
void printDefault(Line line){
    printf("%s", line.secondOperand);
}

void printNewLine(){
    printf("\n");
}

int printVariable(Line line){
    char *variableName = line.secondOperand;
    Variable *variable = getVariable(variableName);
    if(variable == pRootVariable) return 1;
    printf("%s", variable->value);
    return 0;
}
