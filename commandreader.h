#ifndef COMMANDREADER_H
#define COMMANDREADER_H
#include "controller.h"
//#include "mediator.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CommandReader; }
QT_END_NAMESPACE

class CommandReader : public QMainWindow
{
    Q_OBJECT

public:
    CommandReader(QWidget *parent = nullptr);
    ~CommandReader();
    //void copyTable1(QTableView * table);
    //CommandReader(CommandReader & newCommandReder);

private slots:
    void on_pushButton_clicked();

    void move();

    void on_move1_clicked();

    void on_up_clicked();

    void on_down_clicked();

    void on_left_clicked();

    void on_right_clicked();

    void on_tableWidget_itemSelectionChanged();

    void on_progressBar_valueChanged(int value);

    void on_CellEvent_clicked();

    void createNewEventCell(int x, int y);

    void on_pushButton_2_clicked();

private:
    Ui::CommandReader *ui;
    //Mediator * mediator;
    Controller * controller;
};
#endif // COMMANDREADER_H
