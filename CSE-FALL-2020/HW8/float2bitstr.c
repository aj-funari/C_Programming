#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]) {

   float value; // floating point number
   int whole_num = 0;
   float dec_num = 0;

   char string[33];
   char final[33];

   int outcome = 0;
   int outcome2 = 0;
   int mask = 1;  // 0000 0001
   int mask2 = 1; // 0000 0001
 
   int move = 6;
   int index = 0;
   int exp = 0;
   int e = 0;
   int i;
   int j = 9;
   int x = 1;

   // CHECK FOR NUMBER OF ARGUMENTS //
   if (argc != 2) {
      printf("No input given\n");
      exit(EXIT_FAILURE);
   }
   
   // SPLIT NUMBER INTO INTEGER PART AND FRACTIONAL PART
   value = atof(argv[1]); // convert string (decimal) to floating point number
   whole_num = (int)value; // whole number portion of floating point number
   dec_num = value - whole_num; // decimal portion of floating point number

   // printf("Whole = %d\n", whole_num);
   // printf("Dec = %lf\n", dec_num); 


   // FINDING SIGN //
   if (argv[1][0] != '-') { // positive number 
      string[0] = '0';
      final[0] = '0';
   }

   else { // negative number
      string[0] = '1';
      final[0] = '1';
   } 
      
   // CONVERT INTEGER PART TO BINARY//
    for (i = 8; i > 0; i--) {
      outcome = whole_num & mask;
      if (outcome == 0) {
         string[i] = '0';
      }
      else {
         string[i] = '1';
      }
      mask = mask << 1;
   }  
   
   
   // CONVERT FRACTIONAL PART TO BINARY //
   for (i = 9; i < 33; i++) {
      dec_num *= 2;
      if (dec_num >= 1) {
         dec_num -= 1;
         string[i] = '1';
      }
      else {
         string[i] = '0';
      }
   }

   // CALCULATE EXPONENT //
   for (i = 1; i < 9; i++) {
      if (string[i] == '1') {
         index = i;
         e = i + move;
         break;
      }
      else {
         move -= 2;
      }
   }
   exp = e + 127; 

   for (i = 8; i > 0; i--) {
      outcome2 = exp & mask2;
      if (outcome2 == 0) {
         final[i] = '0';
      }
      else {
         final[i] = '1';
      }
      mask2 = mask2 << 1;
   }
  
   // FIND MANTISSA //
   for (i = 9; i < 33; i++) {
      if ((index+x) == 9) {
         final[i] = string[j];
         j++;
      }
      else {
         final[i] = string[index+x];
         x++;
      }
   }
   
   string[32] = '\0'; // 32 bits; string[32] is 33rd spot in string 
   printf("%s\n", final);
   exit(EXIT_SUCCESS);  
}
