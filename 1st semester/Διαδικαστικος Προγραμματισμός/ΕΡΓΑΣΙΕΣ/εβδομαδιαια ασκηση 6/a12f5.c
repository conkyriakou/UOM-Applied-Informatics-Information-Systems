#include<stdio.h>
#include"simpio.h"

int main(){
int M,N,i,j;
double marks[30][10],marks2[30][10],sum,sum2;

printf("Dwse ton arithmo twn mathitwn: ");
M=GetInteger();
printf("Dwse ton arithmo twn thematwn: ");
N=GetInteger();
for( i=0;i<M;i++){
    for(  j=0;j<N;j++){
        printf("Dwse th bathmologia tou %dou thematos tou %dou mathiti:",j+1,i+1);
        marks[i][j]=GetReal();
    }
}
for( i=0;i<M;i++){
sum=0;
sum2=0;
    for(  j=0;j<N;j++){
    sum+=marks[i][j];
    printf("%6.1lf",marks[i][j]);
    marks2[i][j]=marks[i][j]/5;
    sum2+=marks2[i][j];
    }
    printf("%6.1lf\n",sum/N);
    for(  j=0;j<N;j++){
       printf("%6.1lf",marks2[i][j]);
    }
    printf("%6.1lf\n",sum2/N);
}
system("Pause");
return 0;}
