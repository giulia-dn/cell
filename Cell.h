#ifndef CELL_CELL_H
#define CELL_CELL_H

#include "Subject.h"
#include <list>

using namespace std;

class Cell : public Subject {
public:
    Cell() {
    }

    virtual void subscribe(Observer *o) override {
        observers.push_back(o);
    }

    virtual void unsubscribe(Observer *o) override {
        observers.remove(o);
    }

    virtual void notify() override {
        for (auto i = observers.begin(); i != observers.end(); i++)
            (*i)->update();
    }

    /*virtual void notifyData(){
        for(auto i=observers.begin(); i!=observers.end(); i++)
            (*i)->updateData(data);
    }*/
    float getData() const {
        return data;
    }

    void setData(float c) {
        data = c;
        //notifyData();
        notify();
    }

private:
    float data = 0;
    list<Observer *> observers;

};



#endif //CELL_CELL_H
