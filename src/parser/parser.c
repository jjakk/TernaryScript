#include "./operations/createVariable.c"
#include "./operations/setVariable.c"
#include "./operations/addVariable.c"
#include "./operations/inputVariable.c"
#include "./operations/print.c"

int parse(Line line){
    char *operation = line.firstOperand;
    if(operation[0] == '/' && operation[1] == '/'){
        return 0;
    }
    else if(strcmp(operation, "CREATE_VARIABLE") == 0){
        createVariable(line);
    } else if(strcmp(operation, "MODIFY_VARIABLE:SET:STATIC") == 0){
        if(setVariableStatic(line) == 1){
            printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.secondOperand, line.number);
            return 1;
        }
    } else if(strcmp(operation, "MODIFY_VARIABLE:SET:VARIABLE") == 0){
        int error = setVariableVariable(line);
        if(error == 1){
            printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.secondOperand, line.number);
            return 1;
        } else if(error == 2){
            printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.thirdOperand, line.number);
            return 1;
        } else if(error == 3){
            printf("\nERROR: Variable type collision on Line #%i\n", line.number);
            return 1;
        }
    } else if(strcmp(operation, "MODIFY_VARIABLE:ADD:STATIC") == 0){
        int error = addVariableStatic(line);
        if(error == 1){
            printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.secondOperand, line.number);
            return 1;
        } else if(error == 2){
            printf("\nERROR: Invalid value type on Line #%i\n", line.number);
            return 1;
        }
    } else if(strcmp(operation, "MODIFY_VARIABLE:ADD:VARIABLE") == 0){
        int error = addVariableVariable(line);
        if(error == 1){
            printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.secondOperand, line.number);
            return 1;
        } else if(error == 2){
            printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.thirdOperand, line.number);
            return 1;
        } else if(error == 3){
            printf("\nERROR: Invalid value type on Line #%i\n", line.number);
            return 1;
        }
    } else if(strcmp(operation, "INPUT_VARIABLE") == 0){
        if(inputVariable(line) == 1){
            printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.secondOperand, line.number);
            return 1;
        }
    } else if(strcmp(operation, "PRINT") == 0){
        printDefault(line);
    } else if(strcmp(operation, "PRINT_NEW_LINE") == 0){
        printNewLine();
    } else if(strcmp(operation, "PRINT_VARIABLE") == 0){
        if(printVariable(line) == 1){
            printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.secondOperand, line.number);
            return 1;
        }
    } else{
        printf("\nERROR: Unknown operation `%s` on Line #%i\n", operation, line.number);
        return 1;
    }
    return 0;
}
