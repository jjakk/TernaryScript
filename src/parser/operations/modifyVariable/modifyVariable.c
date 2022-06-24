#include "./setVariable.c"
#include "./addVariable.c"

int checkModifyVariable(Line line){
    Operation operation = line.operation;
    char *op1 = operation.firstParameter;

    if(strcmp(op1, "MODIFY_VARIABLE") == 0){

        int numberOfPaths = 2;
        int paths[] = {
            checkAddVariable(line),
            checkSetVariable(line)
        };

        for(int i = 0; i < numberOfPaths; i++){
            switch(paths[i]){
                case 0:
                    return 0;
                case 1:
                    return 1;
            }
        }
    }

    return 2;
}