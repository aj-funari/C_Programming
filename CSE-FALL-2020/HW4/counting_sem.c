#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;

void* print_A (void* arg) {

   int i = 65;
   char A = i;
   
   sem_wait(&mutex);
   printf("%c\n", A);
   sem_post(&mutex);
   return(0);
}

void* print_B (void* arg) {
 
   int j = 66;
   char B = j;
   
   sem_wait(&mutex);
   printf("%c\n", B);
   return(0);
}

void* print_C (void* arg) {
 
   int k = 67;
   char C = k;

   sem_wait(&mutex);
   printf("%c\n", C);
   return(0);
}

int main (int argc, char* argv[]) {

   pthread_t tid[3];
   
   if (argc != 1) {
      printf("too many arguments\n");
      exit(EXIT_FAILURE);
   }

   sem_init(&mutex,0,2);

   pthread_create(&tid[0], NULL, print_A, NULL);
   pthread_create(&tid[1], NULL, print_B, NULL);
   pthread_create(&tid[2], NULL, print_C, NULL);

   pthread_join(tid[0], NULL);
   pthread_join(tid[1], NULL);
   pthread_join(tid[2], NULL); 
   
   return(0);    
}
