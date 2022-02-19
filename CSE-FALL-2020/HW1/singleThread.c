#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[])
{
   FILE *fp0, *fp1;
   ssize_t n = 0;
   char *lineptr = NULL;
   int count0 = 0, count1 = 0;
   char *string0, *string1;

   if (argc < 2 | argc > 5)
   {
      printf("Error: incorrect number of arguements\n");
      exit(EXIT_FAILURE);
   }

   fp0 = fopen(argv[1], "r");
   if (fp0 == NULL)
   {
      printf("Error: file is empty\n");
      exit(EXIT_FAILURE);
   }

   while(getline(&lineptr, &n, fp0) != -1)
   {  
      while((string0 = strstr(lineptr, argv[2])) != NULL)
      {      
         if (string0 != NULL)
         {
            count0++;
            *string0 += 1;
         }
      }
   }
   
   fclose(fp0);
   printf("football Count: %d\n", count0);  

   if (argc < 4)
   {
      printf("Only one file seached for sub string\n");
      exit(EXIT_FAILURE);
   }
   
   fp1 = fopen(argv[3], "r");
   if (fp1 == NULL)
   {
      printf("Error: incorrect number of arguments\n");
      exit(EXIT_FAILURE);
   }
   
   while(getline(&lineptr, &n, fp1) != -1)
   {
      while((string1 = strstr(lineptr, argv[4])) != NULL)
      {
         if (string1 != NULL)
         {
            count1++;
            *string1 += 1;
         }
      }
   }

   fclose(fp1);
   printf("username Count: %d\n", count1);       
}
