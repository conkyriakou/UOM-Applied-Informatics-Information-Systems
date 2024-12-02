#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

 int main(){
int N;
float sum=0;
printf("Dwse orio:");
N=GetInteger();

for(int i=1;i<=N;i++){

    sum+=(float)1/i;

}

 printf("To athroisma einai %.2f",sum);
 return 0;
 }
