// simple main file for testing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math_funcs.h"


int main(int argc, char *argv[])
{
    int n1 = 0;
    int n2 = 0;
    if (argc == 3)
    {
        n1 = atoi(argv[1]);
        n2 = atoi(argv[2]);
    }

    printf("\nResult of add_with_limits: %d\n\n", add_with_limits(n1, n2) );

    return 0;
}
