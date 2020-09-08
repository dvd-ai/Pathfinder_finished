#ifndef FINDPATH_H
#define FINDPATH_H

//Error handling:

#define ARGC_NUMBER 1
#define ER_FILENAME "usage: ./pathfinder [filename]"
#define ER_FILE "error: file "
#define ER_NO_FILE_END " does not exist"
#define ER_EMPTY_FILE_END " is empty"
#define ER_NaPN "error: line 1 is not valid"
#define ER_LINE_BEG "error: line "
#define ER_LINE_END " is not valid"
#define ER_INV_ISLNDNUM "error: invalid number of islands"
#define ER_DUP_BRDG "error: duplicate bridges"
#define ER_BIG_BRDG_SUM "error: sum of bridges lengths is too big"

/*Checks the whole input and prints the appropriate error
    to the standard error stream
*/
void fp_validation(int argc, const char **argv);
void IsFailed(int fd, char *errorname);
char *file_JoinStrs(const char *s1, const char *s2, const char *s3);
char *val_JoinStrs(const char *s1, char *s2, const char *s3);
void EmptyFile(const char *filename);
void FL_NotPosNum(const char *filename);
void InvalidArgc(int argc);
void NoFile(const char *filename);
void WrLines(const char *filename);
void WrIslandsNum(const char *filename);
void DuplicBridges(const char *filename);
void BigBridgeLenSum(const char *filename);

//------------------------------------------------

char **GetLines(const char *filename, int *LineAmnt);

//Storing data:
/*Stores data after validation, creates and filles 
Matrix, WayMatrix, Islands (for Floyd's algorithm). 
*/
void fp_store_data(char ***Islands, int ***Matrix, const char *filename, int ***WayMatrix);
void IslandArray(char ***Islands, const char *filename);
void FillTheMatrix(int ***Matrix, char **Islands, const char *filename);
void FillTheWayMatrix(int ***WayMatrix, int ***Matrix);
char *Reverse_2_words(char *str, char *delim);
//-------------------------------------------------
//Floyd:

/*Floyd's algorithm */
void fp_floyd(int ***Matrix, int ***WayMatrix);

//Printing output:

#define AMNT_EQUAL_SIGN 40
#define PATH "Path: "
#define ROUTE "Route: "
#define DISTANCE "Distance: "
/*Printing output*/
void fp_print_output(int **Matrix, int **WayMatrix, char **Islands, const char *filename);
#endif
