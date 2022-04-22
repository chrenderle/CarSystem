#include "Stopper.h"
#include "Arduino.h"

Stopper::Stopper(int _pin)
{
    pin = _pin;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, !STOPPER_ACTIVE);
}

bool Stopper::getStatus()
{
    return numberLocks > 0;
}

int Stopper::getPin()
{
    return pin;
}

void Stopper::lock()
{
    numberLocks++;

    writePin();
}

void Stopper::release()
{
    numberLocks--;

    writePin();
}

void Stopper::writePin()
{
    if (numberLocks > 0)
    {
        digitalWrite(pin, STOPPER_ACTIVE);
    }
    else
    {
        digitalWrite(pin, !STOPPER_ACTIVE);
    }
}