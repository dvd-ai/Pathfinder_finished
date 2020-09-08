#include "../inc/libmx.h"
#include "findpath.h"

void fp_store_data(char ***Islands, int ***Matrix, const char *filename, int ***WayMatrix) {
    IslandArray(Islands, filename);
    FillTheMatrix(Matrix, *Islands, filename);
    FillTheWayMatrix(WayMatrix, Matrix);
}
