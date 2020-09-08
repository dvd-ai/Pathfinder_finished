#include "../inc/libmx.h"
#include "findpath.h"

static void FindDups(char ***StrArr, int size) {
    char *tmp = NULL;

    for (int i = 0; i < size; i++) {
        tmp = (*StrArr)[i];
        for (int j = 0; j < size; j++) {
            if (j != i) {
                if (mx_strcmp(tmp, (*StrArr)[j]) == 0) {
                    mx_del_strarr(StrArr);
                    mx_print_error(ER_DUP_BRDG);
                }
            }
        }
    }
}

void DuplicBridges(const char *filename) {
    int LinesAmnt;
    char **Lines = GetLines(filename, &LinesAmnt); 
    char **Bridges = mx_strarrnew(LinesAmnt);
    char **ComaSepdLine = NULL;

    for (int i = 0; i < LinesAmnt; i++) {
        ComaSepdLine = mx_strsplit(Lines[i + 1], ',');
        Bridges[i] = mx_strdup(ComaSepdLine[0]);
        mx_del_strarr(&ComaSepdLine);
    }
    mx_del_strarr(&Lines);
    FindDups(&Bridges, LinesAmnt);
    mx_del_strarr(&Bridges);    
}
