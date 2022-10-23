#ifndef FIELDVIEW_H
#define FIELDVIEW_H
#include "cellview.h"
#include "../GameLogic/field.h"
#include "qtablewidget.h"
#include <QMainWindow>
class FieldView //: public QMainWindow
{
    //Q_OBJECT
public:
    FieldView() = default;
    FieldView(const Field &field, QTableWidget * table);
    FieldView(FieldView const & newFieldView);
    FieldView(FieldView && newFieldView);
    FieldView & operator = (const FieldView &other);
    FieldView & operator = (FieldView &&other);
    ~FieldView();
    void drowField(Field & field, QTableWidget * table);

private:
    Field field;
    CellView cellView;
    //QTableView * table;
};

#endif // FIELDVIEW_H
