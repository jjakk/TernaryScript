#include "./operations/print.c"


int parse(struct Line line){
    char *operation = line.firstOperand;
    if(strcmp(operation, "PRINT") == 0){
        printDefault(line);
    } else if(strcmp(operation, "CREATE_VARIABLE") == 0){

    }
    else{
        printf("\nERROR: Unknown operation `%s` on Line #%i\n", operation, line.number);
        return 1;
    }
    return 0;
}
