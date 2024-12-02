#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

int main(){
int M1,N1,M2,N2,i,j,k;
printf("Dwse to plithos twn grammwn m1: ");
M1=GetInteger();
printf("Dwse to plithos twn sthlwn n1: ");
N1=GetInteger();
printf("Dwse to plithos twn grammwn m2: ");
M2=GetInteger();
printf("Dwse to plithos twn sthlwn n2: ");
N2=GetInteger();
long A[M1][N1],B[M2][N2],sum[M1][N1],diff[M1][N1],product[M1][N2];
    for( i=0;i<M1;i++){
        for(j=0;j<N1;j++){
            A[i][j]=GetLong();
        }
    }
    for(i=0;i<M2;i++){
        for(j=0;j<N2;j++){
            B[i][j]=GetLong();
        }
    }
if(M1==M2 && N1==N2){
for( i=0;i<M1;i++){
    for(j=0;j<N1;j++){
        for(i=0;i<M2;i++){
            for(j=0;j<N2;j++){
                sum[i][j]=A[i][j]+B[i][j];
                printf("%ld   \t",sum[i][j]);
                diff[i][j]=A[i][j]-B[i][j];
                printf("%ld  \t ",diff[i][j]);
                    }
                    printf("\n");
                }printf("\n");
                }
            }
        }
        else {
            printf("ERROR +\n");
            printf("ERROR -\n");
}
for( i=0;i<M1;i++){
    for(j=0;j<N1;j++){
        for(i=0;i<M2;i++){
            for(j=0;j<N2;j++){
                   product[i][j]=0;
                   for(int a=0;a<N2;a++)
                   product[i][j]+=A[i][a]*B[a][j];

            }
            }
        }
    }

if(N1==M2){
for( i=0;i<M1;i++){
    for(j=0;j<N2;j++){
            printf("%ld \t ",product[i][j]);
                }printf("\n");
    }
}
else
    printf("ERROR *\n");
return 0;
}
