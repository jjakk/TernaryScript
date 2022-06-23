
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
