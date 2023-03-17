#include <stdio.h>
#include <stdlib.h>
 struct dynamic_array
    {
        int *arr;
        int space;
        int len;
    };
void* append(struct dynamic_array*array,int element){
    if(array->len==array->space){
        int* new_array=(int*)malloc((array->space)*2*sizeof(int));
        for(int i=0;i<array->len;i++){
            new_array[i]=array->arr[i];
        }
        free(array->arr);
        array->arr=new_array;
        array->space= array->space*2;
    }
    array->arr[array->len]=element;
    array->len+=1;

}
int poplast(struct dynamic_array*array){
   int last=array->arr[array->len-1];
   array->len+=-1;
   return last;
}
int popfirst(struct dynamic_array*array){
    int first=array->arr[0];
    array->len+=-1;
    array->arr=array->arr+1;
    return first;
}
struct queue{
    
}

int main(){
    struct dynamic_array array;
    array.arr=(int*)malloc(5*sizeof(int));
    array.len=2;
    array.space=5;
    array.arr[0]=0;
    array.arr[1]=1;
    for(int i =2;i<1000;i++)
    {
    append(&array,i);
    }
    for(int i = 0;i<1000;i++){
        printf("%d",array.arr[i]);
    }

    return 0;
}
 