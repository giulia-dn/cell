#ifndef CELL_OBSERVER_H
#define CELL_OBSERVER_H


class Observer {
public:

    virtual ~ Observer() = default;

    virtual void update() = 0;

    virtual void upDate() = 0;

    virtual void reset() = 0;
};

#endif //CELL_OBSERVER_H
