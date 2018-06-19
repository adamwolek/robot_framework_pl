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
Silnik lewySilnik(5, 6, 10, Silnik::Polaryzacja::RIGHT);
Silnik prawySilnik(7, 8, 9, Silnik::Polaryzacja::RIGHT);
CzujnikOdleglosci czujnikOdleglosci(4, 3);
// Serwomechanizm serwo(10);
// Dioda czerwonaDioda(11);
// Przycisk przycisk(12);
WykrywaczObecnosci lewyWykrywacz(A1);
WykrywaczObecnosci prawyWykrywacz(A0);

void setup() {
    lewySilnik.hamuj();
    prawySilnik.hamuj();
}


void loop() {
   
    
}

