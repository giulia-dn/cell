//
// Created by giulia on 19/09/23.
//

#ifndef CELL_SUBJECT_H
#define CELL_SUBJECT_H

#include "Observer.h"

class Subject{
public:
    virtual ~Subject()= default;
    virtual void subscribe(Observer * o)=0;
    virtual void unsubscribe(Observer * o)=0;
    virtual void notify()=0;
    //virtual void notifyData()=0;
};

#endif //CELL_SUBJECT_H
