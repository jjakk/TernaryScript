int setVariableStatic(Line line);
int setVariableVariable (Line line);

int checkSetVariable(Line line){
    Operation operation = line.operation;
    char *op2 = operation.secondParameter;
    char *op3 = operation.thirdParameter;

    if(strcmp(op2, "SET") == 0){
        if(strcmp(op3, "STATIC") == 0){
            if(setVariableStatic(line)){
                printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.secondParameter, line.number);
                return 1;
            }
            return 0;
        } else if(strcmp(op3, "VARIABLE") == 0){
            int error = setVariableVariable(line);
            if(error == 1){
                printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.secondParameter, line.number);
                return 1;
            } else if(error == 2){
                printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.thirdParameter, line.number);
                return 1;
            } else if(error == 3){
                printf("\nERROR: Variable type collision on Line #%i\n", line.number);
                return 1;
            }
            return 0;
        }
    }

    return 2;
}

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

