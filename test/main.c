#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int i;
    pid_t pid;

    for (i = 0; i < 5; i++) {
        pid = fork();

        if (pid < 0) {
            printf("Fork failed.\n");
            exit(1);
        } else if (pid == 0) {
            // Child process
            printf("Child %d executing ls -l /tmp\n", i+1);
            char *args[] = {"ls", "-l", "/tmp", NULL};
            execvp("ls", args);
            printf("Failed to execute ls.\n");
            exit(1);
        } else {
            // Parent process
            wait(NULL);
            printf("Child %d exited.\n", i+1);
        }
    }

    return 0;
}

