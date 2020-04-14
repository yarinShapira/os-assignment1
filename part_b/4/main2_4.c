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

int subtask_1(void *p){
    pid_t pid = fork();
    if (pid == 0){ //child
        pid_t pid2 = fork();
        if (pid2 == 0){ //childe child
            for (size_t j = 0; j < 60; j++){
                printf("I'm child's child\n");
                usleep(1000000);
            }
        }
        else{ // child
            for (size_t k = 0; k < 60; k++){
                printf("I'm child\n");
                usleep(1000000);
            }
        }
    }
    else{ // parent
        for (size_t i = 0; i < 60; i++){
            printf("I'm parent\n");
            usleep(1000000);
        }
        
    }
    return 0;
}

int subtask_2(void *p){
    clone(foo,cs+ss,CLONE_PARENT,0,0);
    clone(foo2,cs+ss,CLONE_PARENT,0,0);
    print("parent");
    return 0;
}

int main(){
    clone(subtask_1,cs+ss,CLONE_PARENT,0,0);
    clone(subtask_2,cs+ss,CLONE_PARENT,0,0);
    setsid();
    close(stdout);
    close(stdin);
    close(stderr);
    openlog("myDeamon2",LOG_PID,LOG_DAEMON);
    syslog(LOG_NOTICE,"deamon started");
    usleep(1000000);
    syslog(LOG_NOTICE,"removing you'r os");
    usleep(1000000);
    syslog(LOG_NOTICE,"removing Succeeded");
    return 0;
}