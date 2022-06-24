void printDefault(Line line);
void printNewLine();
int printVariable(Line line);

int checkPrint(Line line){
    Operation operation = line.operation;
    char *op1 = operation.firstParameter;
    char *op2 = operation.secondParameter;
    char *op3 = operation.thirdParameter;

    if(strcmp(op1, "PRINT") == 0){
        if(strcmp(op2, "STATIC") == 0){
            printDefault(line);
            return 0;
        } else if(strcmp(op2, "NEW_LINE") == 0){
            printNewLine();
            return 0;
        } else if(strcmp(op2, "VARIABLE") == 0) {
            if(printVariable(line) == 1){
                printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.secondParameter, line.number);
                return 1;
            }
            return 0;
        }
    }

    return 2;
}

void printDefault(Line line){
    printf("%s", line.secondParameter);
}

void printNewLine(){
    printf("\n");
}

int printVariable(Line line){
    char *variableName = line.secondParameter;
    Variable *variable = getVariable(variableName);
    if(variable == pRootVariable) return 1;
    printf("%s", variable->value);
    return 0;
}
