#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct{
    int len;
    int Digi_max;
    int *arr;
}DynamicArray;

//initialize the list

void init(DynamicArray *array){
    array->arr=NULL;
    array->Digi_max=1;
    array->len=1;
}

//initial memory allocation to list

void create(DynamicArray *Array,int len_m,int digi){
    Array->arr=(int*)malloc((len_m)*sizeof(int));
    if(Array->arr==NULL){
        printf("Allocation Failed");
        return;
    }
    Array->len=len_m;
    Array->Digi_max=digi;
}

//expand if the list is full

void expand(DynamicArray *Array,int new_len,int n_digi){
    if(Array->len<new_len){
        int *temp=realloc(Array->arr,2*new_len*sizeof(int));
        if(temp==NULL){
        printf("Re-allocation Failed");
        return;                                     //need to add failure case
        }
        Array->arr=temp;
        Array->len=new_len;
        Array->Digi_max=n_digi;
    }
}

int DigiCheck(int num){
    int digi=0;
    while(num){
        digi++;
        num/=10;
    }
    return num;
}

//clears the buffer of a invalid output
void BufferClear(){
    int x;
    while(x=getchar()!='\n'&&x!=EOF);
}

//render the array in real time
void render(DynamicArray *array){
    //  _     _
    // | 2 2 5 |
    // | 8 9 6 |
    // |_1 4 9_|


    printf("_");
    int a=0,b=0;
    for(int i=0;i<array->len;i++){
        if(array->arr[i]!=INT_MIN){
            a++;
        }
        else if(array->arr[i]==INT_MIN){
            if(a>b){
                b=a;
                a=0;
            }

        }
    }

    int b1=b;
    while(b1){
        printf(" ");
        b1--;
    }
    printf("_\n");

    for(int i=0;;i++){
        if(array->arr[i]!=INT_MIN && i<=array->len){
            printf("%d ",array->arr[i]);
        }
        else{
            if(i<=array->len){
                break;
            }
            printf("\n");
        }
    }
    printf("|_");
    while(b){
        printf(" ");
        b--;
    }
    printf("_|\n");

}



DynamicArray* DynamicMatrix(){
    int n=-1;
    DynamicArray *array = (DynamicArray*)malloc(sizeof(DynamicArray));
    if (array == NULL) return NULL;
    init(array);
    create(array,10,1);

    for(int i=0;;i++){
        if(scanf("%d",&n)!=1){
            char c=getchar();
            if(c=='x')return array;                           //input over
            else if(c=='r'){
               array->arr[i]=INT_MIN;                         //row change
            }
            else{
                i--;
                BufferClear();
            }
        }
        else{
            if(i<array->len){
                array->arr[i]=n;
                render(array);
            }
            else{
                expand(array,i,DigiCheck(n));
                array->arr[i]=n;
                render(array);
            }
        }
    }
}

void main(){
    DynamicMatrix();
}