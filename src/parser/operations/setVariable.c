
int setVariableStatic(Line line){
    char *variableName = line.secondOperand;
    int variableNewType = determineType(line.thirdOperand);
    Variable *variable = getVariable(line.secondOperand);
    if(variable == pRootVariable) return 1;
    variable->type = variableNewType;
    strcpy(variable->value, line.thirdOperand);
    return 0;
}

int setVariableVariable (Line line){
    char *firstVariableName = line.secondOperand;
    char *secondVariableName = line.thirdOperand;
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

