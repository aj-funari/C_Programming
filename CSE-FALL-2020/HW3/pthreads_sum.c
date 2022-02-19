#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#ifndef NTHREADS
   #define NTHREADS 2
#endif
#ifndef ASIZE
   #define ASIZE 50
#endif

int array[ASIZE];
int array_sum[NTHREADS];
 
void *sum(void* arg) {
   int *thread = (int*) arg;
   int read_length = ASIZE/NTHREADS;
   int start = *thread * read_length;
   int sum = 0;
   int i;
   
   for (i = start; i < start + read_length; i++) {
      sum += array[i];
   }
   printf("the sum = %d at thread# = %d\n",sum, *thread);
   array_sum[*thread] = sum;
   return(NULL);
}

int main (int argc, char* argv[]) {
   
   int i = 0;
   pthread_t tid[NTHREADS];
   int ids[NTHREADS];
   int value;

   for (i = 0; i < ASIZE; i++) {
        array[i] = i*atoi(argv[1]);
   }
   
   for (i = 0; i < NTHREADS; i++) { // create threads
      ids[i] = i;
      pthread_create(&tid[i], NULL, sum, (void*)&ids[i]);
   }
   
   for (i = 0; i < NTHREADS; i++) { // join threads 
      pthread_join(tid[i], NULL);
   }

   for (i = 0; i < NTHREADS; i++) {
      value += array_sum[i];
   }

   printf("%d\n", value);      
   
   return(0);
}
