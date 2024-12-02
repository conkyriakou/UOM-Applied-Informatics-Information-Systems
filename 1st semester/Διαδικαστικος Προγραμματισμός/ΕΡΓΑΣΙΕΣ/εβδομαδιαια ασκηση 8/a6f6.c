#include<stdio.h>
#include"simpio.h"
#define N 5
#define C 4

void readData(int n,int c ,int data[n][c]);
void FindMean(int n,int c,int data[n][c],double *w_avg_m,double *h_avg_m,double *a_avg_m,double *w_avg_w,double *h_avg_w,double *a_avg_w);

int main(){
int data[N][C];
double weight_avg_men,height_avg_men,age_avg_men,weight_avg_women,height_avg_women,age_avg_women;
readData(N,C,data);
FindMean(N,C,data,&weight_avg_men,&height_avg_men,&age_avg_men,&weight_avg_women,&height_avg_women,&age_avg_women);
printf("Mesos oros barous andrwn: %.1lf\n",weight_avg_men);
printf("Mesos oros barous gynaikwn: %.1lf\n",weight_avg_women);
printf(" \n");
printf("Mesos oros ypsous andrwn: %.1lf\n",height_avg_men);
printf("Mesos oros ypsous gynaikwn: %.1lf\n",height_avg_women);
printf(" \n");
printf("Mesos oros hlikias andrwn: %.1lf\n",age_avg_men);
printf("Mesos oros hlikias gynaikwn: %.1lf\n",age_avg_women);
return 0;}
void readData(int n,int c,int data[n][c]){
int i,j,g,w,h,a;
for(i=0;i<n;i++){
    printf("Dwse fylo:");
    g=GetInteger();
    printf("Dwse baros:");
    w=GetInteger();
    printf("Dwse ypsos:");
    h=GetInteger();
    printf("Dwse ilikia:");
    a=GetInteger();
    printf("-----\n");
    for(j=0;j<c;j++){
        data[i][0]=g;
        data[i][1]=w;
        data[i][2]=h;
        data[i][3]=a;
    }
    }
}
void FindMean(int n,int c, int data[n][c],double *w_avg_m,double *h_avg_m,double *a_avg_m,double *w_avg_w,double *h_avg_w,double *a_avg_w){
   int i,j,plm=0,plw=0;
   *w_avg_m=0;
   *h_avg_m=0;
   *a_avg_m=0;
   *w_avg_w=0;
   *h_avg_w=0;
   *a_avg_w=0;
    for(i=0;i<n;i++){
        for(j=0;j<c;j++){
            if(data[i][0]==0){
               *w_avg_m+=data[i][1];
               *h_avg_m+=data[i][2];
               *a_avg_m+=data[i][3];
               plm++;
            }
            if(data[i][0]==1){
                *w_avg_w+=data[i][1];
                *h_avg_w+=data[i][2];
                *a_avg_w+=data[i][3];
                plw++;
            }
        }
    }
   *w_avg_m=*w_avg_m/plm;
   *h_avg_m=*h_avg_m/plm;
   *a_avg_m=*a_avg_m/plm;
   *w_avg_w=*w_avg_w/plw;
   *h_avg_w=*h_avg_w/plw;
   *a_avg_w=*a_avg_w/plw;
}


