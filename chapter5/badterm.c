#include <stdio.h>
#include <term.h>
#include <curses.h>
#include <stdlib.h>

int main(void)
{
    setupterm("xterm", fileno(stdout), (int *)0);
    printf("Done.\n");
    exit(0);
}
