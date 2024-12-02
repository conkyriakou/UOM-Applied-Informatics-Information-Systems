#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

int Fibonacci(int n);

 int main (){
 int N,num1,num2,n_oros;

 printf("Dwse to n:");
 N=GetInteger();

 printf("%d\n",Fibonacci(N));
 num1=0;
 num2=1;
 n_oros=num1+num2;

 printf("%5d\n",num1);
 printf("%5d\n",num2);
 printf("%5d\n",n_oros);

 for(int i=3; i<=N; i++){
    num1=num2;
    num2=n_oros;
    n_oros=num1+num2;
    printf("%5d\n",n_oros);
 }
 return 0;
 }

int Fibonacci(int n){
int i1=0,i2=0,n_oros;
n_oros=i1+i2;

for(int i=3 ;i<=n;i++){

    i1=i2;
    i2=n_oros;
    n_oros=i1+i2;
}

return n_oros;
}
