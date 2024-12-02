#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

int main(){
long eispraxeis04,eispraxeis08,eispraxeis18;
double synolikoposo;
 printf("Dwse tis synolikes eispraxeis gia FPA 0.04:\n");
  eispraxeis04=GetLong();
 printf("Dwse tis synolikes eispraxeis gia FPA 0.08:\n");
  eispraxeis08=GetLong();
 printf("Dwse tis synolikes eispraxeis gia FPA 0.18:\n");
  eispraxeis18=GetLong();
  synolikoposo=(0.04*eispraxeis04)+(0.08*eispraxeis08)+(0.18*eispraxeis18);
 print("To synoliko poso FPA einai %g\n",synolikoposo);
return 0;
}
