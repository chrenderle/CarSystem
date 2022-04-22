#include "Sensor.h"
#include "Arduino.h"

Sensor::Sensor(int _pin)
{
    // setup pin
    pin = _pin;
    pinMode(pin, INPUT);

    // read pin for the first time
    lastState = digitalRead(pin);
}

bool Sensor::getStatus()
{
    return digitalRead(pin) == SENSOR_ACTIVE;
}

bool Sensor::addStartOwner(Section &section)
{
    if (startSectionOwners_size >= MAX_SECTION_OWNERS)
    {
        return false;
    }

    startSectionOwners[startSectionOwners_size] = &section;
    startSectionOwners_size++;

    return true;
}

bool Sensor::addEndOwner(Section &section)
{
    if (endSectionOwners_size >= MAX_SECTION_OWNERS)
    {
        return false;
    }

    endSectionOwners[endSectionOwners_size] = &section;
    endSectionOwners_size++;

    return true;
}

/*void Sensor::addPinChangeCallback(callback_void_t *callback)
{
    // check if array is already full
    if (pinChangeCallbacksSize >= MAX_CALLBACKS)
    {
        return;
    }

    // add callback to array
    pinChangeCallbacks[pinChangeCallbacksSize] = callback;
    pinChangeCallbacksSize++;
}*/

// should be called periodically
// maybe need to add debouncing
// calls all registered callbacks when the state changes
void Sensor::checkPinChange()
{
    if (digitalRead(pin) != lastState)
    {
        for (unsigned int i = 0; i < startSectionOwners_size; i++)
        {
            startSectionOwners[i]->startSensorCallback(pin);
        }
        for (unsigned int i = 0; i < endSectionOwners_size; i++)
        {
            endSectionOwners[i]->endSensorCallback(pin);
        }
    }
}

int Sensor::getPin()
{
    return pin;
}