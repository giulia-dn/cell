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



QT_BEGIN_NAMESPACE

class Monitor{
public:

    QWidget * ViewWidget;
    QPushButton * sumButton;
    QPushButton * meanButton;
    QPushButton * maxButton;
    QPushButton * minButton;
    QLabel * textResult;
    QLabel * textSum;
    QLabel * textMean;
    QLabel * textMax;
    QLabel * textMin;
    QLabel * textData;
    int highData=280;

    void setUi(QMainWindow * View){
        if(View->objectName().isEmpty())
            View->setObjectName(QStringLiteral("Monitor"));
        View->resize(500, 800);
        ViewWidget = new QWidget(View);
        ViewWidget->setObjectName(QStringLiteral("Monitor"));
        sumButton = new QPushButton(ViewWidget);
        sumButton->setObjectName(QStringLiteral("sumButton"));
        sumButton->setGeometry(QRect(20,50, 100, 20));
        meanButton = new QPushButton(ViewWidget);
        meanButton->setObjectName(QStringLiteral("meanButton"));
        meanButton->setGeometry(QRect(20,100, 100, 20));
        maxButton = new QPushButton(ViewWidget);
        maxButton->setObjectName(QStringLiteral("maxButton"));
        maxButton->setGeometry(QRect(20,150, 100, 20));
        minButton = new QPushButton(ViewWidget);
        minButton->setObjectName(QStringLiteral("minButton"));
        minButton->setGeometry(QRect(20,200, 100, 20));
        textResult = new QLabel(ViewWidget);
        textResult->setObjectName(QStringLiteral("textResult"));
        textResult->setGeometry(QRect(180,20, 100, 20));
        textSum=new QLabel(ViewWidget);
        textSum->setObjectName(QStringLiteral("textSum"));
        textSum->setGeometry(QRect(180, 50, 100, 20));
        textMean=new QLabel(ViewWidget);
        textMean->setObjectName(QStringLiteral("textMean"));
        textMean->setGeometry(QRect(180, 100, 100, 20));
        textMax=new QLabel(ViewWidget);
        textMax->setObjectName(QStringLiteral("textMax"));
        textMax->setGeometry(QRect(180, 150, 100, 20));
        textMin=new QLabel(ViewWidget);
        textMin->setObjectName(QStringLiteral("textMin"));
        textMin->setGeometry(QRect(180, 200, 100, 20));
        textData=new QLabel(ViewWidget);
        textData->setObjectName(QString("textData"));
        textData->setGeometry(QRect(20, 250, 100, 20));

        View->setCentralWidget(ViewWidget);

        translateUi(View);
        QObject::connect(sumButton, SIGNAL(clicked()), View, SLOT(useSumButton()));
        QObject::connect(meanButton, SIGNAL(clicked()), View, SLOT(useMeanButton()));
        QObject::connect(maxButton, SIGNAL(clicked()), View, SLOT(useMaxButton()));
        QObject::connect(minButton, SIGNAL(clicked()), View, SLOT(useMinButton()));

        QMetaObject::connectSlotsByName(View);

    }
    void createData(int value){
        QLabel * data;
        data = new QLabel (ViewWidget);
        data->setText(QString::number(value));
        data->setGeometry(QRect(20,highData,100,20));
        highData += 30;


    }
    void translateUi(QMainWindow * View){
        View->setWindowTitle(QApplication::translate("Monitor", "CELLBOX", nullptr));
        sumButton->setText(QApplication::translate("Monitor", "SUM", nullptr));
        meanButton->setText(QApplication::translate("Monitor", "MEAN", nullptr));
        maxButton->setText(QApplication::translate("Monitor", "MAX", nullptr));
        minButton->setText(QApplication::translate("Monitor", "MIN", nullptr));
        textResult->setText(QApplication::translate("Monitor", "Results :", nullptr));
        textData->setText(QApplication::translate("Monitor", "Datas :", nullptr));

    }






};

 QT_END_NAMESPACE
#endif //CELL_MONITOR_H
