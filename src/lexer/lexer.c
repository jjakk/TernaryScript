#include <string.h>
#include "./Line.c"

struct Line lexify(char line_str[LINE_MAX_LENGTH]){
    int i;
    int operationNumber = 0;
    int lineLength = strlen(line_str);
    struct Line line = {"", "", ""};
    for(i = 0; i < lineLength; i++){
        char currentChar = line_str[i];
        if(currentChar == DIVIDING_CHARACTER){
            operationNumber++;
        }
        else{
            char newChar[2] = {currentChar, '\0'};
            switch(operationNumber){
                case 0:
                    strcat(line.firstOperand, newChar);
                    break;
                case 1:
                    strcat(line.secondOperand, newChar);
                    break;
                case 2:
                    strcat(line.thirdOperand, newChar);
                    break;
            }
        }
    }
    return line;
}