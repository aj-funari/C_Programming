#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char lower_case (void) {

   int num;
   char letter;

   num = rand() % 26; // 26 letters in alphabet 
   num += 97; // lower case letter 97-122
   letter = num;

   printf("%c\n", letter);   
   return(0);
}

char upper_case (void) {
   
   int num0;
   char letter0;

   num0 = rand() % 26;
   num0 += 65; // upper case letter 65-90
   letter0 = num0;

   printf("%c\n", letter0);
   return(0);  
}

int main (int argc, char* argv[]) {

   int i;
   
   srand(time(0));
  
   if (argc != 2) {
      printf("Not enough/too many argumnets\n");
      exit(EXIT_FAILURE);
   }
   
   if (argv[1][0] == '-') { // argument is a flag
      
      if (argv[1][1] == 'l') { // l flag is passed 
         for (i = 0; i < 10; i++)
            lower_case();
      }

      if (argv[1][1] == 'u') { // u flag is passed
         
         for (i = 0; i < 10; i++)
            upper_case();
      }
   }
   
   else {
      printf("not a flag\n");
      exit(EXIT_FAILURE);
   }
   
   return(0);
}
