#include "../inc/libmx.h"
#include "findpath.h"



static int WhatToFind(char *Island1, char *Island2, char **shortlines) {
    char *StrToFind = NULL;
    char *HalfString = NULL;
    int result;

    HalfString = mx_strjoin(Island1, "-");
    StrToFind = mx_strjoin(HalfString, Island2);
    mx_strdel(&HalfString);
    result = mx_getindex_foundstr(StrToFind, shortlines, 1);
    mx_strdel(&StrToFind);
    return result;
    
}

static void Filling(char **Islands, char **Lines, char **shortlines, int ***Matrix) {
    int SearchResult;

    for (int i = 0; Islands[i] != NULL; i++) {
        for (int j = 0; Islands[j] != NULL; j++) {
            SearchResult = WhatToFind(Islands[i], Islands[j], shortlines);
            if (SearchResult >= 0) { 
                (*Matrix)[i][j] = mx_strget_longlongnum(Lines[SearchResult]);
                (*Matrix)[j][i] = (*Matrix)[i][j];
            }   
            else  {
                SearchResult = WhatToFind(Islands[j], Islands[i], shortlines);
                if (SearchResult < 0) {
                    (*Matrix)[i][j] = 2147483647;
                    (*Matrix)[j][i] = (*Matrix)[i][j];
                }
                else {
                    (*Matrix)[i][j] = mx_strget_longlongnum(Lines[SearchResult]);
                    (*Matrix)[j][i] = (*Matrix)[i][j];
                }
            }
        }
    }
}  

void FillTheMatrix(int ***Matrix, char **Islands, const char *filename) {
    int LineAmnt;
    char **Lines = GetLines(filename, &LineAmnt);
    char **shortlines = mx_copy_strarrchar(Lines, ',');
    
    int IslandAmnt = mx_strarrlen(Islands);
    *Matrix = mx_intarrnew(IslandAmnt);
    for (int i = 0; i < IslandAmnt; i++) {
        (*Matrix)[i] = mx_intnew(IslandAmnt);
    }
    Filling(Islands, Lines, shortlines, Matrix);
    mx_del_strarr(&Lines);
    mx_del_strarr(&shortlines);
}
