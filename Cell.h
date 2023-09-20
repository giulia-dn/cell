#ifndef CELL_CELL_H
#define CELL_CELL_H

class Cell{
public:
    Cell(int d) : data(d){
    }

    int getData() const {
        return data;
    }

    void setData(int c) {
        data = c;
    }

private:
    int data;

};



#endif //CELL_CELL_H
