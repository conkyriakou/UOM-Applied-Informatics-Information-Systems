#include<stdio.h>
#include"simpio.h"
#include"genlib.h"

bool Valid_Time(int hours,int minutes,int seconds);

int main(){
int hours, minutes, seconds;

printf("Dwse tis wres: ");
hours=GetInteger();
printf("Dwse ta lepta: ");
minutes=GetInteger();
printf("Dwse ta defterolepta: ");
seconds=GetInteger();
if(Valid_Time(hours,minutes,seconds)==TRUE)
    printf("Valid: yes");
else
    printf("Valid: no");
return 0;
}
bool Valid_Time(int hours,int minutes,int seconds){
    if(hours>=0 && hours<=23 && minutes>=0 && minutes<=59 && seconds>=0 && seconds<=59)
        return TRUE;
    else
        return FALSE;
}
