#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_fork.h"
#include "print_pids.h"
#include "count_lines.h"
#include "print_threads.h"

int main(int argc, char* argv[]) {
    // בדיקת מספר ארגומנטים
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <N> <G> <number_of_threads>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // קריאת ערכים מהארגומנטים
    short unsigned int N = atoi(argv[1]); // מספר התהליכים
    short unsigned int G = atoi(argv[2]); // מספר הדורות
    short unsigned int num_threads = atoi(argv[3]); // מספר הת'רדים

    // פתיחת קובץ לכתיבה
    int fd = open("out.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    // קריאה לפונקציות לפי הסדר
    print_pids(fd, N, G);        // יצירת תהליכים והדפסתם
    count_lines(G);              // בדיקת התוצאות של print_pids
    print_threads(num_threads);  // יצירת ת'רדים והדפסתם

    // סגירת הקובץ
    close(fd);

    printf("Output written to out.txt\n");
    return EXIT_SUCCESS;
}
