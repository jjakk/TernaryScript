
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

void appendVariable(Variable var){
    Variable currentVar = rootVariable;
    while(currentVar.next != NULL){
        currentVar = *currentVar.next;
    }
    currentVar.next = &var;
}

Variable getVariable(char line[LINE_MAX_LENGTH]){
    Variable currentVariable = rootVariable;
    while(currentVariable.next != NULL){
        currentVariable = *currentVariable.next;
        if(strcmp(currentVariable.name, line) == 0) return currentVariable;
    }
    return rootVariable;
}
