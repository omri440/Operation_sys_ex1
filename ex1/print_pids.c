#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "my_fork.h"

void print_pids(int fd, short unsigned int N, short unsigned int G) {
    int g = 0; 

    for (int i = 1; i <= N; i++) {
        if (g < G) {
            pid_t my_pid = my_fork();
            if (my_pid == 0){
                 g++;
                i = 0; 
            } else {

                wait(NULL); 
                if(i !=N ){
                dprintf(fd, "My pid is %d. My generation is %d.\n", getpid(), g);}
                continue;

            }
        }
        else{
            pid_t  myPid = getpid();
             if (myPid != 0){
                wait(NULL);
                if( i !=N){
                dprintf(fd,"My pid is %d. My generation is %d.\n",getpid(),g);
                continue;       }}
                else{
        dprintf(fd,"My pid is %d. My generation is %d.\n",getpid(),g);
                        }

    }
    if (g != 0) {
        exit(0);
    }
}}
