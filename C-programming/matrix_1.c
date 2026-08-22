#include<stdio.h>

typedef struct{
    int len;
    int Dig_max;
    int *arr;
}DynamicMatrix;

void init(DynamicMatrix *arr){
    arr->Dig_max=1;
    arr->len=1;
}

void input(DynamicMatrix *Arr,int len_m,int dig){
    Arr->arr=(int*)malloc((len_m)*sizeof(int));
    Arr->len=len_m;
    Arr->Dig_max=dig;
}

void append(DynamicMatrix *Arr,int new_len){
    if(Arr->len<=new_len){
        Arr->arr=0;
    }
}