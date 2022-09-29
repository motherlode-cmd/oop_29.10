#include "commandreader.h"
#include "eventadd.h"
#include "mediator.h"
#include "ui_commandreader.h"
CommandReader::CommandReader(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CommandReader)
{
    ui->setupUi(this);
    //controller = Controller(ui->tableWidget, 3, 3);
    Mediator * mediator = new Mediator();
    delete mediator;
    //delete controller;
    //fieldView.setSize(3,3, ui->tableWidget);
    //FieldView nfieldView(5,5, ui->tableWidget);
    //fieldView = nfieldView;
}

CommandReader::~CommandReader()
{
    delete ui;
}

void CommandReader::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    //FieldView newField(3,3,ui->tableWidget);
    //fieldView = newField;
    controller.start(ui->tableWidget, 3, 3);
    ui->progressBar->setValue(controller.getPlayerHealth());
}

void CommandReader::move()
{
    controller.makeMove(1,1);
    ui->pushButton->setText(controller.currentState());
    ui->progressBar->setValue(controller.getPlayerHealth());
}


void CommandReader::on_move1_clicked()
{
    controller.makeMove(1,1);
    ui->pushButton->setText(controller.currentState());
    ui->progressBar->setValue(controller.getPlayerHealth());
}


void CommandReader::on_up_clicked()
{
    controller.makeMove(-1,0);
    ui->pushButton->setText(controller.currentState());
    ui->progressBar->setValue(controller.getPlayerHealth());
}


void CommandReader::on_down_clicked()
{
    controller.makeMove(1,0);
    ui->pushButton->setText(controller.currentState());
    ui->progressBar->setValue(controller.getPlayerHealth());
}


void CommandReader::on_left_clicked()
{
    controller.makeMove(0,1);
    ui->pushButton->setText(controller.currentState());
    ui->progressBar->setValue(controller.getPlayerHealth());
}


void CommandReader::on_right_clicked()
{
    controller.makeMove(0,-1);
    ui->pushButton->setText(controller.currentState());
    ui->progressBar->setValue(controller.getPlayerHealth());
}


void CommandReader::on_tableWidget_itemSelectionChanged()
{
    ui->progressBar->setValue(controller.getPlayerHealth());
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
    connect(ui->tableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(createNewEventCell(int,int)));
    ui->CellEvent->hide();
    ui->tableWidget->setEnabled(true);
}

void CommandReader::createNewEventCell(int x, int y)
{
    controller.newEvent(new EventAdd(), x, y);
    disconnect(ui->tableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(createNewEventCell(int,int)));
    ui->CellEvent->show();
}


void CommandReader::on_pushButton_2_clicked()
{

}

