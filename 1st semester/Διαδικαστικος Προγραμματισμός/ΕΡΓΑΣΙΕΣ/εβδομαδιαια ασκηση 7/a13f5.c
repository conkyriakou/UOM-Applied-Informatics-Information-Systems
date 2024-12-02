#include<stdio.h>
#include"genlib.h"
#include"simpio.h"
#include"stdlib.h"
void populate_data(int row,int col,int A[row][col]);
void print_array(int row,int col,int A[row][col]);
void change_array(int row,int col ,int A[row][col]);
int main(){
int R,C;
printf("Dwse ton arithmo twn grammwn: ");
R=GetInteger();
printf("Dwse ton arithmo twn sthlwn: ");
C=GetInteger();
int A[R][C],maxk[R][C];
populate_data(R,C,A);
printf("ARXIKOS PINAKAS\n");
print_array(R,C,A);
printf("ALLAGMENOS PINAKAS\n");
change_array(R,C,A);
return 0;}
void populate_data(int row,int col,int A[row][col]){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            A[i][j]=(rand()%100);
        }
    }
}
void print_array(int row,int col,int A[row][col]){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
           printf("%d \t",A[i][j]);
        }
        printf("\n");
    }
}
void change_array(int row,int col ,int A[row][col]){
int maxk,index;
    for(int i=0;i<row;i++){
        maxk=A[i][0];
        index=0;
        for(int j=0;j<col;j++){
            if(maxk<A[i][j]){
                maxk=A[i][j];
                index=j;
        }
        }
        for(int j=0;j<index;j++){
            A[i][j]=maxk;
        }
    }
for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d \t",A[i][j]);}
        printf("\n");
        }
}
