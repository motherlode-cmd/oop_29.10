#include "dialog.h"
#include "ui_dialog.h"
#include "Logger/Logger.h"
#include "Logger/consolelogger.h"
#include "Logger/filelogger.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //ui->lineEdit->hide();
    //ui->lineEdit->setEnabled(false);
    ui->comboBox_2->hide();
}

Dialog::~Dialog()
{
    obs = nullptr;
    delete ui;
}

void Dialog::getObs(Observer * obs)
{
    if(obs != nullptr)
        this->obs = obs;
}

void Dialog::on_buttonBox_clicked(QAbstractButton * button)
{
    Logger * logger;
    switch (ui->comboBox->currentIndex()) {
    case 0:
        if(obs != nullptr){
            logger = new FileLogger(("../Mediator/" + ui->lineEdit->text() + ".txt").toStdString());
            obs->addLogger(logger);
        }
        break;
    case 1:
        if(obs != nullptr){
            logger = new ConsoleLogger();
            obs->addLogger(logger);
        }
        break;
    case 2:
        if(obs != nullptr){
            logger = new ConsoleLogger();
            obs->deleteLogger(logger);
        }
        break;
    }
}

void Dialog::on_comboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        ui->lineEdit->show();
        ui->lineEdit->setEnabled(true);
        ui->comboBox_2->show();
        isCreate = true;
        break;
    case 1:
        ui->lineEdit->hide();
        ui->lineEdit->setEnabled(false);
        ui->comboBox_2->hide();
        isCreate = true;
        break;
    case 2:
        ui->lineEdit->hide();
        ui->lineEdit->setEnabled(false);
        ui->comboBox_2->hide();
        isCreate = false;
        break;
    }
}

bool Dialog::getIsCreate() const
{
    return isCreate;
}



