#include <stdio.h>
#include "./misc/constants.h"
#include "./misc/validArguments.c"
#include "./lexer/lexer.c"
#include "./parser/parser.c"

int run(int lineNum, char line_str[LINE_MAX_LENGTH]);

int main(int argumentCount, char *arguments[])  {
   
   if(!validArguments(argumentCount, arguments)) return 1;
   char *fileName = arguments[1];
   
   
   FILE * pFile = fopen(fileName, "r");
   char read_line[LINE_MAX_LENGTH];

   int lineNumber = 1;
   while(fgets(read_line, LINE_MAX_LENGTH, pFile)) {
      if(run(lineNumber, read_line) == 1) return 1;
      lineNumber++;
   }

   fclose(pFile);

   return 0;
}

int run(int lineNum, char line_str[LINE_MAX_LENGTH]) {
   struct Line line = lexify(lineNum, line_str);
   return parse(line);
}