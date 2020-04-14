#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>



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

int foo(void *p)
{
   print("child thread");
   return 0;
}
int foo2(void *p)
{
   print("second child thread");
   return 0;
}

int main(){
    clone(foo,cs+ss,CLONE_PARENT,0,0);
    clone(foo2,cs+ss,CLONE_PARENT,0,0);
    print("parent");
    return 0;
}