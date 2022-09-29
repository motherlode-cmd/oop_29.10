#ifndef CELLVIEW_H
#define CELLVIEW_H
#include "cell.h"
#include "qtablewidget.h"
class CellView
{
public:
    CellView();
    CellView(CellView const &copyCellView);
    CellView & operator = (CellView const & other);
    CellView(CellView && source);
    CellView & operator = (CellView && other);

    QTableWidgetItem * drowNewCell(const Cell & cell, const Position & playerPosition);
    void drowCell(QTableWidgetItem * item, const Cell & cell, const Position & playerPosition);

private:
    Cell cell;
};

#endif // CELLVIEW_H
