#ifndef STOPPER_H
#define STOPPER_H

#define STOPPER_ACTIVE HIGH

class Stopper
{
    private:
        unsigned int pin;
        int numberLocks = 0;
        void writePin();
    public:
        bool getStatus();
        void lock();
        void release();
        int getPin();
        Stopper(int pin);
};

#endif