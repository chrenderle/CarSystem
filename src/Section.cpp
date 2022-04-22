#include "Section.h"

bool Section::addStartSensor(Sensor &sensor)
{
    // check if array is already full
    if (startSensors_size >= MAX_START_SENSORS)
    {
        return false;
    }

    startSensors[startSensors_size] = &sensor;
    startSensors_size++;

    sensor.addStartOwner(*this);

    return true;
}

bool Section::addEndSensor(Sensor &sensor)
{
    // check if array is already full
    if (endSensors_size >= MAX_END_SENSORS)
    {
        return false;
    }

    endSensors[endSensors_size] = &sensor;
    endSensors_size++;

    sensor.addEndOwner(*this);

    return true;
}

bool Section::addStopper(Stopper &stopper)
{
    // check if array is already full
    if (stoppers_size >= MAX_STOPPERS)
    {
        return false;
    }

    stoppers[stoppers_size] = &stopper;
    stoppers_size++;
    return true;
}

void Section::startSensorCallback(int pin)
{
    for (unsigned int i = 0; i < stoppers_size; i++)
    {
        stoppers[i]->lock();
    }

    locks++;
}

void Section::endSensorCallback(int pin)
{
    // if no more cars between the start and stop sensors
    if (locks == 1)
    {
        for (unsigned int i = 0; i < stoppers_size; i++)
        {
            stoppers[i]->release();
        }
    }

    locks--;
}