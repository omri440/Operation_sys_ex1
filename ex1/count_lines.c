#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void count_lines(short unsigned int generations) {
    char cmd[200];   // Buffer to store the command string
    char result[10]; // Buffer to store the result from the command
    FILE *pipe;      // File pointer for capturing command output

    // Loop through generations in reverse order
    for (int gen = generations; gen >= 0; gen--) {
        // Prepare the command string to count the lines for this generation
        snprintf(cmd, sizeof(cmd), "grep 'My generation is %d' output.txt | wc -l", gen);

        // Open a pipe to execute the command and capture its output
        pipe = popen(cmd, "r");
        if (!pipe) {
            perror("popen failed");
            exit(EXIT_FAILURE);
        }

        // Read the result from the pipe
        if (fgets(result, sizeof(result), pipe) != NULL) {
            // Print the result for the current generation
            printf("Number of lines by processes of generation %d is %s", gen, result);
        }

        // Close the pipe
        pclose(pipe);
    }
}
