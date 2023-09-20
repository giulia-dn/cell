#ifndef CELL_VIEW_H
#define CELL_VIEW_H

#include <QMainWindow>
#include "Observer.h"
#include "CellBox.h"
#include "Monitor.h"
#include "CellBox.h"

class View: public QMainWindow, public Observer{
    Q_OBJECT
public:
    View(CellBox * cb, QWidget * parent=0): QMainWindow(parent), ui(new Monitor()), subject(cb){
        subject->subscribe(this);
        ui->setUi(this);
        update();
    }
    ~View(){
        subject->unsubscribe(this);
        delete ui;
    }
    virtual void update()override{
        int sum = subject->getAddResult();
        ui->textSum->setText(QString::number(sum));
        int mean = subject->getMeanResult();
        ui->textMean->setText(QString::number(mean));
        int max = subject->getMaxResult();
        ui->textMax->setText(QString::number(max));
        int min = subject->getMinResult();
        ui->textMin->setText(QString::number(min));
    }
    virtual void updateData() override{
        int value = subject->getNewCell();
        ui->createData(value);
    }

private slots:
    void useSumButton(){
        subject->sum();
    }
    void useMeanButton(){
        subject->mean();
    }
    void useMaxButton(){
        subject->max();
    }
    void useMinButton(){
        subject->min();
    }

private:
    CellBox * subject;
    Monitor * ui;


};

#endif //CELL_VIEW_H
