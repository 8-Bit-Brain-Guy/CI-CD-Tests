## Von ChatGPT:
Hallo kannst du mir ein einfaches Beispiel zeigen, wie ich mit criterion einen unit test für einen c quellcode schreibe?
ChatGPT:

Ja, hier ist ein einfaches Beispiel, wie du mit Criterion einen Unit-Test für eine C-Funktion schreibst.
1. Installiere Criterion (falls noch nicht geschehen)

Unter Ubuntu/Debian:

sudo apt install libcriterion-dev



2. Beispiel-Code

Angenommen, du hast eine Funktion add() in math.c und die zugehörige Header-Datei math.h:
math.h

#ifndef MATH_H
#define MATH_H

int add(int a, int b);

#endif

math.c

#include "math.h"

int add(int a, int b) {
    return a + b;
}

3. Unit-Test mit Criterion

Erstelle eine Datei test_math.c für die Tests:
test_math.c

#include <criterion/criterion.h>
#include "math.h"

Test(math_tests, test_add) {
    cr_assert(add(2, 3) == 5, "Expected 2 + 3 to be 5");
    cr_assert(add(-1, 1) == 0, "Expected -1 + 1 to be 0");
}

4. Kompilieren und Ausführen

Mit gcc kannst du den Test so kompilieren und ausführen:

gcc -o test_math test_math.c math.c -lcriterion
./test_math

Criterion führt den Test automatisch aus und zeigt die Ergebnisse an. Falls ein Test fehlschlägt, wird das im Terminal angezeigt.

Falls du mehrere Tests hast, kannst du auch criterion direkt ausführen, wenn du CMake nutzt oder die Tests in ein separates Testverzeichnis legst.

Möchtest du noch etwas erweitern? 😊
Du:




Du:
Kannst du mir den unit test etwas erweitern?
ChatGPT:

Hier ist eine erweiterte Version des Unit-Tests mit mehr Testfällen, Setup/Teardown-Funktionen und negativen Tests.
Erweiterte Testdatei test_math.c

#include <criterion/criterion.h>
#include <criterion/logging.h>
#include "math.h"

// Setup-Funktion (optional, falls nötig)
void setup(void) {
    cr_log_info("Setup: Starte Tests...\n");
}

// Teardown-Funktion (optional, falls nötig)
void teardown(void) {
    cr_log_info("Teardown: Test abgeschlossen.\n");
}

// Testfälle
TestSuite(math_tests, .init = setup, .fini = teardown);

Test(math_tests, test_add_positive) {
    cr_expect(add(2, 3) == 5, "2 + 3 sollte 5 sein.");
    cr_expect(add(10, 15) == 25, "10 + 15 sollte 25 sein.");
}

Test(math_tests, test_add_negative) {
    cr_expect(add(-2, -3) == -5, "-2 + (-3) sollte -5 sein.");
    cr_expect(add(-10, 5) == -5, "-10 + 5 sollte -5 sein.");
}

Test(math_tests, test_add_zero) {
    cr_expect(add(0, 0) == 0, "0 + 0 sollte 0 sein.");
    cr_expect(add(7, 0) == 7, "7 + 0 sollte 7 sein.");
}

Test(math_tests, test_add_large_numbers) {
    cr_expect(add(1000000, 2000000) == 3000000, "1.000.000 + 2.000.000 sollte 3.000.000 sein.");
}

Test(math_tests, test_add_overflow) {
    int result = add(2147483647, 1); // INT_MAX + 1
    cr_expect(result < 0, "Overflow sollte auftreten.");
}

Was wurde verbessert?

✅ Mehr Testfälle → Positiv, negativ, Nullwerte, große Zahlen, Overflow
✅ Setup- und Teardown-Funktionen → Zeigen Teststatus in der Konsole
✅ cr_expect statt cr_assert → Zeigt alle Fehler an, statt sofort abzubrechen
✅ Logging mit cr_log_info → Gibt Statusmeldungen während des Tests aus

Damit kannst du robustere Tests für deine C-Funktion schreiben. Willst du noch eine spezielle Erweiterung? 😊
Du:
wie kann ich cr_log_info  benutzen?
ChatGPT:

cr_log_info ist eine Logging-Funktion in Criterion, die nützlich ist, um Statusmeldungen während der Testausführung auszugeben.
Grundlegende Nutzung

#include <criterion/criterion.h>
#include <criterion/logging.h>

Test(logging_example, test_logging) {
    cr_log_info("Dieser Test startet jetzt...\n");

    int result = 2 + 3;
    cr_expect(result == 5, "Erwartet wurde 5, aber erhalten: %d", result);

    cr_log_info("Dieser Test wurde erfolgreich abgeschlossen.\n");
}

Wichtige Punkte

    Syntax:

cr_log_info("Text mit %d als Platzhalter\n", variable);

    Funktioniert wie printf mit Platzhaltern (%d, %s, etc.).

Weitere Log-Level:
Funktion	Beschreibung
cr_log_info("...")	Normale Meldung
cr_log_warn("...")	Warnung
cr_log_error("...")	Fehler-Meldung
cr_log_debug("...")	Debug-Information (nur sichtbar mit --verbose)

Logging in Setup/Teardown nutzen

    void setup(void) {
        cr_log_info("Setup: Test startet!\n");
    }

    void teardown(void) {
        cr_log_info("Teardown: Test abgeschlossen!\n");
    }

    TestSuite(math_tests, .init = setup, .fini = teardown);

Test mit --verbose ausführen

Standardmäßig werden nur Warnungen und Fehler angezeigt. Falls du cr_log_info oder cr_log_debug sehen willst, führe den Test mit --verbose aus:

./test_math --verbose

So kannst du Logging für detaillierte Testausgaben nutzen. Brauchst du noch ein Beispiel für eine spezifische Situation? 😊


