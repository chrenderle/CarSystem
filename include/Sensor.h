#ifndef SENSOR_H
#define SENSOR_H

#include "Section.h"
#include "Stopper.h"

typedef void (*callback_void_t)(int);

#define MAX_CALLBACKS 5
#define SENSOR_ACTIVE HIGH
#define MAX_SECTION_OWNERS 3

class Sensor
{
    private:
        int lastState;
        int pin;
        Section *startSectionOwners[MAX_SECTION_OWNERS];
        unsigned int startSectionOwners_size = 0;
        Section *endSectionOwners[MAX_SECTION_OWNERS];
        unsigned int endSectionOwners_size = 0;
        //void (*pinChangeCallbacks[MAX_CALLBACKS]) (int);
        //unsigned int pinChangeCallbacksSize = 0;
    public:
        bool getStatus();
        //void addPinChangeCallback(void (*callback) (int));
        void checkPinChange();
        int getPin();
        Sensor(int pin);
        bool addStartOwner(Section &section);
        bool addEndOwner(Section &section);
};

#endif