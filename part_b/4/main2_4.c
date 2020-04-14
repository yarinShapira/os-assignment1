#define _GNU_SOURCE
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>
#include <syslog.h>




#define ss 10000
#define CYCLES 100
char cs [ss+1];

void print(const char *text){
    int i;
    for(i=0 ; i<CYCLES ; i++){
        printf("Hello from %s \n", text);
        usleep(1000000);
    }
}

int foo(void *p){
   print("child thread");
   return 0;
}
int foo2(void *p){
   print("second child thread");
   return 0;
}

int main(){
    pid_t pid = fork();
    printf("%d\n",pid);
    if (pid == 0){ //child
        pid_t pid2 = fork();
        if (pid2 == 0){ //childe child
                print("child's child");
        }
        else{ // child
                print("child\n");
            }
    }
    else{ // parent
        clone(foo,cs+ss,CLONE_PARENT,0,0);
        clone(foo2,cs+ss,CLONE_PARENT,0,0);
        pid_t pid = fork();
        printf("%d\n",pid);
        if(pid == 0){
            chdir("/");
            setsid();
            close(stdout);
            close(stdin);
            close(stderr);

            openlog("myDeamon2",LOG_PID,LOG_DAEMON);
            syslog(LOG_NOTICE,"deamon started");
            usleep(1000000);
            syslog(LOG_NOTICE,"doing some work..");
            usleep(1000000);
            syslog(LOG_NOTICE,"deamon finished");
         }
        print("I'm parent\n");
        }
    return 0; 
}