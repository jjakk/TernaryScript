#include "./setVariable.c"
#include "./addVariable.c"

int checkModifyVariable(Line line){
    Operation operation = line.operation;
    char *op1 = operation.firstParameter;
    char *op2 = operation.secondParameter;
    char *op3 = operation.thirdParameter;

    if(strcmp(op1, "MODIFY_VARIABLE") == 0){
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
        } else if(strcmp(op2, "ADD") == 0){
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
    }

    return 2;
}