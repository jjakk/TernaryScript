
int inputVariable(Line line){
    char *variableName = line.secondOperand;
    Variable *variable = getVariable(variableName);
    if(variable == pRootVariable) return 1;
    char userInput[LINE_MAX_LENGTH];
    fgets(userInput, LINE_MAX_LENGTH, stdin);
    userInput[strcspn(userInput, "\n")] = 0;
    strcpy(variable->value, userInput);
    return 0;
}

