#include <stdio.h>

int main()
{
    char ch1;
    char ch2;
    scanf("%c",&ch1);
    //fflush(stdin);          //διαγράφει οτιδήποτε έχει παραμείνει στο ρεύμα εισόδου. Δε προτείνεται η χρήση της
    while ((getchar()) != '\n');    ////διαγράφει οτιδήποτε έχει παραμείνει στο ρεύμα εισόδου, αντί της fflush(stdin)
    scanf("%c",&ch2);
    printf("ch1=%c, ch2=%c\n",ch1,ch2);
}
