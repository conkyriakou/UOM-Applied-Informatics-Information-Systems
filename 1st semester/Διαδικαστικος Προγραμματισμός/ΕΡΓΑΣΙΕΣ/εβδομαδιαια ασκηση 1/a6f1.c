#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

int main(){

int workdaysinayear;
long hmerhsiaamoibi;
double pososto,dwro;
 printf("Dwse tis hmeres ergasias tou etous:\n");
  workdaysinayear=GetInteger();
 printf("Dwse thn hmerhsia amoibh:\n");
  hmerhsiaamoibi=GetLong();
 printf("Dwse to pososto dwroy:\n");
  pososto=GetReal();
   dwro=round(workdaysinayear*hmerhsiaamoibi*pososto);
 printf("To dwro einai%g",dwro);
return 0;
}
