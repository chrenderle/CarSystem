#ifndef INTERSECTION_ARM_H
#define INTERSECTION_ARM_H

#include "Sensor.h"
#include "Stopper.h"

struct IntersectionArm
{
    Stopper *entry;
    // currently unused
    //Sensor *exit;
};


#endif