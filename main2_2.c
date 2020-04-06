#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sched.h>


#define ss 1000
char cs [ss+1];

int foo(void *p){
    for (size_t k = 0; k < 60; k++){
        printf("I'm child\n");
        usleep(100000);
    }
}

int main(){
    clone(foo,cs+ss,CLONE_PARENT,0);
    for (size_t i = 0; i < 60; i++){
        printf("I'm parent\n");
        usleep(100000);
    }
    return 0;
}