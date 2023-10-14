#ifndef CELL_CELLBOX_H
#define CELL_CELLBOX_H
#include "iostream"
#include "Subject.h"
#include "Observer.h"
#include <list>
using namespace std;

class CellBox : public Subject {
public:
    virtual ~CellBox() = default;
    void subscribe(Observer *o) override {
        observers.push_back(o);
    }

    void unsubscribe(Observer *o) override {
        observers.remove(o);
    }

    void notify() override {
        for (auto i = observers.begin(); i != observers.end(); i++)
            (*i)->update();
    }

    void notifyData() override {
        for (auto i = observers.begin(); i != observers.end(); i++)
            (*i)->upDate();
    }

    void notifyClear() override {
        for (auto i = observers.begin(); i != observers.end(); i++)
            (*i)->reset();
    }

    virtual void op() = 0;

    virtual void reset() = 0;

    virtual float getR() const = 0;

private:
    list<Observer *> observers;

};


#endif //CELL_CELLBOX_H
