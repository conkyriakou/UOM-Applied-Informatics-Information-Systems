#include<stdio.h>
#include"genlib.h"
#include"simpio.h"
int menu();
double value(int num,double aksia);

int main(){
double aksia,amount;
int choice;
do{
    choice=menu();
    if(choice==0) break;
        printf("Dwse poso se euro:");
        amount=GetReal();

        aksia=value(choice,amount);
        printf("value %g\n",aksia);
}while(choice!=6);

return 0;
}
int menu(){
    int num;
printf("1. Metetroph se dollaria\n"
       "2. Metatroph se lires \n"
       "3. Metatroph se fraga Elbetias \n"
       "4. Metatroph se dollaria Canada \n"
       "5. Metatroph se gien \n"
       "6. Exodos \n");
       num=GetInteger();
       return num;
}
double value(int choice, double amount){
double aksia;

if(choice==1)
     aksia=amount*0.89;
else if(choice==2)
    aksia=amount*0.618;
else if(choice==3)
    aksia=amount*1.5465;
else if(choice==4)
    aksia=amount*1.3565;
else if(choice==5)
    aksia=amount*109.22;

return aksia;
}
