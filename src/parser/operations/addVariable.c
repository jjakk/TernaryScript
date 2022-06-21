
int addVariableStatic(Line line){
    char *variableName = line.secondOperand;
    Variable *variable = getVariable(variableName);
    if(variable == pRootVariable) return 1;
    
    int variableType = variable->type;
    int valueType = determineType(line.thirdOperand);
    if(variableType != valueType) return 2;
    
    if(variableType == 0){
        addBooleans(variable, line.thirdOperand);
    } else if(variableType == 1){
        addIntegers(variable, line.thirdOperand);
    } else if(variableType == 2){
        addFloats(variable, line.thirdOperand);
    } else if(variableType == 3){
        addStrings(variable, line.thirdOperand);
    }
    return 0;
}