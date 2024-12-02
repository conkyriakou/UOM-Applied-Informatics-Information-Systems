#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

int main(){
    int coffees,poso,changes,e1,e2,e50,e20,e10;

    printf("Dwse kafedes:\n");
    coffees=GetInteger();

    poso=coffees*70;
    changes=500-poso;

    if(changes>0){
        printf("Resta\n");

        e2=changes/200;
        changes%=200;

        e1=changes/100;
        changes%=100;

        e50=changes/50;
        changes%=50;

        e20=changes/20;
        changes%=20;

        e10=changes/10;
        changes%=10;

        printf("2E:%d\n",e2);
        printf("1E:%d\n",e1);
        printf("50L:%d\n",e50);
        printf("20L:%d\n",e20);
        printf("10L:%d\n",e10);
    }
    else
        printf("Sfalma");

return 0;
}
