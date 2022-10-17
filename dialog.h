#ifndef DIALOG_H
#define DIALOG_H

#include "logger.h"
#include "qabstractbutton.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void setLoggers(std::vector <Logger *> * vecloggers) {loggers = vecloggers;}
    ~Dialog();

private slots:
    void on_comboBox_activated(int index);

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Dialog *ui;
    std::vector <Logger *> * loggers;
};

#endif // DIALOG_H
