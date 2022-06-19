
/*
Variable types by int value
0 - boolean
1 - integer
2 - float
3 - string
*/

void printVariables();

typedef struct Variable{
    char *name;
    int type;
    char *value;
    struct Variable *next;
} Variable;

Variable *pRootVariable = NULL;

void initVariables(){
    pRootVariable = (Variable *) malloc(sizeof(Variable));
    pRootVariable->name = NULL;
    pRootVariable->type = 0;
    pRootVariable->value = NULL;
    pRootVariable->next = NULL;
}

void closeVariables(){
    Variable *pCurrentVariable = pRootVariable;
    while(pCurrentVariable != NULL){
        Variable *pNextVariable = pCurrentVariable->next;
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
    printf("________\n");
    printVariables();
}

Variable *getVariable(char line[LINE_MAX_LENGTH]){
    Variable *pCurrentVariable = pRootVariable;
    while(pCurrentVariable->next != NULL){
        pCurrentVariable = pCurrentVariable->next;
        if(strcmp(pCurrentVariable->name, line) == 0) return pCurrentVariable;
    }
    return pRootVariable;
}

void printVariables(){
    Variable *pCurrentVariable = pRootVariable;
    while(pCurrentVariable->next != NULL){
        pCurrentVariable = pCurrentVariable->next;
        printf("%s\n", pCurrentVariable->name);
    }
}
