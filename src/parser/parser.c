#include "./operations/print.c"
#include "./operations/createVariable.c"
#include "./operations/printVariable.c"

int parse(Line line){
    char *operation = line.firstOperand;
    if(operation[0] == '/' && operation[1] == '/'){
        return 0;
    }
    else if(strcmp(operation, "PRINT") == 0){
        printDefault(line);
    } else if(strcmp(operation, "CREATE_VARIABLE") == 0){
        createVariable(line);
    } else if(strcmp(operation, "PRINT_VARIABLE") == 0){
        if(printVariable(line)){
            printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.secondOperand, line.number);
            return 1;
        }
    } else{
        printf("\nERROR: Unknown operation `%s` on Line #%i\n", operation, line.number);
        return 1;
    }
    return 0;
}
