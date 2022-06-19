
int setVariable(Line line){
    char *variableName = line.secondOperand;
    int variableNewType = determineType(line.thirdOperand);
    Variable *variable = getVariable(line.secondOperand);
    if(variable == pRootVariable) return 1;
    variable->type = variableNewType;
    strcpy(variable->value, line.thirdOperand);
    return 0;
}

