#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_fork.h"

pid_t my_fork(void) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    return pid;
}
