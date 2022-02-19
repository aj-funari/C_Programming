#include "bits.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Return and of x and y
 * Points: 5
 */
int and_op(int x, int y) {
   int i;
   i = (x&y);
   return (i);
}

/* 
 * Return or of x and y
 * Points: 5
 */
int or_op(int x, int y) {
   int i;
   i = (x|y);
   return (i);
}

/*
 * Return xor of x and y
 * Points: 5
 */
int xor_op(int x, int y) {
   int i;
   i = (x^y);
   return (i);
}


/*
 * Extract `b`th byte of x
 * Points: 10
 */
int masking_and(int x, int b) { 
   int var;
   var = ~(0xFF << (b << 3));
   return(x & var);
}

/*
 * Set `b`th byte of x
 * Points: 10
 */
int masking_or(int x, int b) {
   int var;
   var = (0xFF << (b << 3));
   return(x | var);
}

/*
 * Toggle `b`th byte of x
 * Points: 10
 */
int masking_xor(int x, int b) {
   int var;
   var = (0xFF << (b << 3));
   return(x ^ var);
}

/*
 * Shift x to the left by `sc` # of bits
 * Points: 5
 */
int shifting_left_op(int x, int sc) {
   int i;
   i = x << sc;
   return (i);
}

/*
 * Shift x to the right by `sc` # of bits
 * Points: 5
 */
int shifting_right_op(int x, int sc) {
   int i;
   i = x >> sc;
   return (i);
}

/*
 * Return logical not of x
 * Points: 5
 */
int bang(int x) {
   int i;
   i = !x;
   return (i);
}

/*
 * Given an integer x in decimal, convert to binary and set it in `bitstring`
 * Points: 40
 */
void bit_conversion(int x, char* bitstring) {
   int binary[32];
   int j, i = 0;
   while( x > 0) {
      binary[i] = x % 2;
      x /= 2;
      i++;
   }
   bitstring = malloc(sizeof(char)*i+1);
   
   j = i - 1;
   i = 0;

   for(j; j >= 0; j--) {
      bitstring[j] = binary[i] + '0';
      i++; 
   }
   bitstring[i] = '\n';
   printf("%s\n", bitstring);
}
