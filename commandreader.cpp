#include "commandreader.h"
#include "dialog.h"
#include "ui_commandreader.h"
#include "QStandardItem"
#include "QFile"
#include "QList"
#include <QButtonGroup>
CommandReader::CommandReader(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CommandReader)
{
    //connect(mediator, SIGNAL(send_to_gui(bool)), this, SLOT(get_from_object(bool)));
    ui->setupUi(this);
    //this->mediator = mediator;
    setup_visual();
    connect(this, SIGNAL(signal()), this, SLOT(state()));
    lockButtons(false);
    ui->tableWidget->setTabKeyNavigation(false);
    //ui->tableWidget->show();
}

CommandReader::~CommandReader()
{
    delete ui;
}

void CommandReader::addMediator(MediatorInterface *m)
{
    mediator = m;
    //connect(this, SIGNAL(keyPressEvent(QKeyEvent*)), mediator, SLOT(keyPressEvent(QKeyEvent*)));
}

QTableWidget *CommandReader::get_table()
{
    return ui->tableWidget;
}

void CommandReader::on_pushButton_clicked()
{
    setup_visual();
    mediator->startGame(ui->tableWidget, ui->spinBox->value(), ui->spinBox_2->value()/*, loggers*/);
    ui->tableWidget->show();
    ui->progressBar->setValue(mediator->getPlayerHealth());
    lockButtons(true);
}

void CommandReader::state()
{
    QPixmap pixmap;
    switch(mediator->getState()) {
    case 2:
        pixmap = QPixmap("winner.png");
        ui->lineEdit->setText("you win");
        break;
    case 0:
        pixmap = QPixmap("loser.png");
        ui->lineEdit->setText("you lose");
        break;
    default:
        ui->progressBar->setValue(mediator->getPlayerHealth());
        return;
    }

    ui->tableWidget->hide();
    ui->label->show();
    ui->lineEdit->show();
    pixmap.scaled(700,600);
    ui->label->setPixmap(pixmap);
    ui->pushButton->setText("start new level");
    ui->pushButton->setEnabled(true);
}
void CommandReader::on_up_clicked()
{
    //mediator->makeMove(ui->tableWidget, -1 ,0);
    mediator->makeMove(ui->tableWidget, -1, 0);
    setup_game();
}

void CommandReader::on_down_clicked()
{
    mediator->makeMove(ui->tableWidget, 1, 0);
    setup_game();
}


void CommandReader::on_left_clicked()
{
    mediator->makeMove(ui->tableWidget, 0, 1);
    setup_game();
}


void CommandReader::on_right_clicked()
{
    mediator->makeMove(ui->tableWidget, 0, -1);
    setup_game();
}

void CommandReader::on_tableWidget_itemSelectionChanged()
{
    ui->progressBar->setValue(mediator->getPlayerHealth());
}

void CommandReader::setup_visual()
{
    ui->comboBox->hide();
    ui->lineEdit->hide();
    ui->label->hide();
}

void CommandReader::setup_game()
{
    emit signal();
}


void CommandReader::on_pushButton_logger_clicked()
{
    Dialog dlg;
    dlg.getObs(mediator->getObserver());
    dlg.exec();
}

void CommandReader::lockButtons(bool l)
{
    ui->up->setEnabled(l);
    ui->down->setEnabled(l);
    ui->right->setEnabled(l);
    ui->left->setEnabled(l);
}

void CommandReader::on_checkBox_info_stateChanged(int arg1)
{
    if(arg1 == 0){
        mediator->deleteLevel(Level::Info);
    } else
        mediator->addLevel(Level::Info);
}


void CommandReader::on_checkBox_state_stateChanged(int arg1)
{
    if(arg1 == 0){
        mediator->deleteLevel(Level::State);
    } else
        mediator->addLevel(Level::State);

}


void CommandReader::on_checkBox_Error_stateChanged(int arg1)
{
    if(arg1 == 0){
        mediator->deleteLevel(Level::Error);
    } else
        mediator->addLevel(Level::Error);
}

