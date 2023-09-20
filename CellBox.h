#ifndef CELL_CELLBOX_H
#define CELL_CELLBOX_H

#include "Cell.h"
#include "Subject.h"
#include "Observer.h"
#include <list>
using namespace std;

class CellBox : public Subject{
public:
    virtual void subscribe(Observer * o) override{
        observers.push_back(o);
    }
    virtual void unsubscribe(Observer * o) override{
        observers.remove(o);
    }
    virtual void notify()override{
        for(auto i=observers.begin(); i!=observers.end(); i++)
            (*i)->update();

    }
    virtual void notifyData()override{
        for(auto i=observers.begin(); i!=observers.end(); i++)
            (*i)->updateData();
    }
    void addCell(Cell * c){
        if(cells.empty())
            firstMean = c->getData();
        newCell = c->getData();
        cells.push_back(c);
        notifyData();
    }
    void sum(){
        int c = 0;
        for(auto i=cells.begin(); i!=cells.end(); i++)
            c += (*i)->getData();
        setAddResult(c);

    }
    void mean(){
        int c= firstMean + firstMean;
        if (firstMean<0)
            c = firstMean;
        for(auto i=cells.begin(); i!=cells.end(); i++)
            c -=(*i)->getData();
        setMeanResult(c);
    }
    void max(){
        int c = firstMean;
        int p,s;
        for(auto i=cells.begin(); i!=cells.end(); i++) {
            p = (*i)->getData();
            if (p>c)
                c=p;
            for(auto i=cells.begin(); i!=cells.end(); i++){
                s = (*i)->getData();
                if(s>c)
                    c=s;
            }
        }
        setMaxResult(c);
    }
    void min(){
        int c = firstMean;
        int p,s;
        for(auto i=cells.begin(); i!=cells.end(); i++) {
            p = (*i)->getData();
            if (p<c)
                c=p;
            for(auto i=cells.begin(); i!=cells.end(); i++){
                s = (*i)->getData();
                if(s<c)
                    c=s;
            }
        }
        setMinResult(c);
    }

    int getAddResult() const {
        return addResult;
    }
    void setAddResult(int addResult) {
        CellBox::addResult = addResult;
        notify();
    }
    int getMeanResult() const {
        return meanResult;
    }
    void setMeanResult(int meanResult) {
        CellBox::meanResult = meanResult;
        notify();
    }
    int getMaxResult() const {
        return maxResult;
    }
    void setMaxResult(int maxResult) {
        CellBox::maxResult = maxResult;
        notify();
    }
    int getMinResult() const {
        return minResult;
    }

    void setMinResult(int minResult) {
        CellBox::minResult = minResult;
        notify();
    }

    int getNewCell() const {
        return newCell;
    }

private:
    int addResult=0;
    int meanResult=0;
    int maxResult=0;
    int minResult=0;
    int firstMean;
    list <Observer*> observers;
    list <Cell*> cells;
    int newCell=0;


};


#endif //CELL_CELLBOX_H
