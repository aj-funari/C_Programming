#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
   int pid;
   int new;

   new = atoi(argv[1]);

   if (argc < 2)
   {
      printf("Error: wrong number of argements\n");
      exit(EXIT_FAILURE);
   }

   pid = fork();
   printf("Hello World\n");

   if (pid == 0) { //child //
      printf("Child: %d\n", --new);
   }

   else // parent //
      printf("Parent: %d\n", ++new);
}
