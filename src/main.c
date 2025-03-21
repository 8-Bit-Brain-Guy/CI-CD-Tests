// simple main file for testing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int add_with_limits(int z1, int z2)
{
    int ret = -1;
    if ( (z1 <= 100) && ( z2 <= 100 ) )
    {
        ret = (z1 + z2);
    }
    return ret;
}


int main(int argc, char *argv[])
{
    int n1 = 0;
    int n2 = 0;
    if (argc == 3)
    {
        n1 = atoi(argv[1]);
        n2 = atoi(argv[2]);
    }        

    printf("\nHello World!\n");    
    printf("Result with limits: %d\n\n", add_with_limits(n1, n2) );
    
    return 0;
}
