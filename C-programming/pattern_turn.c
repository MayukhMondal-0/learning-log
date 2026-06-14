#include <stdio.h>

int main(){
    
    //   *
    //  ***
    // *****
    //*******

    int z=1;
    while(z){
        int a,b=1,i=1,j,c;
        scanf("%d",&a);
        c=a-1;j=c;
        (a==0)?(printf(":)"),z--):0;
        while(c>=0){
            (j>0)?(printf(" "),j--):((i<=b)?(printf("*"),i++):(printf("\n"),b+=2,i=1,c--,j=c));
        }

    }
    return 0;
}
