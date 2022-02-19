/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Points: 5
 */
int bitAnd(int x, int y) {
   int i;
   i = ~(~x | ~y);
   return(i);
}

/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Points: 10
 */
int getByte(int x, int n) {
   x = (x >> (n << 3)) & 0xff;
   return(x);
}

/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Points: 10
 */
int byteSwap(int x, int n, int m) {
   int a = 0;
   n = n << 3;
   m = m << 3;
   a = 0xff & ((x >> n) ^ (x >> m));
   x = x ^ (a << n);
   x = x ^ (a << m);
   return(x);
}


/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Points: 15
 */
int logicalShift(int x, int n) {
   x = (x >> n) & (~(((1 << 31) >> n) << 1));
   return(x);
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Points: 20
 */
int bitCount(int x) {
   int a = 0;
   a += x & 0x1;
   a += (x >> 1) & 0x1;
   a += (x >> 2) & 0x1;
   a += (x >> 3) & 0x1;
   a += (x >> 4) & 0x1;
   a += (x >> 5) & 0x1;
   a += (x >> 6) & 0x1;
   a += (x >> 7) & 0x1;
   a += (x >> 8) & 0x1;
   a += (x >> 9) & 0x1;
   a += (x >> 10) & 0x1;
   a += (x >> 11) & 0x1;
   a += (x >> 12) & 0x1;
   a += (x >> 13) & 0x1;
   a += (x >> 14) & 0x1;
   a += (x >> 15) & 0x1;
   a += (x >> 16) & 0x1;
   a += (x >> 17) & 0x1;
   a += (x >> 18) & 0x1;
   a += (x >> 19) & 0x1;
   a += (x >> 20) & 0x1;
   a += (x >> 21) & 0x1;
   a += (x >> 22) & 0x1;
   a += (x >> 23) & 0x1;
   a += (x >> 24) & 0x1;
   a += (x >> 25) & 0x1;
   a += (x >> 26) & 0x1;
   a += (x >> 27) & 0x1;
   a += (x >> 28) & 0x1;
   a += (x >> 29) & 0x1;
   a += (x >> 30) & 0x1;
   a += (x >> 31) & 0x1;
   return(a);
}

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Points: 20
 */
int bang(int x) {
   x = (((~x + 1) | x) >> 31) + 1;
   return(x);
}

/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Points: 20
 */
int bitParity(int x) {
   x ^= x >> 16;
   x ^= x >> 8;
   x ^= x >> 4;
   x ^= x >> 2;
   x ^= x >> 1;
   x &= 1;
   return(x);
}
