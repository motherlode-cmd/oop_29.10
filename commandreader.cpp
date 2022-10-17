#include "commandreader.h"
#include "consolelogger.h"
#include "dialog.h"
#include "filelogger.h"
#include "mediator.h"
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
    Mediator * mediator = new Mediator();
    delete mediator;
    this->controller = controller;
    setup_visual();
    connect(this, SIGNAL(signal()), this, SLOT(state()));
    loggers.push_back(new ConsoleLogger);
    loggers.push_back(new FileLogger("../Mediator/default.txt"));
    loggers.push_back(new FileLogger("../Mediator/default2.txt"));
}

CommandReader::~CommandReader()
{
    delete ui;
}

void CommandReader::on_pushButton_clicked()
{
    startLogger();
    setup_visual();
    controller->start(ui->tableWidget, 5, 5, loggers);
    ui->tableWidget->show();
    ui->progressBar->setValue(controller->getPlayerHealth());
    ui->pushButton->setText(controller->currentState());
    //FileLogger fileLogger("new.txt");
    //std::ofstream outfile("new.txt",std::ofstream::binary);
}

void CommandReader::state()
{
    QPixmap pixmap;
    switch(controller->getState()) {
    case 2:
        pixmap = QPixmap("penisUp.png");
        ui->lineEdit->setText("you win");
        break;
    case 0:
        pixmap = QPixmap("penis.png");
        ui->lineEdit->setText("you lose");
        break;
    default:
        return;
    }
    ui->tableWidget->hide();
    ui->label->setPixmap(pixmap.scaled(500,500));
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
    for(auto logger : loggers) {
        if(controller->getState() == 1)
          controller->logging(logger);
        else if(controller->getState() == 2)
            logger->log("       WIN!\n");
        else
            logger->log("       LOSE\n");
    }
}


void CommandReader::on_comboBox_set_logger_currentTextChanged(const QString &arg1)
{
    Dialog dlg;
    dlg.setLoggers(&loggers);
    dlg.exec();
}

void CommandReader::startLogger()
{
    for(auto logger : loggers) {
        if(controller->getState() == 0) {
            logger->log("\n-----STARTED NEW GAME--------\n");
        } else if(controller->getState() == 1){
            logger->log("\n-----RESTARTED LEVEL--------\n");
        } else {
            logger->log("\n-----STARTED NEW LEVEL--------\n");
        }
    }
}

