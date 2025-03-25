#include <criterion/criterion.h>
#include <criterion/logging.h>
#include "math_funcs.h"

// Setup-Funktion (optional, falls nötig)
void setup(void)
{
    cr_log_info("Setup: Starte Tests...\n");
}

// Teardown-Funktion (optional, falls nötig)
void teardown(void)
{
    cr_log_info("Teardown: Test abgeschlossen.\n");
}

// Testfälle
TestSuite(Addition_Tests, .init = setup, .fini = teardown);


Test(Addition_Tests, add_with_limits)
{
    cr_log_info("Testen der add_with_limits function...\n");
    cr_expect(add_with_limits(2, 3) == 5, "Expected add_with_limits of 2 and 3 = 5");
}
