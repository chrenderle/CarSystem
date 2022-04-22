#ifndef SECTION_H
#define SECTION_H

#define MAX_START_SENSORS 2
#define MAX_END_SENSORS 2
#define MAX_STOPPERS 2

#include "Sensor.h"
#include "Stopper.h"

class Section
{
    private:
        Sensor *startSensors[MAX_START_SENSORS];
        unsigned int startSensors_size = 0;
        Sensor *endSensors[MAX_END_SENSORS];
        unsigned int endSensors_size = 0;
        Stopper *stoppers[MAX_STOPPERS];
        unsigned int stoppers_size = 0;
        int locks = 0;
    public:
        void startSensorCallback(int pin);
        void endSensorCallback(int pin);
        bool addStartSensor(Sensor &sensor);
        bool addEndSensor(Sensor &sensor);
        bool addStopper(Stopper &stopper);
};

#endif