#ifndef FIELDVIEW_H
#define FIELDVIEW_H
#include "cellview.h"
#include "field.h"
#include "qtablewidget.h"
class FieldView
{
public:
    FieldView() = default;
    FieldView(int n, int m, QTableWidget * table);
    FieldView(FieldView const & newFieldView);
    FieldView(FieldView && newFieldView);
    FieldView & operator = (const FieldView &other);
    FieldView & operator = (FieldView &&other);
    ~FieldView();
    void setSize(int n, int m, QTableWidget * table);
    QTableWidget *getTableWidet() const;
    void setTableWidet(QTableWidget *newTableWidet);
    void playerMove(int x, int y, Player & player);
    void createNewEvent(Event * event, int x,int y);
    Field &getField();

private:
    Field field = Field(0,0);
    CellView cellView;
    QTableWidget * tableWidet/* = new QTableWidget*/;
};

#endif // FIELDVIEW_H
