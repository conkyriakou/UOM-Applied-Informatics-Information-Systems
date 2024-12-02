#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

 int main(){
 int code,pagio;
 long present_indication_of_cash,previous_indication_of_cash,power_consumption,current_value;
 double fpa,totalamount;

 printf("Dwse ton kwdiko kathgorias timologiou:\n");
 code=GetInteger();

 printf("Dwse thn parousa endeixh toy metrhth:\n");
 present_indication_of_cash=GetLong();

 printf("Dwse thn prohgoumenh endeixh toy metrhth:\n");
 previous_indication_of_cash=GetLong();

 power_consumption=present_indication_of_cash-previous_indication_of_cash;
 printf("Katanalwsh reumatos se monades: %ld\n",power_consumption);

 if(power_consumption>=1 && power_consumption<=200){
    current_value=power_consumption*12;

 }else if(power_consumption>=201 && power_consumption<=500){
        current_value=power_consumption*15;

 }else if(power_consumption>=501 && power_consumption<=1500){
     current_value=power_consumption*20;

 }else if(power_consumption>=1501 && power_consumption<=10000){
     current_value=power_consumption*30;
 }
 printf("Axia reumatos (cent):%ld \n",current_value);
 if(code==1 || code==2)
    pagio=20;
 else
    pagio=100;
 printf("Pagio (eyro): %d\n",pagio);

 fpa=(pagio+(current_value/100))*0.18;
 printf("FPA (euro): %g \n",fpa);

 totalamount=fpa+(current_value/100)+pagio;
 printf("Synoliko poso plhrwmhs (euro): %g\n",totalamount);
 return 0;
 }
