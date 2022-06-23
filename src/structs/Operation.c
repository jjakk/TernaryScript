
typedef struct Operation {
    char firstParameter[LINE_MAX_LENGTH];
    char secondParameter[LINE_MAX_LENGTH];
    char thirdParameter[LINE_MAX_LENGTH];
} Operation;

char *operationToString(Operation opeartion){
    char *output;

    char *op1 = opeartion.firstParameter;
    char *op2 = opeartion.secondParameter;
    char *op3 = opeartion.thirdParameter;

    char firstDivider;
    char secondDivider;

    if(strcmp(op1, "") != 0) firstDivider = OPERATION_DIVIDING_CHARACTER;

    if(strcmp(op2, "") != 0) secondDivider = OPERATION_DIVIDING_CHARACTER;

    strcat(output, opeartion.firstParameter);
    sprintf(
        output,
        "%s%c%s%c%s",
        op1,
        firstDivider,
        op2,
        secondDivider,
        op3
    );
    return output;
}
