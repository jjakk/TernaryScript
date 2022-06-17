#include <stdio.h>
#include "./misc/constants.h"
#include "./misc/validArguments.c"
#include "./lexer/lexer.c"

void run(char line_str[LINE_MAX_LENGTH]);

int main(int argumentCount, char *arguments[])  {
   
   if(!validArguments(argumentCount, arguments)) return 1;
   char *fileName = arguments[1];
   
   
   FILE * pFile = fopen(fileName, "r");
   char read_line[LINE_MAX_LENGTH];

   int i = 0;
   while(fgets(read_line, LINE_MAX_LENGTH, pFile)) {
      run(read_line);
   }

   fclose(pFile);

   return 0;
}

void run(char line_str[LINE_MAX_LENGTH]) {
   struct Line line = lexify(line_str);
}