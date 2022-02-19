#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]) {

   int i;
   int sum = 0;
   int weight = 1;
   int a[8];
   int x[8] = {0,0,0,0,0,0,0,1};
   int carry = 0;

   if (argc != 3) {
      printf("ERROR: incorrect command line argument\n");
      exit(EXIT_FAILURE);
   }

   if (strcmp(argv[2], "unsigned") == 0) { // signed number  
   
      for (i = 7; i >= 0; i--) {
         if (argv[1][i] == '1') {
            sum += weight;
            weight *= 2;
         }
         else {
            weight *= 2;
         }
      }
      
      printf("%d\n", sum);
      exit(EXIT_SUCCESS);  
   }

   if (strcmp(argv[2], "signed") == 0) { // signed number
   
      if (argv[1][0] == '0') { // signed positive number
         
         for (i = 7; i > 0; i--) {
            if (argv[1][i] == '1') {
               sum += weight;
               weight *= 2;
            }
            else {
               weight *= 2;
            }
         }
         printf("%d\n", sum);
         exit(EXIT_FAILURE);
      }
   
      else { // signed negative number 
      
         for (i = 7; i >= 0; i--) { // flip bits & store in int array
            if (argv[1][i] == '1') {
               a[i] = 0;
            }
            else {
               a[i] = 1;
            }
         }
   
         for (i = 7; i >= 0; i--) { // add 1 to bits
            a[i] = a[i] + x[i] + carry;
            if (a[i] == 1) { // nothing to carry
               carry = 0;
            }   
            if (a[i] > 1) {
               a[i] = 0;
               carry++;
               if (carry == 2) {
                  carry--;
               }
            }
         }

         for (i = 7; i >= 0; i--) {
            if (a[i] == 1) {
               sum += weight;
               weight *= 2;
            }
            else {
               weight *= 2;
            }
         }
         printf("-%d\n", sum);
         exit(EXIT_SUCCESS);
      }
   }

   else { // not signed or unsigned 
      printf("ERROR: incorrect command line argument\n");
      exit(EXIT_FAILURE);
   }
}
