#include "cellview.h"
#include "../Events/EventPlayer/eventadd.h"
#include "../Events/EventPlayer/eventnone.h"
#include "../Events/EventPlayer/eventkey.h"
#include "../Events/EventField/eventlock.h"
#include "../Events/EventField/eventunlock.h"
#include "../Events/EventField/eventwin.h"

QTableWidgetItem *CellView::drowNewCell(const Cell & cell, const Position &playerPosition)
{
    QTableWidgetItem * item = new QTableWidgetItem("-");
    setItem(getType(cell.getEvent()),cell.getIsOpen(), item);
    if(playerPosition.getX() == cell.getPosition().getX() && cell.getPosition().getY() == playerPosition.getY()) {
        item->setText("Here");
        item->setBackground(QColor(230, 10, 155));
    }
    return item;
}

void CellView::drowCell(QTableWidgetItem *item, const Cell &cell, const Position &playerPosition)
{
    setItem(getType(cell.getEvent()), cell.getIsOpen(), item);
    if(playerPosition.getX() == cell.getPosition().getX() && playerPosition.getY() == cell.getPosition().getY()) {
        item->setText("Here");
        item->setBackground(QColor(230, 10, 155));
    }
}

void CellView::setItem(int numType, bool isOpen, QTableWidgetItem *item)
{
    QColor color = QColor(1,1,1);
    switch (numType) {
    case 0:
        color = QColor(255, 157, 209);
        item->setText("-10 HP");
        break;
    case 1:
        color = QColor(0, 255, 0);
        item->setText("+10 HP");
        break;
    case 3:
        color = QColor(255, 0, 0);
        item->setText("lock");
        break;
    case 4:
        color = QColor(0, 0, 255);
        item->setText("unlock");
        break;
    case 10:
        color = QColor(0, 150, 150);
        item->setText("winner");
        break;
    case 15:
        color = QColor(255, 255, 0);
        item->setText("Key");
        break;
    default:
        color = QColor(255,255,255);
        break;
    }
    if(!isOpen && numType != 10) {
        color = QColor(1,1,1);
    }
    item->setBackground(color);
}

int CellView::getType(Event *event)
{
    if(event == dynamic_cast<EventNone *>(event)) return 0;
    if(event == dynamic_cast<EventAdd *>(event)) return 1;
    if(event == dynamic_cast<EventLock *>(event)) return 3;
    if(event == dynamic_cast<EventUnlock *>(event)) return 4;
    if(event == dynamic_cast<EventWin *>(event)) return 10;
    if(event == dynamic_cast<EventKey *>(event)) return 15;
    return -1;
}



