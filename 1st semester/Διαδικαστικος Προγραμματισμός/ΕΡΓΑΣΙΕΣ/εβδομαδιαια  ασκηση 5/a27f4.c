#include<stdio.h>
#include"genlib.h"
#include"simpio.h"
long encode(long N);
bool check(long EN);

int main(){
    long n1,n2,N,EN,i;

    printf("Lower Limit:");
    n1=GetLong();
    printf("Upper Limit:");
    n2=GetLong();

    for(i=n1;i<=n2;i++){

        EN=encode(i);
        if(check(EN)==TRUE)
            printf("Code: %d  Encoding: %ld  isValid:yes \n",i,EN);
        else
            printf("Code: %d  Encoding: %ld  isValid:no \n",i,EN);
        }
return 0;
}
long encode(long N){
    long digits;

    digits=(98-(N*100)%97)%97;
    return N*100+digits;
}
bool check(long EN){
    if(EN%97==1)
        return TRUE;
    else
        return FALSE;

}
