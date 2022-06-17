
void parse(struct Line line){
    if(strcmp(line.firstOperand, "PRINT") == 0){
        printf("%s", line.secondOperand);
    }
}
