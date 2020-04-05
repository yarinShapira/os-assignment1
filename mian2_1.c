#include <sys/types.h>
#include <stdio.h>


int main(){
    pid_t pid = fork();
    if (pid == 0){ //childe
        pid_t pid2 = fork();
        if (pid2 == 0){ //childe childe
            for (size_t i = 0; i < 60; i++){
                printf("I'm childe's childe");
                usleep(1000000);
            }
        }
        else{ // childe
            for (size_t i = 0; i < 60; i++){
                printf("I'm childe");
                usleep(1000000);
            }
        }
    }
    else{ // parent
        for (size_t i = 0; i < 60; i++){
            printf("I'm parent");
            usleep(1000000);
        }
        
    }
    return 0;
}