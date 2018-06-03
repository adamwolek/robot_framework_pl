#include "Updateable.h"
#include "Lista.h"
class Updater
{
private:
   Lista<Updateable> listeners;
public:
    Updater(/* args */);
    ~Updater();
    static void updateEveryListeners();
    static void registerForUpdates(Updateable updateable);
};

void Updater::updateEveryListeners(){
    for(int i = 0; i < listeners.length(); i++)
    {
        listeners.get(i).update();
    }   
}

void Updater::registerForUpdates(Updateable& listener){
    listeners.add(listener);
}


Updater::Updater(/* args */)
{
}

Updater::~Updater()
{
}
