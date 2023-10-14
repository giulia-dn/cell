//
// Created by giulia on 07/10/23.
//

#ifndef CELL_MEAN_H
#define CELL_MEAN_H

#include "CellBox.h"
#include "Add.h"

class Mean : public CellBox {
public:
    Mean(Add *a) : add(a) {}

    void op() override {
        lista1 = add->getLista();
        float c = 0;
        float d = add->getR();
        if (d == 0)
            mediaR = 0;
        else {
            for (auto i = lista1.begin(); i != lista1.end(); i++)
                c += (*i);
            mediaR = c / d;
        }
        notify();
    }

    void reset() override {
        mediaR = 0;
    }

    float getR() const override {
        return mediaR;
    }

private:
    Add *add;
    float mediaR = 0;
    list<float> lista1;
};

#endif //CELL_MEAN_H
