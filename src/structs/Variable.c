
/*
Variable types by int value
0 - boolean
1 - integer
2 - float
3 - string
*/

typedef struct Variable{
    char *name;
    int type;
    char *value;
    struct Variable *next;
} Variable;

Variable rootVariable = {
    NULL,
    0,
    NULL,
    NULL
};
