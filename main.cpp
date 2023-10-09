#include <QApplication>

#include "CellBox.h"
#include "View.h"
#include "Sum.h"
#include "Add.h"
#include "Mean.h"
#include "Max.h"
#include "Min.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Add *cellBox = new Add;
    CellBox *sum = new Sum(cellBox);
    CellBox *mean = new Mean(cellBox);
    CellBox *max = new Max(cellBox);
    CellBox *min = new Min(cellBox);

    View view(cellBox, sum, mean, max, min);
    view.show();

    return QApplication::exec();
}
