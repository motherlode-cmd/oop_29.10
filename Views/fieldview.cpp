#include "fieldview.h"
#include "qheaderview.h"
FieldView::FieldView(const Field & field, QTableWidget * table)
{

    this->field = field;
    int n = field.getHeight();
    int m = field.getWidth();
    if(n > 0 && m > 0){
        table->setColumnCount(m);
        table->setRowCount(n);
        table->horizontalHeader()->setDefaultSectionSize(50);    // width
        table->verticalHeader()->setDefaultSectionSize(50);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                table->setItem(i,j,cellView.drowNewCell(field.cells[i][j], field.positionPlayer));
            }
        }
    }
}

FieldView::FieldView(const FieldView &newFieldView):field(newFieldView.field), cellView(newFieldView.cellView)
{}

FieldView::FieldView(FieldView &&newFieldView):field(newFieldView.field), cellView(newFieldView.cellView)
{
    //newFieldView.field = Field(0,0);
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
        //other.field = Field(0,0);
    }
    return *this;
}

FieldView::~FieldView()
{}

void FieldView::drowField(Field &field, QTableWidget *table)
{
    this->field = field;
    int n = field.getHeight();
    int m = field.getWidth();
    if(n > 0 && m > 0) {
        table->setColumnCount(m);
        table->setRowCount(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cellView.drowCell(table->item(i,j), field.cells[i][j], field.positionPlayer);
            }
        }
    }
}




