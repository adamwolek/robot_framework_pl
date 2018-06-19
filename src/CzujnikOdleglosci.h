#include<Arduino.h>

class CzujnikOdleglosci{

    private:
        int trigPin;
        int echoPin;
    public:
        CzujnikOdleglosci(int trigPin, int echoPin);
        int getOdleglosc();
};

CzujnikOdleglosci::CzujnikOdleglosci(int trigPin, int echoPin){
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    pinMode(trigPin, OUTPUT);             
    pinMode(echoPin, INPUT);  
}

int CzujnikOdleglosci::getOdleglosc()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(15);
    digitalWrite(trigPin, LOW);
    long czas = pulseIn(echoPin, HIGH);
    int odleglosc = czas / 58;
    if(odleglosc > 200){
        odleglosc = 200;
    }
    return odleglosc;
}