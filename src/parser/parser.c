#include "./operations/print.c"
#include "./operations/createVariable.c"

int parse(struct Line line){
    char *operation = line.firstOperand;
    if(strcmp(operation, "PRINT") == 0){
        printDefault(line);
    } else if(strcmp(operation, "CREATE_VARIABLE") == 0){
        createVariable(line);
    }
    else{
        printf("\nERROR: Unknown operation `%s` on Line #%i\n", operation, line.number);
        return 1;
    }
    return 0;
}
