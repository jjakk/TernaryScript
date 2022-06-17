
int determineType(char value[LINE_MAX_LENGTH]);

void createVariable(struct Line line){
    char *variableName = line.secondOperand;
    int variableType = determineType(line.thirdOperand);
}

int determineType(char value[LINE_MAX_LENGTH]){
    if(strcmp(value, "TRUE") == 0 || strcmp(value, "FALSE") == 0){
        return 0;
    // Check int
    // Check float
    else {
        return 3;
    }
}
