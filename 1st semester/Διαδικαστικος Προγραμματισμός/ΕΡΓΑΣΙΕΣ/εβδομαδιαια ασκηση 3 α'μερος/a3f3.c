#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

 int main(){

 long boxesin=0,boxesout,posoin,posoout,totalamount1=0,totalin=0,totalout=0,totalamount2=0;
    printf("Kibwtia eswterikou?");
    boxesin=GetLong();
    printf("Kibwtia exwterikou?");
    boxesout=GetLong();
 while(boxesin>=0 && boxesout>=0){

    posoin=boxesin*10;
    posoout=boxesout*15;
    totalamount1=posoin+posoout;

    printf("%10ld %10ld %10ld\n",posoin,posoout,totalamount1);

    totalin=totalin+posoin;
    totalout=totalout+posoout;

    printf("Kibwtia eswterikou?");
    boxesin=GetLong();
    if(boxesin>=0){
    printf("Kibwtia exwterikou?");
    boxesout=GetLong();}

 }

 totalamount2=totalin+totalout;

 printf("%10ld %10ld %10ld\n",totalin,totalout,totalamount2);
 return 0;
 }
