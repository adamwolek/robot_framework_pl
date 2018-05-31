#include <Arduino.h>

class Wysylacz{
    public:
        Wysylacz();
        void wyslij(String wiadomosc);
        String poczekajNaWiadomoscIZwroc();
};


Wysylacz::Wysylacz(){
    Serial.begin(115200);
}

void Wysylacz::wyslij(String wiadomosc){
    Serial.println(wiadomosc);
}

String Wysylacz::poczekajNaWiadomoscIZwroc(){
    String wiadomosc = Serial.readStringUntil('\n');
    return wiadomosc;
}