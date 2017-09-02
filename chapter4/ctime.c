#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    time_t timeval;
    (void)time(&timeval);
    printf("The date is: %s", ctime(&timeval));
    exit(0);
}
