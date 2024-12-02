#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

int main(){
long yposo,fklimakas,poso,diff;
yposo=GetLong();
printf("%ld Euro\n",yposo);

if(yposo>0 && yposo<=10000){
   poso=0;

}
else if(yposo<=39000){
    fklimakas=0;
    diff=(yposo-10000)*0.18;
    poso=fklimakas+diff;
}
else if(yposo<=49000){
    fklimakas=5220;
    diff=(yposo-39000)*0.21;
    poso=fklimakas+diff;
}
else if(yposo<=59000){
    fklimakas=7320;
    diff=(yposo-49000)*0.24;
    poso=fklimakas+diff;
}
else if(yposo<=85000){
    fklimakas=9720;
    diff=(yposo-59000)*0.28;
    poso=fklimakas+diff;
}
else if(yposo<=100000){
    fklimakas=17000;
    diff=(yposo-85000)*0.33;
    poso=fklimakas+diff;
}
else if(yposo<=120000){
    fklimakas=21950;
    diff=(yposo-100000)*0.38;
    poso=fklimakas+diff;
}
else if(yposo<=150000){
    fklimakas=29550;
    diff=(yposo-120000)*0.43;
    poso=fklimakas+diff;
}
else if(yposo<=170000){
    fklimakas=42450;
    diff=(yposo-150000)*0.49;
    poso=fklimakas+diff;
}
else {
    fklimakas=52250;
    diff=(yposo-170000)*0.5;
    poso=fklimakas+diff;
}
printf("%ld Euro\n",fklimakas);
printf("%ld Euro\n",diff);
printf("%ld Euro\n",poso);
return 0;
}
