//
// Created by giulia on 07/10/23.
//

#ifndef CELL_MIN_H
#define CELL_MIN_H

#include "CellBox.h"
#include "Add.h"

class Min : public CellBox {
public:
    Min(Add *a) : add(a) {}

    void op() override {
        lista1 = add->getLista();
        auto d = lista1.begin();
        float c = (*d);
        float p, s;
        for (auto i = lista1.begin(); i != lista1.end(); i++) {
            p = (*i);
            if (p < c)
                c = p;
            for (auto i = lista1.begin(); i != lista1.end(); i++) {
                s = (*i);
                if (s < c)
                    c = s;
            }
        }
        minimoR = c;
        notify();
    }

    void reset() override{
        minimoR = 0;
    }

    float getR() const override {
        return minimoR;
    }

private:
    Add *add;
    float minimoR = 0;
    list<float> lista1;

};


#endif //CELL_MIN_H
