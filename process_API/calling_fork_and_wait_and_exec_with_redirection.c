#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    printf("hello world (pid:%d)\n", (int) getpid());

    int rc = fork();

    if (rc < 0)
    {

        fprintf(stderr, "fork failed\n");
        exit(1);

    } else if (rc == 0)
    {

        // close standard output
        close(STDOUT_FILENO);

        open("./calling_form_and_wait_with_redirection.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

        printf("hello, i am child (pid:%d)\n", (int) getpid());
        
        char *myargs[3];

        // strdup returns a pointer to the duplicated version of its parameter
        myargs[0] = strdup("wc"); // word count
        myargs[1] = strdup("calling_fork_and_wait");
        myargs[2] = NULL;

        // exec function loads code from the given executable and overwirtes its current code segment (and current static data) with it
        // thus it does not create a new process, it transforms the currently running program in to a different running program(wc)
        // execvp(*path, *argv[])
        execvp(myargs[0], myargs);

        // a successful exec never returns
        printf("this shouldn't print out");

    } else 
    {

        int wc = wait(NULL);

    }

    return 0;
}