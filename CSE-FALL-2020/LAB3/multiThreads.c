#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct input_args {
   char* file;
   char* word;
};

typedef struct input_args IA;

void *count(void* arg) {
   
   double time_spent = 0.0;
   clock_t begin = clock();

   IA* args = (IA*) arg;
   FILE *fp;
   ssize_t n = 0;
   char *lineptr = NULL;
   int count = 0;
   char *string;
   char *argument;
   int x;

   fp = fopen(args->file, "r");
   if (fp == NULL) {
      printf("Error: no file\n");
      exit(EXIT_FAILURE);
   }

   argument = args->word;
   while(getline(&lineptr, &n, fp) != -1) {
      while((string = strstr(lineptr, argument)) != NULL) {
         if (string != NULL) {
            count++;
            *string += 1;
         }
      }
   }
   printf("football count: %d\n", count);
   fclose(fp);
   
   clock_t end = clock();
   time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
   printf("Time = %f\n", time_spent);
}

int main (int argc, char* argv[]) {

   double time_spent = 0.0;
   clock_t begin = clock();

   pthread_t tid0, tid1;
   IA thread0 = {}; // gives access to struct
   IA thread1 = {};
   thread0.file = argv[1];
   thread0.word = argv[2];
   thread1.file = argv[3];
   thread1.word = argv[4];
   
   if (argc != 5) {
      printf("Error: not enough arguments\n");
      exit(EXIT_FAILURE);
   } 

   pthread_create(&tid0, NULL, count, (void*)&thread0);
   pthread_create(&tid1, NULL, count, (void*)&thread1);
   pthread_join(tid0, NULL);
   pthread_join(tid1, NULL);
   
   clock_t end = clock();
   time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
   printf("Main Executing = %f\n", time_spent);

   return(0);
} 
