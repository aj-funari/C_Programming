#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int global;

void *thread(void* arg){

   int *num = (int*) arg;
   int value = *num; // stores value from command line into value
   int i;
   int tmp;

   for (i = 0; i < value; i++) {
      tmp = rand() % value;
      global = tmp;
      printf("writer wrote: %d\n", tmp);
   } 
}

int main (int argc, char* argv[]) {

   pthread_t tid;
   int id;
   int i;

   srand(time(0));

   if (argc != 2) {
      printf("Not enough argumnets\n");
      exit(EXIT_FAILURE);
   } 

   // gets number from command line (argv[1]) to send to thread
   id = atoi(argv[1]);
   printf("number from argv[1] = %d\n", id);
 
   if (id < 1) {
      printf("argv(1) is not greater than 0\n");
      exit(EXIT_FAILURE);
   }
 
   pthread_create(&tid, NULL, thread, (void*)&id);
   
   for (i = 0; i < id; i++) {
      printf("main read = %d\n", global);
   }
   
   pthread_join(tid, NULL);
   
   return(0);   
}
