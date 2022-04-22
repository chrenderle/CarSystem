#include "Intersection.h"

Intersection::Intersection(IntersectionArm upperRoad, IntersectionArm rightRoad, IntersectionArm leftRoad)
{
    this->upperRoad = upperRoad;
    this->rightRoad = rightRoad;
    this->leftRoad = leftRoad;
}

void Intersection::loop1000ms()
{
    timeCounter++;
    executeStateMachine();
}

void Intersection::executeStateMachine()
{
    // check if time of state is over
    if (timeCounter > states[state].time)
    {
        // reset timer
        timeCounter = 0;
        // go to next state
        state++;
        // if were at last state go to first state
        if (state >= sizeof(states)/sizeof(State))
        {
            state = 0;
        }
    }
}