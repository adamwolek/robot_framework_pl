#include <Arduino.h>
#include "function.h"
#include "Dioda.h"
#include "Wysylacz.h"
#include "Serwomechanizm.h"
#include "Przycisk.h"
#include "CzujnikOdleglosci.h"
#include "Stoper.h"
#include "Silnik.h"
#include "WykrywaczObecnosci.h"

Wysylacz wysylacz;
Stoper stoper;
extern Silnik lewySilnik(2, 3, 4, Silnik::Polaryzacja::LEFT);
Silnik prawySilnik(5, 6, 7, Silnik::Polaryzacja::RIGHT);
CzujnikOdleglosci czujnikOdleglosci(8, 9);
Serwomechanizm serwo(10);
Dioda czerwonaDioda(11);
Przycisk przycisk(12);
WykrywaczObecnosci lewyWykrywacz(A0);
WykrywaczObecnosci prawyWykrywacz(A1);

void setup() {


}

void loop() {
    czerwonaDioda.zapal();
    poczekaj(2);
    czerwonaDioda.zgas();
    poczekaj(0.5);


    
}