#include <QApplication>
#include "Cell.h"
#include "CellBox.h"
#include "View.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    CellBox * cellBox = new CellBox;
    View view(cellBox);
    Cell * cell = new Cell(7);
    Cell * cell1 = new Cell(-1);
    Cell * cell2 = new Cell(2);
    Cell * cell3 = new Cell(4);
    Cell * cell4 = new Cell(3);
    cellBox->addCell(cell);
    cellBox->addCell(cell1);
    cellBox->addCell(cell2);
    cellBox->addCell(cell3);
    cellBox->addCell(cell4);
    view.show();

    return QApplication::exec();
}
