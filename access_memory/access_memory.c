#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> // assertion macro 
#include <sys/time.h> // time related



int main(int argc, char *argv[])
{
    int *p = malloc(sizeof(int));
    
    assert(p != NULL);
    
    // prints at least 8 digits of hexadecimal filling blank spaces with zero
    printf(" (%d) address of p: %08x\n",
            getpid(), (unsigned) p);

    *p = 0;

    while (1) 
    {
        // Spin(1);
        sleep(1);

        *p = *p + 1;
        
        printf(" (%d) p: %d\n", getpid(), *p);
    }

    return 0;
}