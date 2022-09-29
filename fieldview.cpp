#include "fieldview.h"

FieldView::FieldView(int n, int m, QTableWidget * table)
{
    field = Field(n,m);
    tableWidet = table;
    tableWidet->setColumnCount(m);
    tableWidet->setRowCount(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            tableWidet->setItem(i,j,cellView.drowNewCell(field.getCell(i,j), Position(-1,-1)));
        }
    }
    tableWidet->setItem(0,0,cellView.drowNewCell(field.getCell(0,0), field.getPositionPlayer()));
    tableWidet->setEnabled(false);
}

FieldView::FieldView(const FieldView &newFieldView)
{
    field = newFieldView.field;
    cellView = newFieldView.cellView;
    tableWidet->setColumnCount(newFieldView.tableWidet->columnCount());
    tableWidet->setRowCount(newFieldView.tableWidet->rowCount());
    for(int i = 0; i < newFieldView.field.getHeight(); i++) {
        for(int j = 0; j < newFieldView.field.getWidth(); j++) {
            QTableWidgetItem * item = new QTableWidgetItem(*newFieldView.tableWidet->item(i,j));
            tableWidet->setItem(i,j, item);
        }
    }
}

FieldView::FieldView(FieldView &&newFieldView)
{
    field = newFieldView.field;
    cellView = newFieldView.cellView;
    tableWidet = newFieldView.tableWidet;
    //tableWidet = new QTableWidget;
//    tableWidet->setColumnCount(newFieldView.tableWidet->columnCount());
//    tableWidet->setRowCount(newFieldView.tableWidet->rowCount());
//    for(int i = 0; i < newFieldView.field.getHeight(); i++) {
//        for(int j = 0; j < newFieldView.field.getWidth(); j++) {
//            QTableWidgetItem * item = new QTableWidgetItem(*newFieldView.tableWidet->item(i,j));
//            tableWidet->setItem(i,j, item);
//        }
//    }
    newFieldView.tableWidet = nullptr;
}
FieldView &FieldView::operator = (const FieldView &other)
{
    if(this != &other) {
        field = other.field;
        tableWidet->setColumnCount(other.tableWidet->columnCount());
        tableWidet->setRowCount(other.tableWidet->rowCount());
        for(int i = 0; i < other.field.getHeight(); i++) {
            for(int j = 0; j < other.field.getWidth(); j++) {
                QTableWidgetItem * item = new QTableWidgetItem(*other.tableWidet->item(i,j));
                tableWidet->setItem(i,j, item);
            }
        }
        cellView = other.cellView;
    }
    return *this;
}

FieldView &FieldView::operator = (FieldView &&other)
{
    if(this != &other) {
        field = other.field;
        tableWidet = other.tableWidet;
//        tableWidet->setColumnCount(other.tableWidet->columnCount());
//        tableWidet->setRowCount(other.tableWidet->rowCount());
//        for(int i = 0; i < other.field.getHeight(); i++) {
//            for(int j = 0; j < other.field.getWidth(); j++) {
//                QTableWidgetItem * item = new QTableWidgetItem(*other.tableWidet->item(i,j));
//                tableWidet->setItem(i,j, item);
//            }
//        }
        cellView = other.cellView;
        other.tableWidet = nullptr;
    }
    return *this;
}

FieldView::~FieldView()
{
    delete tableWidet;
}

void FieldView::setSize(int n, int m, QTableWidget * table)
{
    tableWidet = table;
    field = Field(n,m);
    tableWidet->setColumnCount(m);
    tableWidet->setRowCount(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
              tableWidet->setItem(i,j,cellView.drowNewCell(field.getCell(i,j), Position(-1,-1)));
        }
    }
    tableWidet->setItem(0,0,cellView.drowNewCell(field.getCell(0,0), field.getPositionPlayer()));
    tableWidet->setEnabled(false);
}

QTableWidget *FieldView::getTableWidet() const
{
    return tableWidet;
}

void FieldView::setTableWidet(QTableWidget *newTableWidet)
{
    tableWidet = newTableWidet;
}

void FieldView::playerMove(int x, int y, Player &player)
{
    cellView.drowCell(tableWidet->item(field.getPositionPlayer().getX(), field.getPositionPlayer().getY()),
                      field.getCell(field.getPositionPlayer().getX(), field.getPositionPlayer().getY()), Position(-1,-1));

    field.playerMove(x,y, player);

    cellView.drowCell(tableWidet->item(field.getPositionPlayer().getX(), field.getPositionPlayer().getY()),
                      field.getCell(field.getPositionPlayer().getX(), field.getPositionPlayer().getY()), field.getPositionPlayer());
    //tableWidet->setItem(field.getPositionPlayer().getX(), field.getPositionPlayer().getY(),cellView.drowCell(field.getCell(x,y), field.getPositionPlayer()));
    //tableWidet->setItem(field.getPositionPlayer().getX(), field.getPositionPlayer().getY(), cellView.playerCell(field.getCell(0,0)));
}

void FieldView::createNewEvent(Event * event, int x, int y)
{
    field.setNewEvent(event, x, y);
    cellView.drowCell(tableWidet->item(x,y),
                      field.getCell(x,y), field.getPositionPlayer());
    tableWidet->setEnabled(false);
}

Field &FieldView::getField()
{
    return field;
}

