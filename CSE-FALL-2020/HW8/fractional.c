#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
   
   int i;   
   char string[24];
   float num;

   num = atof(argv[1]);
   for (i = 0; i < 23; i++) {
      num *= 2;
      if (num >= 1) {
         num -= 1;
         string[i] = '1';
      }
      else {
         string[i] = '0';
      }
   }

   string[23] = '\0';
   printf("%s\n", string);
   exit(EXIT_SUCCESS);
}
