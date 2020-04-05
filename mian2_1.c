#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>


int main(){
    pid_t pid = fork();
    if (pid == 0){ //child
        pid_t pid2 = fork();
        if (pid2 == 0){ //childe child
            for (size_t i = 0; i < 60; i++){
                printf("I'm child's child\n");
                usleep(100);
            }
        }
        else{ // child
            for (size_t i = 0; i < 60; i++){
                printf("I'm child\n");
                usleep(100);
            }
        }
    }
    else{ // parent
        for (size_t i = 0; i < 60; i++){
            printf("I'm parent\n");
            usleep(100);
        }
        
    }
    return 0;
}