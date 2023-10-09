#ifndef CELL_VIEW_H
#define CELL_VIEW_H

#include <QMainWindow>
#include "Observer.h"
#include "CellBox.h"
#include "Monitor.h"
#include "Add.h"
#include "Sum.h"
#include "Mean.h"
#include "Max.h"
#include "Min.h"

using namespace std;

#include <string>

class View : public QMainWindow, public Observer {
Q_OBJECT
public:
    View(Add *a, CellBox *s, CellBox *m, CellBox *mx, CellBox *mn, QWidget *parent = 0) : QMainWindow(parent),
                                                                                          ui(new Monitor()),
                                                                                          subject1(a), sum(s), mean(m),
                                                                                          max(mx), min(mn) {
        subject1->subscribe(this);
        sum->subscribe(this);
        mean->subscribe(this);
        max->subscribe(this);
        min->subscribe(this);
        ui->setUi(this);
        update();
    }

    ~View() {
        subject1->unsubscribe(this);
        sum->unsubscribe(this);
        mean->unsubscribe(this);
        max->unsubscribe(this);
        min->unsubscribe(this);
        delete ui;
    }

    virtual void update() override {
        float s = sum->getR();
        ui->textSum->setText(QString::number(s));
        float m = mean->getR();
        ui->textMean->setText(QString::number(m));
        float mx = max->getR();
        ui->textMax->setText(QString::number(mx));
        float mn = min->getR();
        ui->textMin->setText(QString::number(mn));
    }

    virtual void upDate() {
        ui->m_pwPending->model()->insertRow(ui->m_pwPending->model()->rowCount());
        QModelIndex oIndex = ui->m_pwPending->model()->index(ui->m_pwPending->model()->rowCount() - 1, 0);
        QString s = QString::number(data);
        ui->m_pwPending->model()->setData(oIndex, s);
        ui->insData->setText("");
    }

    virtual void reset() {
        count = 0;
        ui->textSum->setText(QString::number(0));
        ui->textMean->setText(QString::number(0));
        ui->textMax->setText(QString::number(0));
        ui->textMin->setText(QString::number(0));
        ui->m_pwPending->clearSelection();
        ui->m_pwPending->setModel(new QStringListModel());
    }

private slots:

    void useSumButton() {
        sum->op();
    }

    void useMeanButton() {
        mean->op();
    }

    void useMaxButton() {
        max->op();
    }

    void useMinButton() {
        min->op();
    }

    void useAdd() {
        data = ui->insData->text().toFloat();
        subject1->addLista(data);

    }

    void useRes() {
        subject1->reset();
        sum->reset();
        mean->reset();
        max->reset();
        min->reset();
    }

private:
    Add *subject1;
    CellBox *sum;
    CellBox *mean;
    CellBox *max;
    CellBox *min;
    Monitor *ui;
    int count = 0;
    float data = 0;


};

#endif //CELL_VIEW_H
