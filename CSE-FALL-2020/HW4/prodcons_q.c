#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

char array[5]; // buffer
sem_t w_mutex, r_mutex, mutex; // need to control position of array: how? 
int j = 0, k = 0; 

void* lower_case (void* arg) {
   
   int *id = (int*) arg;
   int i, num;
   char letter;

   for (i = 0; i < 5; i++) {
      sem_wait(&w_mutex);
      sem_wait(&mutex);
      num = rand() % 26;
      num += 97;
      letter = num;
      array[j] = letter;
      j++;
      j = j % 5;
      printf("writer ID: %d, char written: %c\n", *id, letter);
      sem_post(&r_mutex);
      sem_post(&mutex);
   }
   return (void*)NULL; 
}

void* upper_case (void* arg) {

   int *id = (int*) arg;
   int i, num;
   char letter;
     
   for (i = 0; i < 5; i++) {
      sem_wait(&w_mutex);
      sem_wait(&mutex);
      num = rand() % 26;
      num += 65;
      letter = num;
      array[j] = letter;
      j++;
      j = j % 5;
      printf("writer ID: %d, char written %c\n", *id, letter);
      sem_post(&r_mutex);
      sem_post(&mutex);
   }
   return (void*)NULL;
}  

void* read (void* arg) {

   int *id = (int*) arg;
   int i;
   char letter;

   for (i = 0; i < 5; i++) {
      sem_wait(&r_mutex);
      sem_wait(&mutex);
      letter = array[k];
      k++;
      k = k % 5;
      printf("reader ID: %d, char read %c\n", *id, letter);
      sem_post(&w_mutex);
      sem_post(&mutex);
   }
   return (void*)NULL;
} 

int main (int argc, char* argv[]) {

   pthread_t tid[8];
   int ids[8] = {0,1,2,3};
   int i;
   
   if (argc != 1) {
      printf("too many arguments\n");
      exit(EXIT_FAILURE);
   }

   srand(time(0)); // uses current time to generate random values
 
   sem_init(&w_mutex, 0, 5); // can only write max 5 times until it must wait 
   sem_init(&r_mutex, 0, 0);  
   sem_init(&mutex, 0, 1);

   pthread_create(&tid[0], NULL, lower_case, &ids[0]);
   pthread_create(&tid[1], NULL, lower_case, &ids[1]);
   
   pthread_create(&tid[2], NULL, upper_case, &ids[2]);
   pthread_create(&tid[3], NULL, upper_case, &ids[3]);
   
   pthread_create(&tid[4], NULL, read, &ids[0]);
   pthread_create(&tid[5], NULL, read, &ids[1]);
   pthread_create(&tid[6], NULL, read, &ids[2]);
   pthread_create(&tid[7], NULL, read, &ids[3]);
   
   for (i = 0; i < 8; i++) { // join threads
      pthread_join(tid[i], NULL);
   }

   return(0);
}
