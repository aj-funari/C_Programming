#include <stdio.h>

int main (int argc, char* argv[]) {

   int num = atoi(argv[1]);
   char string[9];
   int mask = 1; // 0000 0001
   int outcome;
   int i;

   printf("%d\n", num);
   for (i = 7; i > -1; i--) {
      outcome = num & mask;
      if (outcome == 0) {
         string[i] = '0';
      }
      else {
         string[i] = '1';
      }
      mask = mask << 1;
   } 
   string[8] = '\0';
   printf("%s\n", string);
   return(0);            
}
