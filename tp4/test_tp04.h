#ifndef TEST_TP04_H_INCLUDED
#define TEST_TP04_H_INCLUDED

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

/* alteration of standards for test purpose */

#ifdef TST_MAIN

/* Wrap around main */
extern int mock_main(int argc, char **argv) ;
#define main mock_main

/* Overloading printf */
#define printf mock_printf
extern int mock_printf(const char *format, ...) ;
#endif

#ifdef TST_SAISIE
/* Overloading getchar */
#undef getchar
#define getchar(c) (get_fake()) ;
extern void fake_input(char *) ;
extern char get_fake() ;
#endif

#if defined(TST_MIROIR) || defined(TST_SAISIE)
#define malloc(x) ((x) == 13 ? NULL : malloc(x))
#endif

#endif
