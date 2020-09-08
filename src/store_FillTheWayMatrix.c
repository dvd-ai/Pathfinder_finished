#include "../inc/libmx.h"
#include "findpath.h"

void FillTheWayMatrix(int ***WayMatrix, int ***Matrix) {
    int Len = 0;

    for (int i = 0; (*Matrix)[i] != NULL; i++, Len++);
    *WayMatrix = mx_intarrnew(Len);
    for (int i = 0; i < Len; i++) 
        (*WayMatrix)[i] = mx_intnew(Len);
    for (int i = 0; (*WayMatrix)[i] != NULL; i++) {
        for (int j = 0; (*WayMatrix)[j] != NULL; j++) {
            if ((*Matrix)[i][j] == 2147483647) {
                (*WayMatrix)[i][j] = 2147483647;
            }
            else {
                (*WayMatrix)[i][j] = j;
            }
        }
    }
}
