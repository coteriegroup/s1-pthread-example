#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_SLEEP_USECS 1000000
#define THREAD_COUNT 4


//static pthread_mutex_t mtx;
static void *print_message(void *msg);

int main()
{
    pthread_t threads[THREAD_COUNT];
    size_t i;
    char * msg = "Hello, World!";
    setbuf(stdout, NULL);
    //pthread_mutex_init(&mtx, NULL);
    for (i = 0; i < THREAD_COUNT; ++i) pthread_create(&threads[i], NULL, print_message, msg);
    for (i = 0; i < THREAD_COUNT; ++i) pthread_join(threads[i], NULL);
    //pthread_mutex_destroy(&mtx);
    //printf("\n");
    return 0;
}

void *print_message(void *msg)
{
    const char *m = (char *)msg;
    size_t len = strlen(m);
    size_t i;
    //pthread_mutex_lock(&mtx);
    for (i = 0; i < len; i++)
    {
        printf("%c", m[i]);
        usleep(rand() % THREAD_SLEEP_USECS);
    }
    printf("\n");
    //pthread_mutex_unlock(&mtx);
    pthread_exit(NULL);
}
