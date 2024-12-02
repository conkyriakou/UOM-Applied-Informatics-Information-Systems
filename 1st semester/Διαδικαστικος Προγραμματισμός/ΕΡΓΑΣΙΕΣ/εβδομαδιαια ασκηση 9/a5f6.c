#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
#define size 100
void inputArray(int n,int tab[]);
void inputNumbers(int *a,int *b);
void performCaclulations(int n, int tab[],int *a,int *b,int *pl1,int *pl2,int *pl3);
void ShowResults(int n,int tab[],int *a,int *b,int *pl1,int *pl2,int *pl3);
int main(){
int tab[size],n,i,pl1,pl2,pl3,a,b;
printf("Give n: ");
n=GetInteger();
inputArray(n,tab);
inputNumbers(&a,&b);
performCaclulations(n,tab,&a,&b,&pl1,&pl2,&pl3);
ShowResults(n,tab,&a,&b,&pl1,&pl2,&pl3);
return 0;
}
void inputArray(int n,int tab[]){
int i;
  for(i=0;i<n;i++){
    printf("Give element[%d]: ",i);
      tab[i]=GetInteger();
     }
}
void inputNumbers(int *a,int *b){
    printf("Give A: ");
    *a=GetInteger();
    printf("Give B: ");
    *b=GetInteger();
}
void performCaclulations(int n, int tab[],int *a,int *b,int *pl1,int *pl2,int *pl3){
int i;
     for(i=0;i<n;i++){
        if(tab[i]<=*a)
            (*pl1)++;
        if(tab[i]>=*b)
            (*pl2)++;
        if(tab[i]>*a && tab[i]<*b)
            (*pl3)++;
     }
}
void ShowResults(int n,int tab[],int *a,int *b,int *pl1,int *pl2,int *pl3){
    int i;
    printf("\n");
    printf("----The numbers of the array-----\n");
    for(i=0;i<n;i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
    printf("A = %d\n",*a);
    printf("B = %d\n",*b);
    printf("Numbers smaller or equal to A: %d\n",*pl1);
    printf("Numbers bigger or equal to B: %d\n",*pl2);
    printf("Numbers bigger than A and smaller than B: %d\n",*pl3);
}
