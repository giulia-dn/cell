#ifndef CELL_VIEW_H
#define CELL_VIEW_H

#include <QMainWindow>
#include "Observer.h"
#include "CellBox.h"
#include "Monitor.h"
#include "Cell.h"

class View: public QMainWindow, public Observer{
    Q_OBJECT
public:
    View(CellBox *cb, Cell *c, QWidget *parent = 0) : QMainWindow(parent), ui(new Monitor()), subject(cb), cell(c) {
        subject->subscribe(this);
        cell->subscribe(this);
        ui->setUi(this);
        update();
    }

    ~View() {
        subject->unsubscribe(this);
        delete ui;
    }

    virtual void update() override {
        float sum = subject->getSommaR();
        ui->textSum->setText(QString::number(sum));
        float mean = subject->getSottraioneR();
        ui->textMean->setText(QString::number(mean));
        float max = subject->getMassimoR();
        ui->textMax->setText(QString::number(max));
        float min = subject->getMinimoR();
        ui->textMin->setText(QString::number(min));
        // ui->data1text->setText(ui->data1->text());
    }

    virtual void updateData(float data) {
        // int value = subject->getNewCell();


    }

    virtual void upData() {
        if (count == 0) {
            count = 0;
            ui->dataText0->setText(ui->insData->text());
            data = ui->insData->text().toFloat();
            cell->setData(data);

        } else if (count == 1) {
            ui->dataText1->setText(ui->insData->text());
            data = ui->insData->text().toFloat();
            cell->setData(data);

        } else if (count == 2) {
            ui->dataText2->setText(ui->insData->text());
            data = ui->insData->text().toFloat();
            cell->setData(data);
        } else if (count == 3) {
            ui->dataText3->setText(ui->insData->text());
            data = ui->insData->text().toFloat();
            cell->setData(data);
        } else if (count == 4) {
            ui->dataText4->setText(ui->insData->text());
            data = ui->insData->text().toFloat();
            cell->setData(data);
        } else if (count == 5) {
            ui->dataText5->setText(ui->insData->text());
            data = ui->insData->text().toFloat();
            cell->setData(data);
        }
        count += 1;
    }

    virtual void reset() {
        count = 0;
        ui->dataText0->setText("null");
        ui->dataText1->setText("null");
        ui->dataText2->setText("null");
        ui->dataText3->setText("null");
        ui->dataText4->setText("null");
        ui->dataText5->setText("null");
        ui->textSum->setText(QString::number(0));
        ui->textMean->setText(QString::number(0));
        ui->textMax->setText(QString::number(0));
        ui->textMin->setText(QString::number(0));

    }


private slots:

    void useSumButton() {
        subject->somma();
    }

    void useMeanButton() {
        subject->sottrazione();
    }

    void useMaxButton() {
        subject->massimo();
    }

    void useMinButton() {
        subject->minimo();
    }

    void useAdd() {
        upData();
        //cell->setData(data);
    }

    void useRes() {
        reset();
        subject->clear();
    }

private:
    CellBox *subject;
    Cell *cell;
    Monitor *ui;
    int count = 0;
    float data = 0;


};

#endif //CELL_VIEW_H
