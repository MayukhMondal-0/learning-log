#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int len;
    int Digi_max;
    int *arr;
}DynamicArray;

void init(DynamicArray *array){
    array->arr=NULL;
    array->Digi_max=1;
    array->len=1;
}

void input(DynamicArray *Array,int len_m,int digi){
    Array->arr=(int*)malloc((len_m)*sizeof(int));
    if(Array->arr==NULL){
        printf("Allocation Failed");
        return;
    }
    Array->len=len_m;
    Array->Digi_max=digi;
}

void append(DynamicArray *Array,int new_len){
    if(Array->len<new_len){
        int *temp=realloc(Array->arr,new_len*sizeof(int));
        if(temp==NULL){
        printf("Re-allocation Failed");
        return;
        }
        Array->arr=temp;
        Array->len=new_len;
    }
}

// DynamicArray DynamicMatrix(){
// }