#include "findpath.h"
#include "../inc/libmx.h"

void IslandArray(char ***Islands, const char *filename) {
    int LineAmnt;
    char **Lines = GetLines(filename, &LineAmnt);
    char **IslandPairs = NULL;
    char **AllIslands = NULL;
    IslandPairs = mx_shorten_strs_delim(Lines, ',', 1, 0);
    mx_del_strarr(&Lines);
    AllIslands = mx_strsplitall(IslandPairs, '-');
    mx_del_strarr(&IslandPairs);
    *Islands = mx_delallstrdups(AllIslands);
    mx_del_strarr(&AllIslands);
}
