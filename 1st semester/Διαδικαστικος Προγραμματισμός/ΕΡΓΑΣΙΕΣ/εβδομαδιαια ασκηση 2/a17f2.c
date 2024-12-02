#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

 int main(){
 int plithos=0,number_of_passengers;

 printf("Dwse theseis:\n");
 plithos=GetInteger();

 printf("Dwse epibates: \n");
 number_of_passengers=GetInteger();

 if(plithos >= number_of_passengers*0.5)
    printf("Kerdos");
 else if(plithos <number_of_passengers*0.3 )
    printf("Zimia");
 else
    printf("Kostos");
 return 0;
 }
