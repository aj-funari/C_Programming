#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main (int argc, char* argv[]) {

   int i, half = 0, sum_parent = 0, total;
   long int sum_child = 0;
   int array[ASIZE];
   int value;
   int fd[2]; //fd[0] = read, fd[1] = write 
   pid_t pid, status;
   char message[20], buff[20];
   ssize_t status0;

   if (argc != 2) {
      printf("Error: not enough arguments\n");
      exit(EXIT_FAILURE);
   }

   for (i = 0; i < ASIZE; i++) {
      array[i] = i*atoi(argv[1]);
   }
  
   if (pipe(fd) == -1) {
      printf("Error: pipe did not open successfully\n");
      exit(EXIT_SUCCESS);
   }

   pid = fork();
 
   half = ASIZE/2;

   if (pid == 0) { // child
      for (i = 0; i < half; i++) {
         sum_child += array[i]; 
      }
      
      close(fd[0]);
      sprintf(message, "%ld", sum_child);
      write(fd[1], message, sizeof(message));
      // write() can only write in characters 
      close(fd[1]);
   }

   else { // parent; only parent can wait
      for (i = half; i < ASIZE; i++) {
         sum_parent += array[i];
      } 

      wait(&status); // successful 
      
      close(fd[1]);
      status0 = read(fd[0], buff, sizeof(buff));
      value = atoi(buff);
      close(fd[0]);

      total = value + sum_parent;
      printf("%d\n", total);
   }
}
