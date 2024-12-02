#include<stdio.h>
#include"simpio.h"

typedef struct boxes{
    int width;
    int height;
    int depth;
    int area;
    int valume;

}box;

void get_data(box *a_box);
void calc_box_area(box *a_box);
void calc_box_valume(box *a_box);

int main(){
    box a_box;
    get_data(&a_box);
    calc_box_area(&a_box);
    printf("To emvadon tou koutiou einai %d cm2\n",a_box.area);
    calc_box_valume(&a_box);
    printf("O ogos tou koutiou einai %d cm3\n",a_box.valume);

return 0;
}
void get_data(box (*a_box)){
    printf("Dose to mikos tou koutiou se cm:");
    (*a_box).width=GetInteger();

    printf("Dose to ypsos tou koutiou se cm:");
    (*a_box).height=GetInteger();

    printf("Dose to vathos tou koutiou se cm:");
    (*a_box).depth=GetInteger();
}
void calc_box_area( box *a_box){
    (*a_box).area =2*(a_box->width*a_box->depth+a_box->height*a_box->depth+a_box->width * a_box->height);

}
void calc_box_valume(box *a_box){
    (*a_box).valume= a_box->width*a_box->height*a_box->depth;
}
