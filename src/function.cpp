#include"function.h"
#include<Arduino.h>

void poczekaj(double ileSekund){
    delay((int)round(ileSekund*1000));
}

double aktualnyCzas(){
    return millis()/(double)1000;
}