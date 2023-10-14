//
// Created by giulia on 07/10/23.
//

#ifndef CELL_MAX_H
#define CELL_MAX_H

#include "CellBox.h"
#include "Add.h"

class Max : public CellBox {
public:
    Max(Add *a) : add(a) {}

    void op() override {
        lista1 = add->getLista();
        auto d = lista1.begin();
        float c = (*d);
        float p, s;
        for (auto i = lista1.begin(); i != lista1.end(); i++) {
            p = (*i);
            if (p > c)
                c = p;
            for (auto i = lista1.begin(); i != lista1.end(); i++) {
                s = (*i);
                if (s > c)
                    c = s;
            }
        }
        massimoR = c;
        notify();
    }

    void reset() override{
        massimoR = 0;
    }

    float getR() const override {
        return massimoR;
    }

private:
    Add *add;
    float massimoR = 0;
    list<float> lista1;
};


#endif //CELL_MAX_H
