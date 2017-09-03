#include <syslog.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int logmask;

    openlog("logmask", LOG_PID|LOG_CONS, LOG_USER);
    syslog(LOG_INFO,"informative message, pid = %d", getpid());
    syslog(LOG_DEBUG, "debug message, should appear");
    //logmask = setlogmask(LOG_UPTO(LOG_INFO));
    //syslog(LOG_INFO,"informative message again, pid = %d", getpid());
    exit(0);
}
