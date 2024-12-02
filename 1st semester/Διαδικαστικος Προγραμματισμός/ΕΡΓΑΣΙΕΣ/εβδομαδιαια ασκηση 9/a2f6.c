#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
#define msize 100
void readData(int size,int tab[],int *pl);
void findMinMax(int tab[],int *pl,int *max,int *min);
int main(){
int tab[msize],pl,max,min;
printf("Enter the elements of the array, one per line.\n");
printf("Use -1 to signal the end of the list.\n");
readData(msize,tab,&pl);
findMinMax(tab,&pl,&max,&min);
printf("The range of values is %d-%d",min,max);
return 0;
}
void readData(int size,int tab[],int *pl){
int i,num;
*pl=0;
for(i=0;i<size;i++){
        printf("? ");
        num=GetInteger();
        if(num==-1)
            break;
        else
            tab[i]=num;
            (*pl)++;
    }
}
void findMinMax(int tab[],int *pl,int *max,int *min){
int i;
*max=tab[0];
*min=tab[0];
for(i=1;i<*pl;i++){
    if(tab[i]>*max){
        *max=tab[i];}
    if(tab[i]<*min){
        *min=tab[i];
    }
}
}
