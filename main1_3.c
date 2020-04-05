#include <dlfcn.h>
#include <stdio.h>

void (*f)();

int main(){
    void *hdl = dlopen("./libhello_Ariel.so",RTLD_LAZY);
    if (hdl == NULL){
        printf("Library was not loaded\n");
    }
    else{
    f = (void(*)(const char *))dlsym(hdl,"helloAriel");
    f();
    }
    return 0;
}