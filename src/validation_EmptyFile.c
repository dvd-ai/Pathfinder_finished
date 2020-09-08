#include "findpath.h"
#include "../inc/libmx.h"

void EmptyFile(const char *filename) {
    int fd = open(filename, O_RDONLY);
    char buffer[1];
    int counter = 0;
    char *str = NULL;

    if (fd != -1) {
        while (read(fd, buffer, 1)) {
                counter++;
        }
        if (counter == 0) {
            str = file_JoinStrs(ER_FILE, filename, ER_EMPTY_FILE_END);
            IsFailed(fd, str);
        }
        close(fd);
    }
}
