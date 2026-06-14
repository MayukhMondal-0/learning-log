#include <stdio.h>
int main(){
    
    //palindrome:
    int n,m,t=0,a=0;
    char b;
    scanf("%d",&m);
    printf("%d<=>",m);
    if(m<10){
        printf("Invalid input");
        return 0;
    }
    n=m;
    
    while((n%10)==0){
        t=1;
        printf("0");
        n/=10;
    }
    m=n;
    while(n>0){
        a=(a+(n%10))*10;
        n/=10;
    }
    a/=10;
    (a==m && t==0)?(b='+'):(b='x');

    printf("%d,%c",a,b);
}