#ifndef CELL_MONITOR_H
#define CELL_MONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QStringListModel>


QT_BEGIN_NAMESPACE

class Monitor{
public:

    QWidget * ViewWidget;
    QLabel *sum;
    QLabel *mean;
    QLabel *max;
    QLabel *min;
    QLabel *textResult;
    QLabel *textSum;
    QLabel *textMean;
    QLabel *textMax;
    QLabel *textMin;
    QLabel *textData;
    QLineEdit *insData;
    QPushButton *add;
    QPushButton *reset;
    QListView *m_pwPending = nullptr;

    void setUi(QMainWindow *View) {
        if (View->objectName().isEmpty())
            View->setObjectName(QStringLiteral("Monitor"));
        View->resize(500, 800);
        ViewWidget = new QWidget(View);
        ViewWidget->setObjectName(QStringLiteral("Monitor"));
        sum = new QLabel(ViewWidget);
        sum->setObjectName(QStringLiteral("sumButton"));
        sum->setGeometry(QRect(20, 50, 100, 20));
        mean = new QLabel(ViewWidget);
        mean->setObjectName(QStringLiteral("meanButton"));
        mean->setGeometry(QRect(20,100, 100, 20));
        max = new QLabel(ViewWidget);
        max->setObjectName(QStringLiteral("maxButton"));
        max->setGeometry(QRect(20,150, 100, 20));
        min = new QLabel(ViewWidget);
        min->setObjectName(QStringLiteral("minButton"));
        min->setGeometry(QRect(20,200, 100, 20));
        textResult = new QLabel(ViewWidget);
        textResult->setObjectName(QStringLiteral("textResult"));
        textResult->setGeometry(QRect(180,20, 100, 20));
        textSum=new QLabel(ViewWidget);
        textSum->setObjectName(QStringLiteral("textSum"));
        textSum->setGeometry(QRect(180, 50, 100, 20));
        textMean=new QLabel(ViewWidget);
        textMean->setObjectName(QStringLiteral("textMean"));
        textMean->setGeometry(QRect(180, 100, 100, 20));
        textMax = new QLabel(ViewWidget);
        textMax->setObjectName(QStringLiteral("textMax"));
        textMax->setGeometry(QRect(180, 150, 100, 20));
        textMin = new QLabel(ViewWidget);
        textMin->setObjectName(QStringLiteral("textMin"));
        textMin->setGeometry(QRect(180, 200, 100, 20));
        textData = new QLabel(ViewWidget);
        textData->setObjectName(QString("textData"));
        textData->setGeometry(QRect(20, 350, 100, 20));

        insData = new QLineEdit(ViewWidget);
        insData->setObjectName(QString("insData"));
        insData->setGeometry(QRect(20, 300, 100, 20));
        auto dv = new QDoubleValidator(-100000000000000, 100000000000000, 2);
        insData->setValidator(dv);

        add = new QPushButton(ViewWidget);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(140, 300, 100, 20));

        reset = new QPushButton(ViewWidget);
        reset->setObjectName(QStringLiteral("reset"));
        reset->setGeometry(QRect(260, 300, 100, 20));

        m_pwPending = new QListView(ViewWidget);
        m_pwPending->setGeometry(QRect(20, 390, 200, 300));
        m_pwPending->setModel(new QStringListModel());

        View->setCentralWidget(ViewWidget);

        translateUi(View);
        QObject::connect(add, SIGNAL(clicked()), View, SLOT(useAdd()));
        QObject::connect(reset, SIGNAL(clicked()), View, SLOT(useRes()));

        QMetaObject::connectSlotsByName(View);

    }

    void translateUi(QMainWindow * View) {
        View->setWindowTitle(QApplication::translate("Monitor", "CELLBOX", nullptr));
        sum->setText(QApplication::translate("Monitor", "SUM :", nullptr));
        mean->setText(QApplication::translate("Monitor", "MEAN :", nullptr));
        max->setText(QApplication::translate("Monitor", "MAX :", nullptr));
        min->setText(QApplication::translate("Monitor", "MIN :", nullptr));
        textResult->setText(QApplication::translate("Monitor", "Results :", nullptr));
        textData->setText(QApplication::translate("Monitor", "Datas :", nullptr));

        add->setText(QApplication::translate("Monitor", "ADD", nullptr));
        reset->setText(QApplication::translate("Monitor", "RESET", nullptr));

    }

};

QT_END_NAMESPACE
#endif //CELL_MONITOR_H
