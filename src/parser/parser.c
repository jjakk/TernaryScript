#include "./operations/createVariable.c"
#include "./operations/setVariable.c"
#include "./operations/inputVariable.c"
#include "./operations/print.c"

int parse(Line line){
    char *operation = line.firstOperand;
    if(operation[0] == '/' && operation[1] == '/'){
        return 0;
    }
    else if(strcmp(operation, "CREATE_VARIABLE") == 0){
        createVariable(line);
    } else if(strcmp(operation, "SET_VARIABLE") == 0){
        if(setVariable(line) == 1){
            printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.secondOperand, line.number);
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
