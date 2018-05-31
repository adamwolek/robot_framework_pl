#include <Arduino.h>


class Przycisk
{
private:
    int pin;
public:
    Przycisk(int pin);
    ~Przycisk();
    bool czyPrzyciskJestNacisniety();
};

bool Przycisk::czyPrzyciskJestNacisniety(){
    return !digitalRead(pin);
}

Przycisk::Przycisk(int pin)
{
    this->pin = pin;
    pinMode(pin, INPUT_PULLUP);
}

Przycisk::~Przycisk()
{
}
