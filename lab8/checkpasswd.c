#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXLINE 256
#define MAX_PASSWORD 10  

#define SUCCESS "Password verified\n"
#define INVALID "Invalid password\n"
#define NO_USER "No such user\n"

int main(void) {
  char user_id[MAXLINE];
  char password[MAXLINE];

  /* The user will type in a user name on one line followed by a password 
     on the next.
     DO NOT add any prompts.  The only output of this program will be one 
	 of the messages defined above.
     Please read the comments in validate carefully
   */

  if(fgets(user_id, MAXLINE, stdin) == NULL) {
      perror("fgets");
      exit(1);
  }
  if(fgets(password, MAXLINE, stdin) == NULL) {
      perror("fgets");
      exit(1);
  }
  
  // TODO
  
  int pipe_fd[2];

  if (pipe(pipe_fd) == -1) {
    perror("pipe");  
    exit(1);

  }

  int f = fork();

  if (f == 0) {
    if (close(pipe_fd[1]) == -1) {
      perror("close");
      exit(1);
    
    }
    
    dup2(pipe_fd[0], STDIN_FILENO);
    close(pipe_fd[0]);
    execl("./validate", "validate", NULL);
    perror("execl");
    exit(1);
    

  } else {

    if (close(pipe_fd[0]) == -1) {
      perror("close");
      exit(1);
    
    }

    if (strlen(password)-1 > MAX_PASSWORD) {
      printf(INVALID);
      exit(0);
    }

    if (strlen(user_id)-1 > MAX_PASSWORD) {
      printf(NO_USER);
      exit(0);
    }

    if (write(pipe_fd[1], user_id, MAX_PASSWORD) == -1) {
      perror("write");
      exit(1);
    
    }
    if (write(pipe_fd[1], password, MAX_PASSWORD) == -1) {
      perror("write");
      exit(1);
    
    }

    if (close(pipe_fd[1]) == -1) {
      perror("close");
      exit(1);
    }

    int status;
    if (wait(&status) == -1) {
      perror("wait");
      exit(1);
    }

    if (WIFEXITED(status)) {
      int exit_status = WEXITSTATUS(status);
      if (exit_status == 0) {
        printf(SUCCESS);
      } else if (exit_status == 1) {
        exit(0);
      } else if (exit_status == 2) {
        printf(INVALID);
      } else if (exit_status == 3) {
        printf(NO_USER);
      } 
    } else {
      exit(1);
    }

  }
  


  return 0;
}
