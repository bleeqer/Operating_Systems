#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

volatile int counter = 0;
int loops;

void *worker(void *arg)
{
    int i;

    for (i = 0; i < loops; i++)
    {
        counter++;
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: threads<value>\n");
        exit(1);
    }

    loops = atoi(argv[1]);

    // pthread: POSIX thread
    // pthread_t: pthread type
    pthread_t p1, p2;

    printf("Initial value: %d\n", counter);

    // Ptrhead_create(thread, attr, start_routine, arg)
    pthread_create(&p1, NULL, worker, NULL);
    pthread_create(&p2, NULL, worker, NULL);
    
    // Pthread_join allows an application to wait for a thread to terminate
    // Pthread_join(thread, **value_ptr)
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("Final value: %d\n", counter);

    return 0;
}

/*
    volatile: a variable declared with volatile keyword are not altered by compiler during optimization run
*/