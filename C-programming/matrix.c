#include <stdio.h>


int render(int arr[],int size,int row_len){
    //>>({3,4,6,2,7,4,2,3,5},9,3)
    // _     _
    //| 3 4 6 |
    //| 2 7 4 | 
    //|_2 3 5_|

    int row=1,gap=0,last_row=0;
    last_row=size-row_len;

    printf("\n\n\n\n _");
    while (gap<(row_len*2-1)){
        printf(" ");
        gap++;
    } 
    printf("_\n|");

    for(int i=0;i<size;i++){
        
        if(i<=(row*row_len-1)){
            if(i==last_row){
                printf("_%d",arr[i]);
            }
            else{
                printf(" %d",arr[i]);
            }
        }
        else{
            row++;
            i--;
            printf(" |\n|");
        }

    }
    printf("_|\n\n");

}




int buffer_reset(){
    int c;
    while((c=getchar())!='\n' && c!=EOF);
}

int input_mat(){
    int n=-1,row=0,c=0;
    int r[9]={0};
    printf("Enter your Matrix,\nNext row->'r'\nFinish->'x'\n");

    while (c<9)
    {
        if((scanf("%d",&n))!=1){
            char t=getchar();
            if(t=='x' && getchar()=='\n')break;
            else if(t=='r' && getchar()=='\n'){
                row=1;
                printf("%d\n",row);
                buffer_reset();
                continue;
            }
            else {
                printf("oops pls enter numbers\n");
                buffer_reset();
            }
        }
        else{
            r[c]=n;
            render(r,sizeof(r)/sizeof(int),3);
            c++;
        }
    }
    if(c!=9){
        while(c<9){
            r[c]=0;
        }
    }
     render(r,sizeof(r)/sizeof(int),3);
}



int main(){
    input_mat();

}