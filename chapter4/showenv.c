#include <stdlib.h>
#include <stdio.h>

extern char **environ;

int main(void)
{
    char **env = environ;

    while(*env) {
        printf("%s\n", *env);
        env++;
    }

    exit(0);
}
