
int determineType(char value[LINE_MAX_LENGTH]);
int isBoolean(char value[LINE_MAX_LENGTH]);
int isInt(char value[LINE_MAX_LENGTH]);
int isFloat(char value[LINE_MAX_LENGTH]);
int isDigit(char character);

void createVariable(Line line){
    char *variableName = line.secondOperand;
    int variableType = determineType(line.thirdOperand);
    Variable newVariable = {
        variableName,
        variableType,
        line.thirdOperand,
        NULL
    };
    appendVariable(newVariable);
}

int determineType(char value[LINE_MAX_LENGTH]){
    if(isBoolean(value) == 1) return 0;
    else if(isInt(value) == 1) return 1;
    else if(isFloat(value) == 1) return 2;
    else return 3;
}

int isBoolean(char value[LINE_MAX_LENGTH]){
    return strcmp(value, "TRUE") == 0 || strcmp(value, "FALSE") == 0;
}

int isInt(char value[LINE_MAX_LENGTH]){
    int i;
    for(i = 0; i < strlen(value); i++){
        char currentChar = value[i];
        if(currentChar == '-' || currentChar == '+'){
            if(i != 0) return 0;
        } else if(isDigit(currentChar) == 0) {
            return 0;
        }
    }
    return 1;
}

int isFloat(char value[LINE_MAX_LENGTH]){
    int foundPeriod = 0;
    int i;
    for(i = 0; i < strlen(value); i++){
        char currentChar = value[i];
        if(currentChar == '.'){
            if(foundPeriod == 1) return 1;
            else foundPeriod = 1;
        } else if(currentChar == '-' || currentChar == '+'){
            if(i != 0) return 0;
        } else if(isDigit(currentChar) == 0) {
            return 0;
        }
    }
    return 1;
}

int isDigit(char character){
    int isDigit = 0;
    int j;
    for(j = 0; j < 10; j++){
        if(character == DIGITS[j]){
            isDigit = 1;
        }
    }
    return isDigit;
}
