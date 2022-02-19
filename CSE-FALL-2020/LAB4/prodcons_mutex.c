#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int global;
sem_t r_mutex, w_mutex;

void *thread(void* arg){

   int *num = (int*) arg;
   int value = *num; // stores value from command line into value
   int i;
   int tmp;

   for (i = 0; i < value; i++) {
      sem_wait(&r_mutex); // sem_wait decrements
      tmp = rand() % value;
      global = tmp;
      printf("writer wrote: %d\n", tmp); // sem_post increments
      sem_post(&w_mutex);
   } 
}

int main (int argc, char* argv[]) {

   pthread_t tid;
   int id;
   int i;

   sem_init(&r_mutex, 1, 1);
   sem_init(&w_mutex, 1, 0);
   
   srand(time(0));

   if (argc != 2) {
      printf("Not enough argumnets\n");
      exit(EXIT_FAILURE);
   } 

   // gets number from command line (argv[1]) to send to thread
   id = atoi(argv[1]);
   
   if (id < 1) {
      printf("argv(1) is not greater than 0\n");
      exit(EXIT_FAILURE);
   }
 
   pthread_create(&tid, NULL, thread, (void*)&id);
   
   for (i = 0; i < id; i++) {
      sem_wait(&w_mutex);
      printf("main read = %d\n", global);
      sem_post(&r_mutex);
   }
   
   pthread_join(tid, NULL);
   
   return(0);
}
