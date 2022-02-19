#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char* argv[]) {
   
   int fd[2]; 
   // fd[0] = read
   // fd[1] = write
   pid_t cpid; // singed integer 
   char *buff;
   size_t len;

   if (argc != 3) {
      printf("Error: wrong number of arguments\n");
      exit(EXIT_FAILURE);
   }

   // pipe(fd) creates two file descriptors; are independent from each other

   if (pipe(fd) == -1) {
      printf("An error has occurd with opening the pipe\n");
      exit(EXIT_FAILURE);
   }
   
   len = strlen(argv[1])+1;   
   buff = malloc(sizeof(char)*len);  
   write(fd[1], argv[1], len);
   read(fd[0], buff, len);
   printf("%s\n", buff);

   len = strlen(argv[2])+1;
   buff = malloc(sizeof(char)*len);  
   write(fd[1], argv[2], len);
   read(fd[0], buff, len);
   printf("%s\n", buff);

   free(buff);
   close(fd[1]);
   close(fd[0]);

}

