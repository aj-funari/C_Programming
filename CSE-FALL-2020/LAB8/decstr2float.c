#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main (int argc, char* argv[]) {
   
   char* string;
   int sign;
   int exp = 0;
   int weight_exp = 1;
   float man = 0;
   float weight_man = 0.5;
   int i;
   int E;
   float num;

   string = malloc(sizeof(char)*(strlen(argv[1] + 1)));
   string = argv[1];

   // CHECK FOR CORRECT NUMBER OF INPUTS //
   if (argc != 2) {
      printf("ERROR: wrong number of arguments\n");
      exit(EXIT_FAILURE);
   }

   // CHECK FOR INVALID ARGUMENT //
   for (i = 0; i < 32; i++) {
      if (string[i] == '0' || string[i] == '1');
      else {
         printf("Incorrect input argument\n");
         exit(EXIT_FAILURE);
      }
   } 
   
   // FINDING SIGN //   
   if (string[0] == '0') { // positive number
      sign = 0;
      printf("Sign: %d\n", sign);
   }
   
   else { // negative number
      sign = 1;
      printf("Sign: %d\n", sign);
   }

   // FINDING EXPONENT //
   for (i = 8; i >= 1; i--) {
      if (string[i] == '1') {
         exp += weight_exp;
         weight_exp *= 2;
      }
      else { 
         weight_exp *= 2;
      }
   }  
   printf("Exponent: %d\n", exp);

   // FINDING MANTISSA // 
   for (i = 9; i < 32; i++) {
      if (string[i] == '1') {
         man += weight_man;
         weight_man /= 2;
      }
      else {
         weight_man /= 2;
      }
   }

   if (exp != 0) {
      man += 1;
   }

   printf("Mantissa: %.17g\n", man);
      
   // FINDING NUMBER // 
   if (exp != 0 && exp != 255) { //normalized
      E = exp - 127;
      num = pow(-1,string[0]) * man * pow(2,E);
   }

   else { //demormalized
      E = 1 - 127;
      num = pow(-1,string[0]) * man * pow(2,E);
   }
   printf("Number: %.7g\n", num);

   exit(EXIT_SUCCESS);
}
