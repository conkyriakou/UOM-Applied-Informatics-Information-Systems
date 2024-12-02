#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

 int main(){
 int poso,pl=0,max=0,min=100000,total=0;

 do{
   printf("Dwse poso :");
   poso=GetInteger();

   total+=poso;
   pl++;

   if(poso>max){
    max=poso;
   }

   if(poso<min){
    min=poso;

   }

 }while(total<100000);

  printf("Plithos atomon: %d\n",pl);
  printf("Synoliko poso : %d\n",total);
  printf("Megalitero poso: %d  Mikrotero poso:%d ",max,min);


 return 0;
 }

