int inputVariable(Line line);

int checkInputVariable(Line line){
    if(strcmp(line.operation.firstParameter, "INPUT_VARIABLE") == 0){
        if(inputVariable(line) == 1){
            printf("\nERROR: Invalid variable `%s` on Line #%i\n", line.secondParameter, line.number);
            return 1;
        }
        return 0;
    }

    return 2;
}

int inputVariable(Line line){
    char *variableName = line.secondParameter;
    Variable *variable = getVariable(variableName);
    if(variable == pRootVariable) return 1;
    char userInput[LINE_MAX_LENGTH];
    fgets(userInput, LINE_MAX_LENGTH, stdin);
    userInput[strcspn(userInput, "\n")] = 0;
    strcpy(variable->value, userInput);
    return 0;
}

