
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

Variable *pRootVariable = NULL;

void initVariables(){
    pRootVariable = (Variable *) malloc(sizeof(Variable));
}

void closeVariables(){
    Variable *pCurrentVariable = pRootVariable;
    while(pCurrentVariable != NULL){
        Variable *pNextVariable = pCurrentVariable->next;
        printf("Freeing |%s:%s| at %p\n", pCurrentVariable->name, pCurrentVariable->value, pCurrentVariable);
        free(pCurrentVariable);
        pCurrentVariable = pNextVariable;
    }
}

void appendVariable(Variable variable){
    Variable *pCurrentVariable = pRootVariable;
    while(pCurrentVariable->next != NULL){
        pCurrentVariable = pCurrentVariable->next;
    }
    pCurrentVariable->next = (Variable *) malloc(sizeof(Variable));
    *pCurrentVariable->next = variable;
}

Variable *getVariable(char line[LINE_MAX_LENGTH]){
    Variable *pCurrentVariable = pRootVariable;
    while(pCurrentVariable->next != NULL){
        pCurrentVariable = pCurrentVariable->next;
        if(strcmp(pCurrentVariable->name, line) == 0) return pCurrentVariable;
    }
    return pRootVariable;
}
