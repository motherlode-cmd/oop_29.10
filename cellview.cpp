#include "cellview.h"

CellView::CellView()
{

}

CellView::CellView(const CellView &copyCellView)
{
    cell = copyCellView.cell;
}

CellView &CellView::operator =(const CellView &other)
{
    cell = other.cell;
    return *this;
}

QTableWidgetItem *CellView::drowNewCell(const Cell & cell, const Position &playerPosition)
{
    this->cell = cell;
    QColor color = QColor(1,1,1);
    if(!cell.getEvent()->getNumOfType()) {
        color = QColor(255, 157, 209);
    } else if(cell.getEvent()->getNumOfType()){
        color = QColor(119, 255, 98);
    }
    if(!cell.getIsOpen()) {
        color = QColor(1,1,1);
    }
    QTableWidgetItem * newInem = new QTableWidgetItem("-");
    if(playerPosition.getX() == cell.getPosition().getX() && cell.getPosition().getY() == playerPosition.getY()) {
        newInem->setText("Here");
        color = QColor(230, 10, 155);
    }
    newInem->setBackground(color);
    return newInem;
}

void CellView::drowCell(QTableWidgetItem *item, const Cell &cell, const Position &playerPosition)
{
    this->cell = cell;
    QColor color = QColor(1,1,1);
    if(!cell.getEvent()->getNumOfType()) {
        color = QColor(255, 157, 209);
    } else if(cell.getEvent()->getNumOfType()){
        color = QColor(119, 255, 98);
    }
    if(!cell.getIsOpen()) {
        color = QColor(1,1,1);
    }
    item->setText("-");
    if(playerPosition.getX() == cell.getPosition().getX() && playerPosition.getY() == cell.getPosition().getY()) {
        item->setText("Here");
        color = QColor(230, 10, 155);
    }
    item->setBackground(color);
}

CellView::CellView(CellView &&source)
{
    cell = source.cell;
}

CellView &CellView::operator =(CellView &&other)
{
    cell = other.cell;
    return *this;
}


