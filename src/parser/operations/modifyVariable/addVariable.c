
int addVariableStatic(Line line){
    char *variableName = line.secondParameter;
    Variable *pVariable = getVariable(variableName);
    if(pVariable == pRootVariable) return 1;
    
    int variableType = pVariable->type;
    int valueType = determineType(line.thirdParameter);
    if(variableType != valueType) return 2;
    
    if(variableType == 0){
        addBooleans(pVariable, line.thirdParameter);
    } else if(variableType == 1){
        addIntegers(pVariable, line.thirdParameter);
    } else if(variableType == 2){
        addFloats(pVariable, line.thirdParameter);
    } else if(variableType == 3){
        addStrings(pVariable, line.thirdParameter);
    }
    return 0;
}

int addVariableVariable(Line line){
    Variable *pFirstVariable = getVariable(line.secondParameter);
    Variable *pSecondVariable = getVariable(line.thirdParameter);
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