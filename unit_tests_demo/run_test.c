#include <criterion/criterion.h>
#include <criterion/logging.h>
#include "to_be_tested.h"


// Setup-Funktion (optional, falls nötig)
void setup(void) {
    cr_log_info("Setup: Starte Tests...\n");
}

// Teardown-Funktion (optional, falls nötig)
void teardown(void) {
    cr_log_info("Teardown: Test abgeschlossen.\n");
}

// Testfälle
TestSuite(addition_tests, .init = setup, .fini = teardown);




Test(addition_tests, test_add_function)
{
    cr_log_info("Testen der add function...\n");
    cr_expect(add(2, 3) == 5, "Expected return value = 1");
    cr_expect(add(2, 3) == 4, "Expected return value = 1");    
    cr_expect(add(2, 3) == 1, "Expected return value = 1");    
}


Test(addition_tests, test_add2_function)
{
    cr_log_info("Testen der add2 function...\n");
    cr_expect(add2(2, 3) == 5, "Expected 2 + 3 = 5");
    cr_expect(add2(1, 1) == 2, "Expected 1 + 1 = 2");
    cr_expect(add2(1, 1) == -1, "Expected 1 + 1 = 2");
}


