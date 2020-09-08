#include "../inc/libmx.h"
#include "findpath.h"

void NoFile(const char *filename) {
    int fd = open(filename, O_RDONLY);
    char *str = NULL;

    if (fd == -1) {
        str = file_JoinStrs(ER_FILE, filename, ER_NO_FILE_END);
        IsFailed(fd, str);
    }
    close(fd);
}
