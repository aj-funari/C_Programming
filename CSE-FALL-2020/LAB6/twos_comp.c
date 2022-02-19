#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
   
   int number; // ex. 00110010  
   int mask  = 128; // 1000 000
   int outcome = 0;
   int i;
   char string[8];

   if (argc != 2) {
      printf("Wrong number of argumnets\n");
      exit(EXIT_FAILURE);
   }
   
   number = atoi(argv[1]);
   
   if (number < -128 || number > 127) {
      printf("outside range\n");
      exit(EXIT_FAILURE);
   }
    
   if (number < 0) { // negative number 
      outcome = ~number + 1;
      for (i = 0; i < 8; i++) {
         outcome = number & mask;
         if (outcome == 0) {
            string[i] = '0';
         }
         else {
            string[i] = '1';
         }
         mask = mask >> 1;
      }
      string[i] = '\0'; 
   }

   else { // positive number
      for (i = 0; i < 8; i++) {
         outcome = number & mask;
         if (outcome == 0) {
            string[i] = '0';
         }
         else {
            string[i] = '1';
         }
         mask = mask >> 1;
      }
      string[i] = '\0';
   }
   
   printf("%s\n", string);
   return(0);
}
