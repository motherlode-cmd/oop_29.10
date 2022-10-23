#ifndef COMMANDREADER_H
#define COMMANDREADER_H
#include "./GameLogic/controller.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CommandReader; }
QT_END_NAMESPACE

class CommandReader : public QMainWindow
{
    Q_OBJECT

public:
    CommandReader(Controller * controller = nullptr, QWidget *parent = nullptr);
    ~CommandReader();
signals:
    void signal();

private slots:
    void on_pushButton_clicked();

    void state();

    void on_up_clicked();

    void on_down_clicked();

    void on_left_clicked();

    void on_right_clicked();

    void on_tableWidget_itemSelectionChanged();

    void on_pushButton_logger_clicked();


    void on_checkBox_info_stateChanged(int arg1);

    void on_checkBox_state_stateChanged(int arg1);

    void on_checkBox_Error_stateChanged(int arg1);

private:
    void lockButtons(bool l);
    void setup_visual();
    void setup_game();
    Ui::CommandReader *ui;
    //Logger * logger = new FileLogger("../Mediator/default.txt");
    //Logger * logger = new ConsoleLogger();
    //std::vector <Logger *> loggers;
    //FileLogger fileLogger("new.txt");
    Controller * controller;
};
#endif // COMMANDREADER_H
