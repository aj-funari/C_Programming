#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]) {

   int fd[2];
   pid_t pid;
   char *buff;
   int len;

   if (argc != 2) {
      printf("Error: wrong number of arguments\n");
      exit(EXIT_FAILURE);
   }
   
   if (pipe(fd) == -1) {
      printf("An error has occured with opening the pipe\n");
      exit(EXIT_FAILURE);
   }

   pid = fork();
   len = strlen(argv[1]);
   buff = malloc(sizeof(char)*len);

   if(pid == 0) { // child
      close(fd[1]);
      read(fd[0], buff, strlen(argv[1]));
      printf("%s\n", buff);
      close(fd[0]);
   }
   
   else { // parent 
      close(fd[0]);
      write(fd[1], argv[1], strlen(argv[1]));
      close(fd[1]);
   }
   
   free(buff);
   exit(EXIT_SUCCESS);
}  
