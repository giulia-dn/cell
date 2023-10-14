//
// Created by giulia on 07/10/23.
//

#ifndef CELL_SUM_H
#define CELL_SUM_H

#include "CellBox.h"
#include "Add.h"

class Sum : public CellBox {
public:
    Sum(Add *a) : add(a) {}

    void op() override {
        lista1 = add->getLista();
        float c = 0;
        for (auto i = lista1.begin(); i != lista1.end(); i++)
            c += (*i);
        sommaR = c;
        notify();
    }

    void reset() override{
        sommaR = 0;
    }

    float getR() const override {
        return sommaR;
    }

private:
    Add *add;
    float sommaR = 0;
    list<float> lista1;

};

#endif //CELL_SUM_H
