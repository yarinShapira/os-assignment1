#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>


int main(){
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