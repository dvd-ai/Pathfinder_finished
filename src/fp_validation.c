#include "findpath.h"
#include "../inc/libmx.h"

void IsFailed(int fd, char *errorname) {
    if (fd != -1)
        close(fd);
    write(2, errorname, mx_strlen(errorname));
    write(2, "\n", 1);
    free(errorname);
    exit(1);
}

char *file_JoinStrs(const char *s1, const char *s2, const char *s3) {
    char *Join1 = mx_strjoin(s1 , s2);
    char *Join2 = mx_strjoin(Join1, s3);
    mx_strdel(&Join1);
    return Join2;
}

char *val_JoinStrs(const char *s1, char *s2, const char *s3) {
    char *Join1 = mx_strjoin(s1 , s2);
    mx_strdel(&s2);
    char *Join2 = mx_strjoin(Join1, s3);
    mx_strdel(&Join1);
    return Join2;
}

char **GetLines(const char *filename, int *LineAmnt) {
    char *FileData = mx_file_to_str(filename);
    *LineAmnt = mx_count_words(FileData, '\n') - 1;
    char **Lines = mx_strsplit(FileData, '\n');
    mx_strdel(&FileData);
    return Lines;
}

void fp_validation(int argc, const char **argv) {
    InvalidArgc(argc);
    NoFile(argv[ARGC_NUMBER]);
    EmptyFile(argv[ARGC_NUMBER]);
    FL_NotPosNum(argv[ARGC_NUMBER]);
    WrLines(argv[ARGC_NUMBER]);
    WrIslandsNum(argv[ARGC_NUMBER]);
    DuplicBridges(argv[ARGC_NUMBER]);
    BigBridgeLenSum(argv[ARGC_NUMBER]);
}
