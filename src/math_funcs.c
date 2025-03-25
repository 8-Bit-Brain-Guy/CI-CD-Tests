#include "math_funcs.h"

int add_with_limits(int z1, int z2)
{
    int ret = -1;
    if ( (z1 <= 20) && ( z2 <= 20 ) )
    {
        ret = (z1 + z2);
    }
    return ret;
}