
Variable retrieveVariable(char line[LINE_MAX_LENGTH]);

int printVariable(Line line){
    char *variableName = line.secondOperand;
    Variable variable = retrieveVariable(variableName);
    if(&variable == &rootVariable) return 1;
    printf("%s\n", variable.name);
    return 0;
}

Variable retrieveVariable(char line[LINE_MAX_LENGTH]){
    Variable currentVariable = rootVariable;
    while(currentVariable.next != NULL){
        currentVariable = *currentVariable.next;
        if(strcmp(currentVariable.name, line) == 0) return currentVariable;
    }
    return rootVariable;
}
