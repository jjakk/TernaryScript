#include "./operations/createVariable.c"
#include "./operations/setVariable.c"
#include "./operations/addVariable.c"
#include "./operations/inputVariable.c"
#include "./operations/print.c"

int parse(Line line){
    Operation operation = line.operation;
    char *op1 = operation.firstParameter;
    char *op2 = operation.secondParameter;
    char *op3 = operation.thirdParameter;
    if(op1[0] == '/' && op1[1] == '/'){
        return 0;
    }
    else if(strcmp(op1, "CREATE_VARIABLE") == 0){
        createVariable(line);
    } else if(strcmp(op1, "MODIFY_VARIABLE") == 0 && strcmp(op2, "SET") == 0 && strcmp(op3, "STATIC") == 0){
        if(setVariableStatic(line) == 1){
            printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.secondParameter, line.number);
            return 1;
        }
    } else if(strcmp(op1, "MODIFY_VARIABLE") == 0 && strcmp(op2, "SET") == 0 && strcmp(op3, "VARIABLE") == 0){
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
    } else if(strcmp(op1, "MODIFY_VARIABLE") == 0 && strcmp(op2, "ADD") == 0 && strcmp(op3, "STATIC") == 0){
        int error = addVariableStatic(line);
        if(error == 1){
            printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.secondParameter, line.number);
            return 1;
        } else if(error == 2){
            printf("\nERROR: Invalid value type on Line #%i\n", line.number);
            return 1;
        }
    } else if(strcmp(op1, "MODIFY_VARIABLE") == 0 && strcmp(op2, "ADD") == 0 && strcmp(op3, "VARIABLE") == 0){
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
    } else if(strcmp(op1, "INPUT_VARIABLE") == 0){
        if(inputVariable(line) == 1){
            printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.secondParameter, line.number);
            return 1;
        }
    } else if(strcmp(op1, "PRINT") == 0 && strcmp(op2, "STATIC") == 0){
        printDefault(line);
    } else if(strcmp(op1, "PRINT") == 0 && strcmp(op2, "NEW_LINE") == 0){
        printNewLine();
    } else if(strcmp(op1, "PRINT") == 0 && strcmp(op2, "VARIABLE") == 0){
        if(printVariable(line) == 1){
            printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.secondParameter, line.number);
            return 1;
        }
    } else{
        printf("\nERROR: Unknown operation `%s` on Line #%i\n", operationToString(line.operation), line.number);
        return 1;
    }
    return 0;
}
