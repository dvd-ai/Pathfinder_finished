#include "findpath.h"
#include "../inc/libmx.h"

static void CheckSubstr(int fd, char *buffer, bool(*FuncToCheck)(char c), char stop, int line) {
    char *str = NULL;

    if (!(*FuncToCheck)(*buffer)) { 
        str = val_JoinStrs(ER_LINE_BEG, mx_itoa(line), ER_LINE_END);
        IsFailed(fd, str);
    }
    while (*buffer != stop) {
        if (!read(fd, buffer, 1) || (!(*FuncToCheck)(*buffer) && *buffer != stop)) {
            str = val_JoinStrs(ER_LINE_BEG, mx_itoa(line), ER_LINE_END);
            IsFailed(fd, str);
        }
    }
}

void WrLines(const char *filename) {
    int fd = open(filename, O_RDONLY);
    char buf = '\0';
    int i = 2;
    bool(*FuncToCheck)(char);
    char *str = NULL;
    
    if (fd != -1) {
        while (buf != '\n') 
            read(fd, &buf, 1);
        while(read(fd, &buf, 1)) {
            FuncToCheck = mx_is_alphabet;
            CheckSubstr(fd, &buf, FuncToCheck, '-', i);
            if (!read(fd, &buf, 1)) {
                str = val_JoinStrs(ER_LINE_BEG, mx_itoa(i), ER_LINE_END);
                IsFailed(fd, str);
            }
            CheckSubstr(fd, &buf, FuncToCheck, ',', i);
            if (!read(fd, &buf, 1)) {
                str = val_JoinStrs(ER_LINE_BEG, mx_itoa(i), ER_LINE_END);
                IsFailed(fd, str);
            }
            FuncToCheck = mx_is_digit;
            CheckSubstr(fd, &buf, FuncToCheck, '\n', i);
            i++;
        }
    }
}
