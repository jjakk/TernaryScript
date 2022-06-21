
/*
Variable types by int value
0 - boolean
1 - integer
2 - float
3 - string
*/

int stringToBoolean(char *value);

typedef struct Variable{
    char *name;
    int type;
    char *value;
    struct Variable *next;
} Variable;

Variable *pRootVariable = NULL;


// Variable value functions

void addIntegers(Variable *variable, char *value){
    int newValue = atoi(variable->value) + atoi(value);
    sprintf(variable->value, "%d", newValue);
}

void addBooleans(Variable *variable, char *value){
    int variableValue = stringToBoolean(variable->value);
    int booleanValue = stringToBoolean(value);
    if(variableValue == 1 || booleanValue == 1){
        strcpy(variable->value, "TRUE");
    } else {
        strcpy(variable->value, "FALSE");
    }
}

void addFloats(Variable *variable, char *value){
    float newValue = atof(variable->value) + atof(value);
    sprintf(variable->value, "%f", newValue);
}

void addStrings(Variable *variable, char *value){
    strcat(variable->value, value);
}

int stringToBoolean(char *value){
    if(strcmp(value, "TRUE") == 0){
        return 1;
    } else {
        return 0;
    }
}

// Variable list functions

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
    
    pCurrentVariable->next->type = variable.type;

    pCurrentVariable->next->name = (char *) malloc(LINE_MAX_LENGTH);
    pCurrentVariable->next->value = (char *) malloc(LINE_MAX_LENGTH);
    strcpy(pCurrentVariable->next->name, variable.name);
    strcpy(pCurrentVariable->next->value, variable.value);
}

Variable *getVariable(char line[LINE_MAX_LENGTH]){
    Variable *pCurrentVariable = pRootVariable;
    while(pCurrentVariable->next != NULL){
        pCurrentVariable = pCurrentVariable->next;
        if(strcmp(pCurrentVariable->name, line) == 0) return pCurrentVariable;
    }
    return pRootVariable;
}
