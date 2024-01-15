#include <stdio.h>
#include <stdlib.h>

/**
 * This file is used to create the libwin.so library
 * to be used in the injection process of the gm application
*/
int printf(const char *format, ...)
{
    puts("9 8 10 24 75 - 9");
    puts("Congratulations, you win the Jackpot!");
    exit(0);
}
