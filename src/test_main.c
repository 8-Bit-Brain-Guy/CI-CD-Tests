#include <criterion/criterion.h>
#include "main.c"

Test(addition, simple_add) {
    cr_assert(add_with_limits(2, 3) == 5, "Addition failed");
}
