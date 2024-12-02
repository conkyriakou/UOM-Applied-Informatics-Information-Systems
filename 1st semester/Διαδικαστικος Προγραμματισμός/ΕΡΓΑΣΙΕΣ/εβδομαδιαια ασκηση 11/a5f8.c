#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
#define N 20

typedef struct{
    int code;
    char surname[16];
    long poso;
    int region;
    long total_region;
}peopleT;

void get_data(int count,peopleT p[]);
void calc_total(int n,int x,peopleT p[],long total[]);
void print_data(int x,long total[]);

int main(){
    int count,i;
    long total[4],k;
    for (i=1 ;i<=4 ;i++) total [i]=0;

    printf("Dwse to plhthos twn pwlhton? ");
    count=GetInteger();
    peopleT p[N];

    get_data(count , p);

    calc_total(count,1,p, total);
    k=total[1];
    printf("    PERIOXH SYN.PWLHSEWN\n");
    for(i=0;i<24;i++) printf("-");
        printf("\n");
    print_data(1, total);
    calc_total(count,2,p, total);
    k+=total[2];
    print_data(2, total);
    calc_total(count,3,p, total);
    k+=total[3];
    print_data(3, total);
    calc_total(count,4,p, total);
    k+=total[4];
    print_data(4, total);

    for(i=0;i<24;i++) printf("-");
        printf("\n");
    printf ("     SYNOLO: %11ld \n", k) ;
return 0;}

void get_data(int count ,peopleT p[]){
    int i;

    for(i=1;i<=count;i++){
        printf("Kwdikos? ");
        p[i].code=GetInteger();

        printf("Onomatepwnymo? ");
        gets(p[i].surname);

        printf("Poso pwlhseon? ");
        p[i].poso=GetLong();

        printf("Kwdikos (1= Thes/niki, 2= Athens, 3= Volos, 4= Hrakleio)? ");
        p[i].region=GetInteger();
    }

}
void calc_total(int n,int x,peopleT p[],long total[]){
    int i;
    for(i=1;i<=n;i++){
        if(p[i].region==x)
            total[x]+=p[i].poso;}
}
void print_data(int x,long total[]){
    if(x==1)
        printf("   Thes/niki %11ld\n",total[x]);
    if(x==2)
        printf("      Athens %11ld\n",total[x]);
    if(x==3)
        printf("       Volos %11ld\n",total[x]);
    if(x==4)
        printf("    Hrakleio %11ld\n",total[x]);

}
