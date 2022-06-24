#include "./operations/createVariable.c"
#include "./operations/modifyVariable/modifyVariable.c"
#include "./operations/inputVariable.c"
#include "./operations/print.c"

int parse(Line line){
    Operation operation = line.operation;
    char *op1 = operation.firstParameter;
    char *op2 = operation.secondParameter;
    char *op3 = operation.thirdParameter;

    if(op1[0] == '/' && op1[1] == '/'){
        return 0;
    }

    int numberOfPaths = 4;
    int paths[] = {
        checkCreateVariable(line),
        checkModifyVariable(line),
        checkInputVariable(line),
        checkPrint(line)
    };

    for(int i = 0; i < numberOfPaths; i++){
        switch(paths[i]){
            case 0:
                return 0;
            case 1:
                return 1;
        }
    }

    printf("\nERROR: Unknown operation `%s:%s:%s` on Line #%i\n", op1, op2, op3, line.number);
    return 1;
}
