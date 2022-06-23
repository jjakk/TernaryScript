
int setVariableStatic(Line line){
    char *variableName = line.secondParameter;
    int variableNewType = determineType(line.thirdParameter);
    Variable *variable = getVariable(line.secondParameter);
    if(variable == pRootVariable) return 1;
    variable->type = variableNewType;
    strcpy(variable->value, line.thirdParameter);
    return 0;
}

int setVariableVariable (Line line){
    char *firstVariableName = line.secondParameter;
    char *secondVariableName = line.thirdParameter;
    Variable *firstVariable = getVariable(firstVariableName);
    Variable *secondVariable = getVariable(secondVariableName);
    if(firstVariable == pRootVariable){
        return 1;
    } else if(secondVariable == pRootVariable){
        return 2;
    } else if(firstVariable->type != secondVariable->type){
        return 3;
    } else {
        strcpy(firstVariable->value, secondVariable->value);
        return 0;
    }
}

