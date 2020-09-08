#include "findpath.h"
#include "../inc/libmx.h"

char *Reverse_2_words(char *str, char *delim) {
    int NewStrLen = mx_strlen(str);
    char *NewStr = mx_strnew(NewStrLen);
    char *start = mx_strstr(str, delim);
    int index = 0;

    for (int i = 1; start[i] != '\0'; i++) {
        NewStr[index] = start[i];
        index++;
    }
    NewStr[index] = delim[0];
    index++;
    for (int i = 0; str[i] != delim[0]; i++) {
        NewStr[index] = str[i];
        index++;
    }
    return NewStr;
}
