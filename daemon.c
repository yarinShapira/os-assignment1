#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int main(){


    pid_t pid = fork();

    if(pid == 0){

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
          

    }
    else {

        printf("deamon pid %d\n", pid);
    }
    return 0;
}