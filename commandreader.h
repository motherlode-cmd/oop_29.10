#ifndef COMMANDREADER_H
#define COMMANDREADER_H
#include "controller.h"
#include "qbuttongroup.h"
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

private:
    void setup_visual();
    void setup_game();
    Ui::CommandReader *ui;
    Controller * controller;
};
#endif // COMMANDREADER_H
