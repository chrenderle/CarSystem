#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "IntersectionArm.h"
#include <stdint.h>

/*#define STATE_PHASE1 0
#define STATE_PHASE1_2 1
#define STATE_PHASE2 2
#define STATE_PHASE2_3 3
#define STATE_PHASE3 4
#define STATE_PHASE3_4 5
#define STATE_PHASE4 6
#define STATE_PHASE4_1 7*/

// in seconds:
#define LONG_STATE_TIME 18
#define SHORT_STATE_TIME 2

enum Action
{
    NOTHING,
    GREEN_RIGHT,
    GREEN_STRAIGHT,
    GREEN_LEFT,
    YELLOW,
    RED,
    RED_YELLOW,
};

struct State
{
    uint16_t time;
    Action leftAction;
    Action rightAction;
    Action upperAction;
};

State states[] =
{
    {LONG_STATE_TIME, GREEN_STRAIGHT, GREEN_RIGHT, GREEN_RIGHT}, //Phase 1
    {SHORT_STATE_TIME, GREEN_LEFT, YELLOW, GREEN_RIGHT}, //Phase 1 to 2
    {LONG_STATE_TIME, GREEN_LEFT, RED, GREEN_RIGHT}, //Phase 2
    {SHORT_STATE_TIME, GREEN_STRAIGHT, RED_YELLOW, YELLOW}, //Phase 2 to 3
    {LONG_STATE_TIME, GREEN_STRAIGHT, GREEN_STRAIGHT, RED}, //Phase 3
    {SHORT_STATE_TIME, YELLOW, GREEN_RIGHT, RED_YELLOW}, //Phase 3 to 4
    {LONG_STATE_TIME, RED, GREEN_RIGHT, GREEN_LEFT}, //Phase 4
    {SHORT_STATE_TIME, RED_YELLOW, GREEN_RIGHT, GREEN_RIGHT} //Phase 4 to 1
};

class Intersection
{
    private:
        IntersectionArm upperRoad;
        IntersectionArm rightRoad;
        IntersectionArm leftRoad;
        uint16_t timeCounter = 0;
        uint16_t state = 0;
        void executeStateMachine();
    public:
        Intersection(IntersectionArm upperRoad, IntersectionArm rightRoad, IntersectionArm leftRoad);
        void loop1000ms();
};

#endif