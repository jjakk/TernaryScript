int addVariableStatic(Line line);
int addVariableVariable(Line line);

int checkAddVariable(Line line){
    Operation operation = line.operation;
    char *op2 = operation.secondParameter;
    char *op3 = operation.thirdParameter;

    if(strcmp(op2, "ADD") == 0){
        if(strcmp(op3, "STATIC") == 0){
            int error = addVariableStatic(line);
            if(error == 1){
                printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.secondParameter, line.number);
                return 1;
            } else if(error == 2){
                printf("\nERROR: Invalid value type on Line #%i\n", line.number);
                return 1;
            }
            return 0;
        } else if(strcmp(op3, "VARIABLE") == 0){
            int error = addVariableVariable(line);
            if(error == 1){
                printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.secondParameter, line.number);
                return 1;
            } else if(error == 2){
                printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.thirdParameter, line.number);
                return 1;
            } else if(error == 3){
                printf("\nERROR: Invalid value type on Line #%i\n", line.number);
                return 1;
            }
            return 0;
        }
    }

    return 2;
}

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