#include <stdio.h> // I/O
#include <stdlib.h> // C standard library

int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        // write into the file pointer(stderr)
        // stderr is the defualt file descriptor where a process can write error messages
        fprintf(stderr, "usage: cpu <string>\n");
    }

    char *str = argv[1];

    while (1)
    {
        printf("%s\n", str);
    }

    return 0;
}

/*
    segmentation fault: caused by a program trying to read or write an illegal memory location
    core dump: a file of a computer's documented memory of when a program or computer crashed
*/