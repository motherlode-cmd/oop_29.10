#ifndef DIALOG_H
#define DIALOG_H
#include "qabstractbutton.h"
#include <QDialog>
#include <set>
#include "./Observer/Observer.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void getObs(Observer * obs);

    bool getIsCreate() const;

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Dialog *ui;
    Observer * obs;
    bool isCreate = true;
};

#endif // DIALOG_H
