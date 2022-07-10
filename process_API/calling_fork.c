#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{   
    // only executed once
    printf("hello world (pid:%d)\n", (int) getpid());

    // return child PID for the parent process, 0 for the child
    int rc = fork();

    if (rc < 0)
    {

        fprintf(stderr, "fork failed\n");
        exit(1);

    } else if (rc == 0)
    {

        printf("hello, i am child (pid:%d)\n", (int) getpid());

    } else
    {

        printf("hello, i am parent of %d (pid: %d)\n", rc, (int) getpid());
    
    }

    return 0;
}