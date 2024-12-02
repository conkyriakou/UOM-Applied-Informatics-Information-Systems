#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

int main(){

int N,code,gender,kg,height,age,maxcode,maxgender,maxkg,maxage,maxheight;
maxage=0;
maxcode=0;
maxheight=0;
maxgender=0;
maxkg=0;

printf("Dwse to plithos:");
N=GetInteger();

for( int i=0;i<N;i++){

   printf("Dwse to kwdiko:");
   code=GetInteger();
   printf("Dwse to fyllo:");
   gender=GetInteger();
   printf("Dwse to baros:");
   kg=GetInteger();
   printf("Dwse to ypsos:");
   height=GetInteger();
   printf("Dwse thn hlikia:");
   age=GetInteger();

if(height>maxheight && gender==0){
 maxheight=height;
 maxcode=code;
 maxgender=gender;
 maxkg=kg;
 maxage=age;

 }
}
printf("%d  %d  %d  %d  %d",maxcode,maxgender,maxkg,maxheight,maxage);
return 0;
}
