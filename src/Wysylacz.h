#include <Arduino.h>

class Wysylacz{
    public:
        Wysylacz();
        void wyslij(String wiadomosc);
        void wyslij(int wiadomosc);
        void wyslij(long wiadomosc);
        void wyslij(double wiadomosc);
        String poczekajNaWiadomoscIZwroc();
};


Wysylacz::Wysylacz(){
    Serial.begin(9600);
}

void Wysylacz::wyslij(long wiadomosc){
    wyslij(String(wiadomosc));
}

void Wysylacz::wyslij(double wiadomosc){
    wyslij(String(wiadomosc));
}

void Wysylacz::wyslij(int wiadomosc){
    wyslij(String(wiadomosc));
}

void Wysylacz::wyslij(String wiadomosc){
    Serial.println(wiadomosc);
}

String Wysylacz::poczekajNaWiadomoscIZwroc(){
    String wiadomosc = Serial.readStringUntil('\n');
    return wiadomosc;
}