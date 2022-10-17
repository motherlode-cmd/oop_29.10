#include "dialog.h"
#include "filelogger.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    loggers = nullptr;
    delete ui;
}

void Dialog::on_comboBox_activated(int index)
{
    switch (index) {
    case 0:
        loggers->push_back(new FileLogger(ui->lineEdit->text().toStdString() + ".txt"));
        break;
    default:
        loggers->push_back(new FileLogger("./Mediator/" + ui->lineEdit->text().toStdString() + ".txt"));
        break;
    }
}


void Dialog::on_buttonBox_clicked(QAbstractButton *button)
{
    //loggers->push_back(new FileLogger(ui->lineEdit->text().toStdString() + ".txt"));
}

