#include "findpath.h"
#include "../inc/libmx.h"

void Add(long long *sum, int first, int second) {
    long long dodanok1 = first;
    long long dodanok2 = second;
    *sum = dodanok1 + dodanok2;
}

void fp_floyd(int ***Matrix, int ***WayMatrix) {
    long long sum;
    long long element;

    for (int k = 0; (*Matrix)[k] != NULL; k++) {
        for (int i = 0; (*Matrix)[i] != NULL; i++) {
            if ((*Matrix)[k][i] != 2147483647) {
                for (int j = 0; (*Matrix)[j] != NULL; j++) {
                    Add(&sum, (*Matrix)[k][i], (*Matrix)[i][j]);
                    element = (*Matrix)[k][j];
                    if (element > sum) {
                        (*Matrix)[k][j] = (*Matrix)[k][i] + (*Matrix)[i][j];
                        (*WayMatrix)[k][j] = (*WayMatrix)[k][i];
                    }
                }
            }
        }
    }
}
