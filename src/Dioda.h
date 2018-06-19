#include<Arduino.h>

class Dioda{
private:
    int pin;
    bool currentState;
public:
    Dioda(int pin);
    ~Dioda();

    void zapal();
    void zgas();
    bool czyZapalona();
};


Dioda::Dioda(int pin)
{
    this->pin = pin;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    currentState = LOW;
}

Dioda::~Dioda()
{
}

void Dioda::zapal(){
    digitalWrite(pin, HIGH);
    currentState = HIGH;
}

void Dioda::zgas(){
    digitalWrite(pin, LOW);
    currentState = LOW;
}

bool Dioda::czyZapalona(){
    return currentState;
}

