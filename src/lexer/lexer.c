
Line lexify(int lineNum, char line_str[LINE_MAX_LENGTH]){
    int i;
    int lineSection = 0;
    int operationNumber = 0;
    int lineLength = strlen(line_str);
    Operation operation = {"", "", ""};
    Line line = {lineNum, operation, "", ""};
    for(i = 0; i < lineLength; i++){
        char currentChar = line_str[i];
        if(currentChar == DIVIDING_CHARACTER){
            lineSection++;
        } else if(currentChar == OPERATION_DIVIDING_CHARACTER){
            operationNumber++;
        } else if(currentChar != '\n'){
            char newChar[2] = {currentChar, '\0'};
            switch(lineSection){
                case 0:
                    switch(operationNumber){
                        case 0:
                            strcat(operation.firstParameter, newChar);
                            break;
                        case 1:
                            strcat(operation.secondParameter, newChar);
                            break;
                        case 2:
                            strcat(operation.thirdParameter, newChar);
                            break;
                    }
                    break;
                case 1:
                    strcat(line.secondParameter, newChar);
                    break;
                case 2:
                    strcat(line.thirdParameter, newChar);
                    break;
            }
        }
        line.operation = operation;
    }
    return line;
}