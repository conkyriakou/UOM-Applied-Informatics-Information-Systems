#include<stdio.h>
#include<stdlib.h>
#include"simpio.h"
#include"genlib.h"
void decompose(long num,int *plhthos,double *avg,long *maxdigit);
int main(){
long num,maxdigit;
double avg;
int plhthos;

printf("Please insert non-negative number:");
num=GetLong();
decompose(num, &plhthos, &avg, &maxdigit);
printf("Digits: %d \n",plhthos);
printf("Average: %.3lf\n",avg);
printf("Max: %ld\n",maxdigit);
return 0;}
void decompose(long num,int *plhthos,double *avg,long *maxdigit){
int i=0;
int *n;
long k=num;
double sum=0.00;
*plhthos=0;
*avg=0;
    while((k%10)>0){
        k=k/10;
        (*plhthos)++;
        }
        n=(int *)malloc((*plhthos)*sizeof(int));
        for(i=0;i<*plhthos;i++){
            n[i]=num%10;
            num=num/10;
        }
        for(i=0;i<*plhthos;i++){
            sum+=n[i];}
          *avg=sum/(*plhthos);
          *maxdigit=0;
        for(i=0;i<*plhthos;i++){
            if(n[i]>*maxdigit){
                *maxdigit=n[i];}
        }

}
