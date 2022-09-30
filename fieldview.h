#ifndef FIELDVIEW_H
#define FIELDVIEW_H
#include "cellview.h"
#include "field.h"
#include "qtablewidget.h"
class FieldView
{
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
    Field field = Field(0,0);
    CellView cellView;
};

#endif // FIELDVIEW_H
