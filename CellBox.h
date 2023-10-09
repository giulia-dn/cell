#ifndef CELL_CELLBOX_H
#define CELL_CELLBOX_H
#include "iostream"
#include "Cell.h"
#include "Subject.h"
#include "Observer.h"
#include <list>
using namespace std;

class CellBox : public Subject, public Observer {
public:
    CellBox(Cell *c) : subject(c) {
        subject->subscribe(this);
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

    virtual void update() override {
        float v = subject->getData();
        addLista(v);
        cout << "ok" << endl;
    }

    void addLista(float v) {
        if (lista.empty())
            newCell = v;
        lista.push_back(v);
    }

    void clear() {
        newCell = 0;
        sommaR = 0;
        sottrazioneR = 0;
        massimoR = 0;
        minimoR = 0;
        lista.clear();
        //notify();
    }

    void somma() {
        float c = 0;
        for (auto i = lista.begin(); i != lista.end(); i++)
            c += (*i);
        sommaR = c;
        notify();
    }

    void sottrazione() {
        float c = newCell + newCell;
        /*if (newCell < 0)
            c = newCell;*/
        for (auto i = lista.begin(); i != lista.end(); i++)
            c -= (*i);
        sottrazioneR = c;
        notify();
    }

    void massimo() {
        float c = newCell;
        float p, s;
        for (auto i = lista.begin(); i != lista.end(); i++) {
            p = (*i);
            if (p > c)
                c = p;
            for (auto i = lista.begin(); i != lista.end(); i++) {
                s = (*i);
                if (s > c)
                    c = s;
            }
        }
        massimoR = c;
        notify();
    }

    void minimo() {
        float c = newCell;
        float p, s;
        for (auto i = lista.begin(); i != lista.end(); i++) {
            p = (*i);
            if (p < c)
                c = p;
            for (auto i = lista.begin(); i != lista.end(); i++) {
                s = (*i);
                if (s < c)
                    c = s;
            }
        }
        minimoR = c;
        notify();
    }

    float getSommaR() {
        return sommaR;
    }

    float getSottraioneR() {
        return sottrazioneR;
    }

    float getMassimoR() const {
        return massimoR;
    }

    float getMinimoR() const {
        return minimoR;
    }

    /*void addCell(Cell * c){
        if(cells.empty())
            firstMean = c->getData();
        newCell = c->getData();
        cells.push_back(c);


    }
    void sum(){
        int c = 0;
        for(auto i=cells.begin(); i!=cells.end(); i++)
            c += (*i)->getData();
        addResult=c;


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
    virtual void notifyData(){
        for(auto i=observers.begin(); i!=observers.end(); i++)
            (*i)->updateData(newCell);

    }
    virtual void updateData(float data)override{
    }*/

private:
    /*int addResult=0;
    int meanResult=0;
    int maxResult=0;
    int minResult=0;
    int firstMean;*/
    list<Observer *> observers;
    list<Cell *> cells;
    float newCell = 0;
    Cell *subject;
    list<float> lista;
    float sommaR = 0, sottrazioneR = 0, massimoR = 0, minimoR = 0;


};


#endif //CELL_CELLBOX_H
