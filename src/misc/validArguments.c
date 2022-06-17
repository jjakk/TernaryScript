
int validArguments(int argumentCount, char *arguments[]){
   if(argumentCount == 2 ) {
      return 1;
   }
   else if(argumentCount > 2 ) {
      printf("More than one file given\n");
   }
   else {
      printf("No file given\n");
   }
   return 0;
}