#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
   FILE *fp;
   ssize_t n = 0;
   char *lineptr = NULL;
   int count = 0;
   char* string;

   if (argc != 3) 
   {
      printf("Error: incorrect number of arguments\n");
      exit(EXIT_FAILURE);
   }

   fp = fopen(argv[1], "r");
   if (fp == NULL)
      exit(EXIT_FAILURE);
   
   while (getline(&lineptr, &n, fp) != -1)
   {
      string = strstr(lineptr, argv[2]);
      if(string != NULL)
         count++;
   }

   printf("%d\n", count);
   fclose(fp);
}
