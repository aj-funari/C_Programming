#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char* argv[]) {

   char *str;

   str = malloc(sizeof(char)*(strlen(argv[1]) + 6));
   strcpy(str, "/bin/");
   strcat(str, argv[1]);

   if(execl(str, argv[1], argv[2], NULL) == -1) {
      exit(EXIT_FAILURE);
   }
  
   exit(EXIT_SUCCESS);
}
