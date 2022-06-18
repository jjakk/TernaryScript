#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./misc/constants.h"
#include "./misc/validArguments.c"
#include "./structs/Line.c"
#include "./structs/Variable.c"
#include "./lexer/lexer.c"
#include "./parser/parser.c"

int run(int lineNum, char line_str[LINE_MAX_LENGTH]);

int main(int argumentCount, char *arguments[]){
   initVariables();
      
   if(!validArguments(argumentCount, arguments)) return 1;
   char *fileName = arguments[1];
   
   
   FILE *pFile = fopen(fileName, "r");
   if(pFile == NULL){
      printf("ERROR: File `%s` not found\n", fileName);
      return 1;
   }

   char read_line[LINE_MAX_LENGTH];

   int lineNumber = 1;
   while(fgets(read_line, LINE_MAX_LENGTH, pFile)) {
      if(strlen(read_line) > 1){
         if(run(lineNumber, read_line) == 1) return 1;
      }
      lineNumber++;
   }

   fclose(pFile);
   closeVariables();

   return 0;
}

int run(int lineNum, char line_str[LINE_MAX_LENGTH]) {
   Line line = lexify(lineNum, line_str);
   return parse(line);
}