
int printVariable(Line line){
    char *variableName = line.secondOperand;
    Variable variable = getVariable(variableName);
    if(&variable == &rootVariable) return 1;
    printf("%s\n", variable.name);
    return 0;
}
