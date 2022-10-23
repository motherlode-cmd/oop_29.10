#include "commandreader.h"
#include "dialog.h"
#include "ui_commandreader.h"
#include "QStandardItem"
#include "QFile"
#include "QList"
#include <QButtonGroup>
CommandReader::CommandReader(Controller * controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CommandReader), controller(controller)
{
    ui->setupUi(this);
    this->controller = controller;
    setup_visual();
    connect(this, SIGNAL(signal()), this, SLOT(state()));
    lockButtons(false);
}

CommandReader::~CommandReader()
{
    delete ui;
}

void CommandReader::on_pushButton_clicked()
{
    setup_visual();
    controller->start(ui->tableWidget, ui->spinBox->value(), ui->spinBox_2->value()/*, loggers*/);
    ui->tableWidget->show();
    ui->progressBar->setValue(controller->getPlayerHealth());
    ui->pushButton->setText(controller->currentState());
    lockButtons(true);
}

void CommandReader::state()
{
    QPixmap pixmap;
    switch(controller->getState()) {
    case 2:
        ui->lineEdit->setText("you win");
        break;
    case 0:
        ui->lineEdit->setText("you lose");
        break;
    default:
        return;
    }
    ui->tableWidget->hide();
    ui->label->show();
    ui->lineEdit->show();
    ui->pushButton->setText("start new level");
    ui->pushButton->setEnabled(true);
}
void CommandReader::on_up_clicked()
{
    controller->makeMove(ui->tableWidget, -1 ,0);
    setup_game();
}

void CommandReader::on_down_clicked()
{
    controller->makeMove(ui->tableWidget, 1, 0);
    setup_game();
}


void CommandReader::on_left_clicked()
{
    controller->makeMove(ui->tableWidget, 0, 1);
    setup_game();
}


void CommandReader::on_right_clicked()
{
    controller->makeMove(ui->tableWidget, 0, -1);
    setup_game();
}

void CommandReader::on_tableWidget_itemSelectionChanged()
{
    ui->progressBar->setValue(controller->getPlayerHealth());
}

void CommandReader::setup_visual()
{
    ui->comboBox->hide();
    ui->lineEdit->hide();
    ui->label->hide();
}

void CommandReader::setup_game()
{
    ui->pushButton->setText(controller->currentState());
    ui->progressBar->setValue(controller->getPlayerHealth());
    emit signal();
}


void CommandReader::on_pushButton_logger_clicked()
{
    Dialog dlg;
    dlg.getObs(controller->getObserver());
    dlg.exec();
}

void CommandReader::lockButtons(bool l)
{
    ui->up->setEnabled(l);
    ui->down->setEnabled(l);
    ui->right->setEnabled(l);
    ui->left->setEnabled(l);
}



//void CommandReader::on_comboBox_set_logger_Level_currentIndexChanged(int index)
//{
//    switch (index) {
//    case 0:
//        controller->setLevel(Level::Info);
//        break;
//    case 1:
//        controller->setLevel(Level::State);
//        break;
//    case 2:
//        controller->setLevel(Level::Error);
//        break;
//    }
//}


void CommandReader::on_checkBox_info_stateChanged(int arg1)
{
    if(arg1 == 0){
        controller->deleteLevel(Level::Info);
    } else
        controller->addLevel(Level::Info);
}


void CommandReader::on_checkBox_state_stateChanged(int arg1)
{
    if(arg1 == 0){
        controller->deleteLevel(Level::State);
    } else
        controller->addLevel(Level::State);

}


void CommandReader::on_checkBox_Error_stateChanged(int arg1)
{
    if(arg1 == 0){
        controller->deleteLevel(Level::Error);
    } else
        controller->addLevel(Level::Error);
}

