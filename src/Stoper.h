#include <Arduino.h>


class Stoper
{
private:

    enum Stan{
        Stopped,
        Started,
        Init
    };

    long lastMeasure = 0;
    double aktualnaWartosc;
    Stan stan;
    void updateAktualnaWartos();

public:
    Stoper(/* args */);
    ~Stoper();
    void start();
    void stop();
    double zmierzonyCzas();
    void reset();
};

void Stoper::start(){
    lastMeasure = millis();
    stan = Started;
}

void Stoper::stop(){
    updateAktualnaWartos();
    stan = Stopped;
}

void Stoper::reset(){
    aktualnaWartosc = 0;
    lastMeasure = 0;
    stan = Init;
}

void Stoper::updateAktualnaWartos(){
    long difference = millis() - lastMeasure;
    if(difference)
    aktualnaWartosc = difference / (double)1000;
}

double Stoper::zmierzonyCzas(){
    if(stan == Started){
        updateAktualnaWartos();
    }
    return aktualnaWartosc;
}

Stoper::Stoper()
{
}

Stoper::~Stoper()
{
}
