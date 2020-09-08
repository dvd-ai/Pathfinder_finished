#include "findpath.h"
#include "../inc/libmx.h"

void FL_NotPosNum(const char *filename) {
    int fd = open(filename, O_RDONLY);
    char buffer[1];
    bool FindNewLine = false;
    bool FindNum = true;
    bool exit = false;

    if (fd != -1) {
        while (!exit && read(fd, buffer, 1)) {
            if (FindNewLine && buffer[0] == '\n') 
                exit = true;
            else if (!mx_is_digit(buffer[0])) { 
                close(fd);
                mx_print_error(ER_NaPN);
            }
            else if (FindNum && mx_is_digit(buffer[0])) {
                FindNewLine = true;
                FindNum = false;
            }
        }
        if (!exit) {
            close(fd);
            mx_print_error(ER_NaPN);
        }
        close(fd);
    }
}
