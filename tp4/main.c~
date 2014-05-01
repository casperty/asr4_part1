#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "minunit.h"

#include "chaines.h"

/* This section to compute test options
TST_MIROIR
TST_SAISIE
TST_MAIN
TST_ALL
or mixed of these. */

/* If none specified then use TST_ALL as default value */
#if !defined(TST_MIROIR) && !defined(TST_SAISIE) && !defined(TST_MAIN)
#define TST_ALL
#endif

/* If TST_ALL active (explicitly or implicitly) then set all test options */
#ifdef TST_ALL
#define TST_MIROIR
#define TST_SAISIE
#define TST_MAIN
#endif

#ifdef TST_MAIN
#undef main
#undef printf
extern int mock_main(int argc, char **argv) ;
#endif

#ifdef TST_SAISIE
/****************** fake input *******************/
static const char *fake_store ;
static const char *current ;

void fake_input(char *fake_value) {
    fake_store = current = fake_value ;
}

char get_fake() {
    char c ;
    if (*current == '\0') {
        return ' ' ;
    }
    c = *current ;
    current++ ;
    return c ;
}
#endif

#ifdef TST_MAIN
/****************** fake output ******************/
static char out_buffer[1000] ;
static char *out_ptr = out_buffer ;

int mock_printf(const char*format, ...) {
    va_list args ;
    int char_count ;
    va_start(args, format) ;
    char_count = vsprintf(out_ptr, format, args) ;
    out_ptr += char_count ;
    va_end(args) ;
    return char_count ;
}

#define MU_CHECK_OUTPUT(expected) do {      \
    *out_ptr = '\0' ;                       \
    MU_ASSERT_EQUAL(strcmp(out_buffer, expected), 0) ; \
} while (0)

#endif

#ifdef TST_MIROIR
/****************** miroir *******************/

MU_SETUP(miroir) {
}
MU_TEAR_DOWN(miroir) {
}
MU_TEST(miroir, miroir_simple) {
    char *res = miroir("12345") ;
    MU_ASSERT_EQUAL(strcmp(res, "54321"), 0) ;
    free(res) ;
}
MU_TEST(miroir, chaine_vide) {
    char *res = miroir("") ;
    MU_ASSERT_EQUAL(strcmp(res, ""), 0) ;
    free(res) ;
}
MU_TEST(miroir, miroir_simple2) {
    char *res = miroir("ABCDEFG_HIJKLMN") ;
    MU_ASSERT_EQUAL(strcmp(res, "NMLKJIH_GFEDCBA"), 0) ;
    free(res) ;
}
MU_TEST(miroir, short_of_memory) {
    /* A altered 13 bytes malloc request return NULL (cf tp04.h) */
    char *res = miroir("123456789012") ;
    MU_ASSERT_EQUAL(res, NULL) ;
    free(res) ;
}
MU_TEST_SUITE(miroir) = {
    MU_ADD_TEST(miroir, miroir_simple),
    MU_ADD_TEST(miroir, chaine_vide),
    MU_ADD_TEST(miroir, miroir_simple2),
    MU_ADD_TEST(miroir, short_of_memory),
    MU_TEST_SUITE_END
} ;
#endif

#ifdef TST_SAISIE
/****************** saisie *******************/
MU_SETUP(saisie) {
}
MU_TEAR_DOWN(saisie) {
}
MU_TEST(saisie, 0_car) {
    char *res ;
    fake_input(" ") ;
    res = saisie() ;
    MU_ASSERT_EQUAL(strcmp(res, ""), 0) ;
    free(res) ;
}
MU_TEST(saisie, 1_car) {
    char *res ;
    fake_input("1 ") ;
    res = saisie() ;
    MU_ASSERT_EQUAL(strcmp(res, "1"), 0) ;
    free(res) ;
}
MU_TEST(saisie, 2_car_space) {
    char *res ;
    fake_input("12 ") ;
    res = saisie() ;
    MU_ASSERT_EQUAL(strcmp(res, "12"), 0) ;
    free(res) ;
}
MU_TEST(saisie, 2_car_newline) {
    char *res ;
    fake_input("12\n") ;
    res = saisie() ;
    MU_ASSERT_EQUAL(strcmp(res, "12"), 0) ;
    free(res) ;
}
MU_TEST(saisie, 2_car_tab) {
    char *res ;
    fake_input("12\t") ;
    res = saisie() ;
    MU_ASSERT_EQUAL(strcmp(res, "12"), 0) ;
    free(res) ;
}
MU_TEST(saisie, 9_car) {
    char *res ;
    fake_input("123456789 ") ;
    res = saisie() ;
    MU_ASSERT_EQUAL(strcmp(res, "123456789"), 0) ;
    free(res) ;
}
MU_TEST(saisie, 10_car) {
    char *res ;
    fake_input("1234567890 ") ;
    res = saisie() ;    MU_ASSERT_EQUAL(strcmp(res, "1234567890"), 0) ;
    free(res) ;
}
MU_TEST(saisie, 11_car) {
    char *res ;
    fake_input("12345678901 ") ;
    res = saisie() ;
    MU_ASSERT_EQUAL(strcmp(res, "12345678901"), 0) ;
    free(res) ;
}
MU_TEST(saisie, 19_car) {
    char *res ;
    fake_input("1234567890123456789 ") ;
    res = saisie() ;
    MU_ASSERT_EQUAL(strcmp(res, "1234567890123456789"), 0) ;
    free(res) ;
}
MU_TEST(saisie, 20_car) {
    char *res ;
    fake_input("12345678901234567890 ") ;
    res = saisie() ;
    MU_ASSERT_EQUAL(strcmp(res, "12345678901234567890"), 0) ;
    free(res) ;
}
MU_TEST(saisie, 21_car) {
    char *res ;
    fake_input("123456789012345678901 ") ;
    res = saisie() ;
    MU_ASSERT_EQUAL(strcmp(res, "123456789012345678901"), 0) ;
    free(res) ;
}
MU_TEST(saisie, 22_car) {
    char *res ;
    fake_input("1234567890123456789012 ") ;
    res = saisie() ;
    MU_ASSERT_EQUAL(strcmp(res, "1234567890123456789012"), 0) ;
    free(res) ;
}
MU_TEST_SUITE(saisie) = {
    MU_ADD_TEST(saisie, 0_car),
    MU_ADD_TEST(saisie, 1_car),
    MU_ADD_TEST(saisie, 2_car_space),
    MU_ADD_TEST(saisie, 2_car_newline),
    MU_ADD_TEST(saisie, 2_car_tab),
    MU_ADD_TEST(saisie, 9_car),
    MU_ADD_TEST(saisie, 10_car),
    MU_ADD_TEST(saisie, 11_car),
    MU_ADD_TEST(saisie, 19_car),
    MU_ADD_TEST(saisie, 20_car),
    MU_ADD_TEST(saisie, 21_car),
    MU_ADD_TEST(saisie, 22_car),
    MU_TEST_SUITE_END
} ;
#endif

#ifdef TST_MAIN
/****************** main program test *******************/
MU_SETUP(main) {
    out_ptr = out_buffer ;
}
MU_TEAR_DOWN(main) {
}
MU_TEST(main, no_argument) {
    char *argv[] = {"commande"} ;
    int argc = sizeof(argv) / sizeof(char*) ;
    mock_main(argc, argv) ;
    MU_CHECK_OUTPUT("mauvaise utilisation\n") ;
}
MU_TEST(main, wrong_option) {
    char *argv[] = {"commande", "-x"} ;
    int argc = sizeof(argv) / sizeof(char*) ;
    mock_main(argc, argv) ;
    MU_CHECK_OUTPUT("mauvaise utilisation\n") ;
}
MU_TEST(main, two_arguments) {
    char *argv[] = {"commande", "arg1", "arg2"} ;
    int argc = sizeof(argv) / sizeof(char*) ;
    mock_main(argc, argv) ;
    MU_CHECK_OUTPUT("mauvaise utilisation\n") ;
}
MU_TEST(main, conflicting_optionS_then_argument) {
    char *argv[] = {"commande", "-s", "arg2"} ;
    int argc = sizeof(argv) / sizeof(char*) ;
    mock_main(argc, argv) ;
    MU_CHECK_OUTPUT("mauvaise utilisation\n") ;
}
MU_TEST(main, conflicting_argument_then_optionS) {
    char *argv[] = {"commande", "arg2", "-s"} ;
    int argc = sizeof(argv) / sizeof(char*) ;
    mock_main(argc, argv) ;
    MU_CHECK_OUTPUT("mauvaise utilisation\n") ;
}
MU_TEST(main, echo_argument) {
    char *argv[] = {"Commande", "Argument"} ;
    int argc = sizeof(argv) / sizeof(char*) ;
    mock_main(argc, argv) ;
    MU_CHECK_OUTPUT("Argument\n") ;
}
MU_TEST(main, echo_input) {
    char *argv[] = {"Commande", "-s"} ;
    int argc = sizeof(argv) / sizeof(char*) ;
    fake_input("user_entry ") ;
    mock_main(argc, argv) ;
    MU_CHECK_OUTPUT("user_entry\n") ;
}
MU_TEST(main, mirror_argument) {
    char *argv[] = {"Commande", "-m", "miror_arg"} ;
    int argc = sizeof(argv) / sizeof(char*) ;
    mock_main(argc, argv) ;
    MU_CHECK_OUTPUT("gra_rorim\n") ;
}
MU_TEST(main, mirror_input) {
    char *argv[] = {"Commande", "-s", "-m"} ;
    int argc = sizeof(argv) / sizeof(char*) ;
    fake_input("userInput ") ;
    mock_main(argc, argv) ;
    MU_CHECK_OUTPUT("tupnIresu\n") ;
}
MU_TEST(main, combined_options) {
    char *argv[] = {"Commande", "-sm"} ;
    int argc = sizeof(argv) / sizeof(char*) ;
    fake_input("Monday ") ;
    mock_main(argc, argv) ;
    MU_CHECK_OUTPUT("yadnoM\n") ;
}
MU_TEST(main, repeated_option) {
    char *argv[] = {"Commande", "-m", "-m", "Winter"} ;
    int argc = sizeof(argv) / sizeof(char*) ;
    mock_main(argc, argv) ;
    MU_CHECK_OUTPUT("retniW\n") ;
}
MU_TEST(main, full_test) {
    char *argv[] = {"Commande", "-m", "-sms", "-s"} ;
    int argc = sizeof(argv) / sizeof(char*) ;
    fake_input("hello\n") ;
    mock_main(argc, argv) ;
    MU_CHECK_OUTPUT("olleh\n") ;
}
MU_TEST_SUITE(main) = {
    MU_ADD_TEST(main, no_argument),
    MU_ADD_TEST(main, two_arguments),
    MU_ADD_TEST(main, wrong_option),
    MU_ADD_TEST(main, conflicting_optionS_then_argument),
    MU_ADD_TEST(main, conflicting_argument_then_optionS),
    MU_ADD_TEST(main, echo_argument),
    MU_ADD_TEST(main, echo_input),
    MU_ADD_TEST(main, mirror_argument),
    MU_ADD_TEST(main, mirror_input),
    MU_ADD_TEST(main, combined_options),
    MU_ADD_TEST(main, repeated_option),
    MU_ADD_TEST(main, full_test),
    MU_TEST_SUITE_END
} ;
#endif

/****************** main *******************/
int main(int argc, char **argv) {
#ifdef TST_MIROIR
    MU_RUN_TEST_SUITE_WITH_REPORT(miroir) ;
#endif
#ifdef TST_SAISIE
    MU_RUN_TEST_SUITE_WITH_REPORT(saisie) ;
#endif
#ifdef TST_MAIN
    MU_RUN_TEST_SUITE_WITH_REPORT(main) ;
#endif
    return 0 ;
}

