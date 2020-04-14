#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int main(){

    chdir("/");
    setsid();
    close(stdout);
    close(stdin);
    close(stderr);

    openlog("myDeamon",LOG_PID,LOG_DAEMON);
    syslog(LOG_NOTICE,"deamon started");
    usleep(1000000);
    syslog(LOG_NOTICE,"doing some work..");
    usleep(1000000);
    syslog(LOG_NOTICE,"deamon finished");

    return 0;
}