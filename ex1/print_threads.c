#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct {
    int thread_num;
} thread_data;

// הפונקציה שמבצע כל ת'רד
void* thread_function(void* arg) {
    thread_data* data = (thread_data*)arg;

    // הדפסת מספר הת'רד
    printf("Hi. I'm thread number %d\n", data->thread_num);

    free(data); // שחרור הזיכרון שהוקצה
    pthread_exit(NULL); // סיום הת'רד
}

// הפונקציה שמבצעת את דרישות המטלה
void print_threads(short unsigned int N) {
    pthread_t threads[N]; // מערך של ת'רדים

    for (int i = 0; i < N; i++) {
        thread_data* data = malloc(sizeof(thread_data));
        if (data == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }

        data->thread_num = i; // שמירת מספר הת'רד

        // יצירת ת'רד חדש
        if (pthread_create(&threads[i], NULL, thread_function, data) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // המתנה לסיום כל הת'רדים
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }
}
