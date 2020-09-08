#include "findpath.h"
#include "../inc/libmx.h"

static void print_path_str(char *from, char *where) {
    mx_printstr(PATH);
    mx_printstr(from);
    mx_printstr(" -> ");
    mx_printstr(where);
    mx_printchar('\n');
}

static void print_route_str(int from, int where, char **Islands, int **WayMatrix) {
    mx_printstr(ROUTE);
    mx_printstr(Islands[from]);
    mx_printstr(" -> ");

    while (from != where) {
        from = WayMatrix[from][where];
        mx_printstr(Islands[from]);
        if (from != where)
            mx_printstr(" -> ");
        else mx_printchar('\n');
    }
}
//------------------------DISTANCE-----------------------------------------------------
static int GetIslandIndex(int from, int where, char **Islands, char **Lines) {
    char **shortlines = mx_copy_strarrchar(Lines, ',');
    char *HalfString = NULL;
    char *FullString = NULL;
    char *RevFullString = NULL;
    int Search;
    
    HalfString = mx_strjoin(Islands[from], "-");
    FullString = mx_strjoin(HalfString, Islands[where]);
    mx_strdel(&HalfString);
    Search = mx_getindex_foundstr(FullString, shortlines, 1);
    if (Search < 0) {
        RevFullString = Reverse_2_words(FullString, "-");
        Search = mx_getindex_foundstr(RevFullString, shortlines, 1);
    }
    mx_strdel(&FullString);
    mx_strdel(&RevFullString);
    mx_del_strarr(&shortlines);
    return Search;
}

static void print_num(int from, int where, char **Islands, char **Lines) {    
    int foundstr = GetIslandIndex(from, where, Islands, Lines);
    char *StrNum = mx_strget_numberstr(Lines[foundstr]);
    mx_printstr(StrNum);
    mx_strdel(&StrNum);
}

static void print_distance_str(int from, int where, int **Matrix, int **WayMatrix,
                                char **Islands, const char *filename) {
    int amnt;
    char **Lines = GetLines(filename, &amnt);
    mx_printstr(DISTANCE);
    int value = Matrix[from][where];
    if (WayMatrix[from][where] == where) {
        mx_printint(Matrix[from][where]);
        mx_printchar('\n');
    }
    else {
        print_num(from, WayMatrix[from][where], Islands, Lines);
        while (from != where) {
            if (WayMatrix[from][where] != where)
                mx_printstr(" + ");
            from = WayMatrix[from][where];
            if (from != where) 
                print_num(from, WayMatrix[from][where], Islands, Lines);
        }
        mx_printstr(" = ");
        mx_printint(value);
        mx_printchar('\n');
    }
    mx_del_strarr(&Lines);
}
//-------------------------------------------------------------------------------------------
void fp_print_output(int **Matrix, int **WayMatrix, char **Islands, const char *filename) {
    for (int i = 0; Islands[i] != NULL; i++) {
        for (int j = i; Islands[j] != NULL; j++) {
            if (j != i) {
                mx_print_chars('=', AMNT_EQUAL_SIGN);
                mx_printchar('\n');
                print_path_str(Islands[i], Islands[j]);
                print_route_str(i, j, Islands, WayMatrix);
                print_distance_str(i, j, Matrix, WayMatrix, Islands, filename);
                mx_print_chars('=', AMNT_EQUAL_SIGN);
                mx_printchar('\n');
            }
        }
    }
}
