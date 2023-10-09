#include <QApplication>
#include "Cell.h"
#include "CellBox.h"
#include "View.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);



    /*Cell * cell1 = new Cell;
    Cell * cell2 = new Cell;
    Cell * cell3 = new Cell;
    Cell * cell4 = new Cell;

    cellBox->addCell(cell1);
    cellBox->addCell(cell2);
    cellBox->addCell(cell3);
    cellBox->addCell(cell4);*/




    Cell *cell = new Cell;
    CellBox *cellBox = new CellBox(cell);
    //cellBox->addCell(cell);
    View view(cellBox, cell);
    //cell->setData(7.5);
    view.show();


    return QApplication::exec();
}
