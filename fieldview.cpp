#include "fieldview.h"

FieldView::FieldView(const Field & field, QTableWidget * table)
{
    this->field = field;
    int n = field.getHeight();
    int m = field.getWidth();
    table->setColumnCount(m);
    table->setRowCount(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            table->setItem(i,j,cellView.drowNewCell(field.getCell(i,j), field.getPositionPlayer()));
        }
    }
}

FieldView::FieldView(const FieldView &newFieldView)
{
    field = newFieldView.field;
    cellView = newFieldView.cellView;
}

FieldView::FieldView(FieldView &&newFieldView)
{
    field = newFieldView.field;
    cellView = newFieldView.cellView;
}

FieldView &FieldView::operator = (const FieldView &other)
{
    if(this != &other) {
        field = other.field;
        cellView = other.cellView;
    }
    return *this;
}

FieldView &FieldView::operator = (FieldView &&other)
{
    if(this != &other) {
        field = other.field;
        cellView = other.cellView;
    }
    return *this;
}

FieldView::~FieldView()
{
}

void FieldView::drowField(Field &field, QTableWidget *table)
{
    this->field = field;
    int n = field.getHeight();
    int m = field.getWidth();
    table->setColumnCount(m);
    table->setRowCount(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cellView.drowCell(table->item(i,j), field.getCell(i,j), field.getPositionPlayer());
        }
    }
}




