#include<stdio.h>
#include"genlib.h"
#include"simpio.h"
int input(int size);
void table(int size,long a[]);
void print_t(int size,long a[]);
int FindMaxPos(int size, long a[],int index[]);
int main(){
int i,N,plhthos,index[plhthos];
long a[50];

printf("Dwse to plhthos twn stoixeiwn:");
N=input(N);

table(N,a);
print_t(N,a);

plhthos=FindMaxPos(N,a,index);
printf("Plithos maximum %d\n",plhthos);

printf("Positions of maximum  ");
for(i=0;i<plhthos;i++)
    printf("%d ",index[i]);
return 0;
}
int input(int size){
size=GetInteger();
return size;
}
void table(int size,long a[]){
    int i;
    for(i=0;i<size;i++){
        a[i]=GetLong();
    }
}
void print_t(int size,long a[]){
    int i;
    for(i=0;i<size;i++){
        printf("%ld ",a[i]);
    }printf("\n");
}
int FindMaxPos(int size, long a[size],int index[]){
    int i,plhthos,maxth,point;
    long max;
    max=a[0];
    plhthos=0;
    maxth=0;
    for(i=0;i<size;i++){
        if(a[i]>max){
           max=a[i];
           maxth=i;
           plhthos=1;
           point=0;
           index[point]=i;
           }
        else if(a[i]==max){
           point+=1;
           index[point]=i;
           plhthos+=1;

        }
    }

    printf("maximum %ld \n",max);
    return plhthos;
}
