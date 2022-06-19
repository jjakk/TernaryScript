
void setVariable(Line line){
    char *variableName = line.secondOperand;
    int variableNewType = determineType(line.thirdOperand);
    Variable *variable = getVariable(line.secondOperand);
    variable->type = variableNewType;
    strcpy(variable->value, line.thirdOperand);
}

