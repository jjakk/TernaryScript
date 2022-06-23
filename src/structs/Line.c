#include "Operation.c"

typedef struct Line{
    int number;
    Operation operation;
    char secondParameter[LINE_MAX_LENGTH];
    char thirdParameter[LINE_MAX_LENGTH];
} Line;

