#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define ONE_K (1024)

int main(void)
{
    char *some_memory;
    int size_to_allocate = ONE_K;
    int megs_obtained = 0;
    int ks_obtained = 0;
    while (1)
    {
        for (ks_obtained = 0; ks_obtained < 1024; ks_obtained++)
        {
            some_memory = (char *)malloc(size_to_allocate);
            if (some_memory == NULL) exit(EXIT_FAILURE);
                sprintf(some_memory, "Hello world");
            if (ks_obtained == 512) 
            {
                printf("ks_obtained is %d\n", ks_obtained);
                sleep (10);
            }
            printf("the address of some_memory is %p\n", some_memory);
            
        }
        megs_obtained++;
        printf("Now allocated %d Megabytes\n", megs_obtained);
        sleep(100);
    }
    exit(EXIT_SUCCESS);
}
