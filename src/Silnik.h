#include<Arduino.h>


class Silnik
{
public:
    enum Polaryzacja{
        LEFT,
        RIGHT
    };

private:
    int controlPin1;
    int controlPin2;
    int pinEnable;
    Polaryzacja polaryzacja;

public:
    Silnik(int controlPin1, int controlPin2, int pinEnable, Polaryzacja polaryzacja);
    ~Silnik();
    void krecDoPrzoduZPredkoscia(double predkoscWProcentach);
    void krecDoTyluZPredkoscia(double predkoscWProcentach);
    void hamuj();
    void wylaczSilnik();

private:
    int zamienNa8BitPWM(double wProcentach);
};

Silnik::Silnik(int controlPin1, int controlPin2, int pinEnable, Polaryzacja polaryzacja){
    this->polaryzacja = polaryzacja;
    this->controlPin1 = controlPin1;
    this->controlPin2 = controlPin2;
    this->pinEnable = pinEnable;

    pinMode(controlPin1, OUTPUT);
    pinMode(controlPin2, OUTPUT);
    pinMode(pinEnable, OUTPUT);
}

Silnik::~Silnik(){

}

void Silnik::krecDoPrzoduZPredkoscia(double predkoscWProcentach){
    switch (this->polaryzacja){
        case LEFT:
            // Serial.println("Left");
            digitalWrite(controlPin1, LOW);
            digitalWrite(controlPin2, HIGH);
            break;
        case RIGHT:
            // Serial.println("Right");
            digitalWrite(controlPin1, HIGH);
            digitalWrite(controlPin2, LOW);
            break;
    }
    analogWrite(pinEnable, zamienNa8BitPWM(predkoscWProcentach));
}

void Silnik::krecDoTyluZPredkoscia(double predkoscWProcentach){
    Serial.println("przedSilnikiem");
    switch (this->polaryzacja){
        case LEFT:
            digitalWrite(controlPin1, HIGH);
            digitalWrite(controlPin2, LOW);
            // Serial.println("Left");
            break;
        case RIGHT:
            digitalWrite(controlPin1, LOW);
            digitalWrite(controlPin2, HIGH);
            // Serial.println("right");
            break;
    }
    analogWrite(pinEnable, zamienNa8BitPWM(predkoscWProcentach));
}

void Silnik::wylaczSilnik(){
    analogWrite(pinEnable, 0);
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, LOW);
}

void Silnik::hamuj(){
    analogWrite(pinEnable, 255);
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, LOW);
}



int Silnik::zamienNa8BitPWM(double wProcentach){
    int wPWM;
    if(wProcentach >= 100){
        wPWM = 255;
    } else if(wProcentach <= 0){
        wPWM = 0;
    } else {
        wPWM = round(wProcentach) * (255.0/100.0);
        Serial.println(wPWM);
    }
    return wPWM;
}

