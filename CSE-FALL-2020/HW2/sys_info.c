#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {

   char *bin_path, *arg1, *arg2;
   char *buffer = NULL;
   pid_t pid;
   int fd[2];
   
   if (argc != 3) {
      printf("Error: not enough arguments\n");
      exit(EXIT_FAILURE);
   }

   bin_path = malloc(sizeof(char)*(strlen(argv[1] + 1)));
   arg1 = malloc(sizeof(char)*(strlen(argv[1] + 1)));
   arg2 = malloc(sizeof(char)*(strlen(argv[2] + 1)));

   strcpy(arg1, argv[1]);
   strcpy(arg2, argv[2]);

   if (argv[1][0] == '/') {
      strcpy(bin_path, argv[1]);
   }

   else {
      strcpy(bin_path, "/bin/");
      strcat(bin_path, argv[1]);
   }

   pid = fork();

   if (pipe(fd) == -1) {
      printf("Error: pipe did not open successfully\n");
      exit(EXIT_FAILURE);
   }
   
   if (pid == 0) { // child
      close(fd[1]);
      read(fd[0], buffer, strlen(argv[1] + 1));
      read(fd[0], buffer, strlen(argv[2] + 1));
      close(fd[0]);

      if (execl(bin_path, arg1, arg2, NULL) == -1) {
         printf("Error: execl failed\n");
         exit(EXIT_FAILURE);
      }
   }

   else { // parent        
      close(fd[0]);
      write(fd[1], arg1, strlen(argv[1] + 1));   
      write(fd[1], arg2, strlen(argv[2] + 1));
      close(fd[1]);
   }
}
