#include "findpath.h"
#include "../inc/libmx.h"

static char *DefIslndNum(const char* filename) {
    int fd = open(filename, O_RDONLY);
    char buffer = '\0';
    char *IslndNum = NULL;
    int LenInt = 0;

    if (fd != -1) {
        while(buffer != '\n') {
            read(fd, &buffer, 1);
            LenInt++;
        }
        IslndNum = mx_strnew(LenInt - 1);
        close(fd);
    }
    fd = open(filename, O_RDONLY);
    if (fd != -1) {
        for (int i = 0; i < LenInt - 1; i++)
            read(fd, &IslndNum[i], 1);
        close(fd);
    }
    return IslndNum;
}

static char **SplitIslnds(const char *filename) {
    int LinesAmnt;
    char **Lines = GetLines(filename, &LinesAmnt);
    char **ComSepLine = NULL;
    char **IslPair = NULL;
    char **Islands = mx_strarrnew(2 * LinesAmnt + 1);
    int k = 0;

    for (int i = 0; i < LinesAmnt; i++) {
        ComSepLine = mx_strsplit(Lines[i + 1], ','); 
        IslPair = mx_strsplit(ComSepLine[0], '-');
        mx_del_strarr(&ComSepLine);
        Islands[i + k] = mx_strdup(IslPair[0]);
        Islands[i + k + 1] = mx_strdup(IslPair[1]);
        mx_del_strarr(&IslPair);
        k++;
    }
    mx_del_strarr(&Lines);
    return Islands;
}


static void DelStrsDuplicate(char ***StrArr) {
    int StrArrLen = mx_strarrlen(*StrArr);
    char **Compare = *StrArr;
    bool FirstComp;
    bool flag = true;

    for (int i = 0; i < StrArrLen; i++) {
        FirstComp = true;
        while (flag) {
            if (i < StrArrLen && (*StrArr)[i][0] == '\0') {
                i++;
            }
            else flag = false;
        }
        for (int j = i; j < StrArrLen; j++) {
            if (mx_strcmp((*StrArr)[i], Compare[j]) == 0 && !FirstComp) {
                mx_strdel(&Compare[j]);
                Compare[j] = mx_strnew(0);
            }
            FirstComp = false;
        }
        flag = true;
    }
}

void WrIslandsNum(const char *filename) {
    char *str = DefIslndNum(filename);
    int FirstLine = mx_atoi(str);
    mx_strdel(&str);
    char **IslandsInLines = SplitIslnds(filename);
    int counter = 0;
    
    DelStrsDuplicate(&IslandsInLines);
    for (int i = 0; IslandsInLines[i] != NULL; i++)
        if (IslandsInLines[i][0] != '\0')
            counter++;
    mx_del_strarr(&IslandsInLines);
    if (counter != FirstLine) {
        mx_print_error(ER_INV_ISLNDNUM);
    }
}
