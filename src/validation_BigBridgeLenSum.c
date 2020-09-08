#include "../inc/libmx.h"
#include "findpath.h"

static int sum(long long a, long long b) {
    if (a > 0 && b > 0 && INT_MAX - b < a) {
        return -1;
    } 
    else return a + b;
}

static void CheckFares(char **StrArr, int ArrLen) {
    long long fare;

    for (int i = 0; i < ArrLen; i++) {
        fare = mx_atoi(StrArr[i]);
        if (fare > INT_MAX) {
            mx_del_strarr(&StrArr);
            mx_print_error(ER_BIG_BRDG_SUM);
        }  
    }
    long long result = mx_atoi(StrArr[0]);

    for (int i = 1; i < ArrLen; i++) {
        result = sum(result, mx_atoi(StrArr[i]));
        if (result == -1) {
            mx_del_strarr(&StrArr);
            mx_print_error(ER_BIG_BRDG_SUM);
        }
    }
}

void BigBridgeLenSum(const char *filename) {
    int LinesAmnt;
    char **Lines = GetLines(filename, &LinesAmnt);
    char **Fare = mx_strarrnew(LinesAmnt);
    char **ComaSepdLine = NULL;
    
    for (int i = 0; i < LinesAmnt; i++) {
        ComaSepdLine = mx_strsplit(Lines[i + 1], ',');
        Fare[i] = mx_strdup(ComaSepdLine[1]);
        mx_del_strarr(&ComaSepdLine);
    }
    mx_del_strarr(&Lines);
    CheckFares(Fare, LinesAmnt);
    mx_del_strarr(&Fare);
}
