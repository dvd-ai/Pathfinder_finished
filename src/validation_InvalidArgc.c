#include "findpath.h"
#include "../inc/libmx.h"

void InvalidArgc(int argc) {
    if (argc != 2) {
        mx_print_error(ER_FILENAME);
    }
}
