//
// Created by giulia on 07/10/23.
//

#ifndef CELL_ADD_H
#define CELL_ADD_H

#include "CellBox.h"

class Add : public CellBox {
public:

    virtual void addLista(float v) {
        lista.push_back(v);
        op();//nEmpty = true;
        notifyData();
    }

    virtual void reset() override {
        lista.clear();
        op();//nEmpty = false;
        notifyClear();
    }

    virtual void op() override { //setta lista vuota o no(?)
        if (lista.empty())
            nEmpty = false;
        else
            nEmpty = true;
    }

    virtual float getR() const override {//ritorna numero elementi lista.
        int c = 0;
        for (auto i = lista.begin(); i != lista.end(); i++)
            c += 1;
        return c;
    }

    const list<float> &getLista() const {
        return lista;
    }

private:
    list<float> lista;
    bool nEmpty = false;
};

#endif //CELL_ADD_H
