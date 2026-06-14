#include <stdio.h>

int main(){
    //learning integer overflow and loop behaviour to such
    unsigned i=500;

    //loop stuck in a infinite loop between the max_int and 0

    while(i++!=0){while(i--!=0);};
    printf("%d",i);
    return 0;
}
    //need to press ^C in terminal