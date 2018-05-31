#include<Arduino.h>


class WykrywaczObecnosci
{
private:
    int pin;
public:
    WykrywaczObecnosci(int pin);
    ~WykrywaczObecnosci();
    bool czyWykrytoObiekt();
};

WykrywaczObecnosci::WykrywaczObecnosci(int pin){
    this->pin = pin;
    pinMode(pin, INPUT);
}

WykrywaczObecnosci::~WykrywaczObecnosci(){

}

bool WykrywaczObecnosci::czyWykrytoObiekt(){
    return digitalRead(pin);
}
