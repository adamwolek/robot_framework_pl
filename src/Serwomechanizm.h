#include <Arduino.h>
#include <Servo.h>

class Serwomechanizm
{
private:
    int pin;
    Servo servo;
public:
    Serwomechanizm(int pin);
    ~Serwomechanizm();
    void ustawKatNa(int kat);
    int ustawionyKat();
};

Serwomechanizm::Serwomechanizm(int pin)
{
    this->pin = pin;
    servo.attach(pin);
}

Serwomechanizm::~Serwomechanizm()
{
}

void Serwomechanizm::ustawKatNa(int kat){
    if(kat >= 0 && kat <= 180){
        servo.write(kat);
    } else {
        Serial.println("Ustawiono nieprawidlowy kat: " + kat);
    }
}

int Serwomechanizm::ustawionyKat(){
    return servo.read();
}
