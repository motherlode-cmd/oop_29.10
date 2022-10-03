#ifndef CELLVIEW_H
#define CELLVIEW_H
#include "cell.h"
#include "qtablewidget.h"
class CellView
{
public:
    CellView() = default;
    QTableWidgetItem * drowNewCell(const Cell & cell, const Position & playerPosition);
    void drowCell(QTableWidgetItem * item, const Cell & cell, const Position & playerPosition);
};

#endif // CELLVIEW_H
