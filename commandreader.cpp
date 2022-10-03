#include "commandreader.h"
#include "eventadd.h"
#include "mediator.h"
#include "ui_commandreader.h"
CommandReader::CommandReader(Controller * controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CommandReader), controller(controller)
{
    ui->setupUi(this);
    Mediator * mediator = new Mediator();
    delete mediator;
    ui->comboBox->hide();
    this->controller = controller;
}

CommandReader::~CommandReader()
{
    delete ui;
}

void CommandReader::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    controller->start(ui->tableWidget, 5, 5);
    ui->progressBar->setValue(controller->getPlayerHealth());
}

void CommandReader::move()
{
    //controller->makeMove(ui->tableWidget, 1, 1);
//    ui->pushButton->setText(controller->currentState());
//    ui->progressBar->setValue(controller->getPlayerHealth());
}


void CommandReader::on_move1_clicked()
{
    //controller->start(ui->tableWidget, 3, 3);
    controller->makeMove(ui->tableWidget, 1, 1);
    ui->pushButton->setText(controller->currentState());
    ui->progressBar->setValue(controller->getPlayerHealth());
}


void CommandReader::on_up_clicked()
{
    controller->makeMove(ui->tableWidget, -1 ,0);
    ui->pushButton->setText(controller->currentState());
    ui->progressBar->setValue(controller->getPlayerHealth());
}


void CommandReader::on_down_clicked()
{
    controller->makeMove(ui->tableWidget, 1, 0);
    ui->pushButton->setText(controller->currentState());
    ui->progressBar->setValue(controller->getPlayerHealth());
}


void CommandReader::on_left_clicked()
{
    controller->makeMove(ui->tableWidget, 0, 1);
    ui->pushButton->setText(controller->currentState());
    ui->progressBar->setValue(controller->getPlayerHealth());
}


void CommandReader::on_right_clicked()
{
    controller->makeMove(ui->tableWidget, 0, -1);
    ui->pushButton->setText(controller->currentState());
    ui->progressBar->setValue(controller->getPlayerHealth());
}


void CommandReader::on_tableWidget_itemSelectionChanged()
{
    ui->progressBar->setValue(controller->getPlayerHealth());
}

void CommandReader::on_progressBar_valueChanged(int value)
{
    if(ui->progressBar->value() == 0) {
        ui->tableWidget->hide();
        delete ui->tableWidget;
        ui->pushButton->setText("over");
    }
}

void CommandReader::on_CellEvent_clicked()
{
    ui->comboBox->show();
    ui->comboBox->setEnabled(true);
    connect(ui->tableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(createNewEventCell(int,int)));
    ui->CellEvent->hide();
    ui->tableWidget->setEnabled(true);
}

void CommandReader::createNewEventCell(int x, int y)
{
    controller->newEvent(ui->tableWidget, new EventAdd(), x, y);
    disconnect(ui->tableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(createNewEventCell(int,int)));
    ui->CellEvent->show();
}


void CommandReader::on_pushButton_2_clicked()
{

}

