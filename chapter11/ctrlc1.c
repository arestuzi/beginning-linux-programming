#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ouch2(int sig)
{
    printf("OUCH2! - I got signal %d\n", sig);
    (void) signal(SIGINT, SIG_DFL);
}
void ouch(int sig)
{
    printf("OUCH! - I got signal %d\n", sig);
    (void) signal(SIGINT, ouch2);
}

int main(void)
{
    signal(SIGINT, ouch);

    while(1) {
        printf("Hello World!\n");
        sleep(1);
    }
}
