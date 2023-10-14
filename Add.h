//
// Created by giulia on 07/10/23.
//

#ifndef CELL_ADD_H
#define CELL_ADD_H

#include "CellBox.h"

class Add : public CellBox {
public:

    void addLista(float v) {
        lista.push_back(v);
        op();//nEmpty = true;
        notifyData();
    }

    void reset() override {
        lista.clear();
        op();
        notifyClear();
    }

    void op() override {
        if (lista.empty())
            nEmpty = false;
        else
            nEmpty = true;
    }

    float getR() const override {
        float c = 0;
        for (auto i = lista.begin(); i != lista.end(); i++)
            c += 1;
        return c;
    }

    const list<float> &getLista() const {
        return lista;
    }

    bool isNEmpty() const {
        return nEmpty;
    }

private:
    list<float> lista;
    bool nEmpty = false;
};

#endif //CELL_ADD_H
