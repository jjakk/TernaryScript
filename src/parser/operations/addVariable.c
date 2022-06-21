
int addVariableStatic(Line line){
    char *variableName = line.secondOperand;
    Variable *pVariable = getVariable(variableName);
    if(pVariable == pRootVariable) return 1;
    
    int variableType = pVariable->type;
    int valueType = determineType(line.thirdOperand);
    if(variableType != valueType) return 2;
    
    if(variableType == 0){
        addBooleans(pVariable, line.thirdOperand);
    } else if(variableType == 1){
        addIntegers(pVariable, line.thirdOperand);
    } else if(variableType == 2){
        addFloats(pVariable, line.thirdOperand);
    } else if(variableType == 3){
        addStrings(pVariable, line.thirdOperand);
    }
    return 0;
}

int addVariableVariable(Line line){
    Variable *pFirstVariable = getVariable(line.secondOperand);
    Variable *pSecondVariable = getVariable(line.thirdOperand);
    if(pFirstVariable == pRootVariable){
        return 1;
    } else if(pSecondVariable == pRootVariable){
        return 2;
    } else if(pFirstVariable->type != pSecondVariable->type){
        return 3;
    }
    
    int variableType = pFirstVariable->type;
    if(variableType == 0){
        addBooleans(pFirstVariable, pSecondVariable->value);
    } else if(variableType == 1){
        addIntegers(pFirstVariable, pSecondVariable->value);
    } else if(variableType == 2){
        addFloats(pFirstVariable, pSecondVariable->value);
    } else if(variableType == 3){
        addStrings(pFirstVariable, pSecondVariable->value);
    }
    return 0;
}