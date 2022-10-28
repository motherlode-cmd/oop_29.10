#ifndef COMMANDREADER_H
#define COMMANDREADER_H
#include "MediatorInterface.h"
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
    void addMediator(MediatorInterface * m);
    QTableWidget * get_table();
signals:
    void signal();
public slots:
    void keyPressEvent(QKeyEvent * e);

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

    void setup_game();
private:
    void lockButtons(bool l);
    void setup_visual();
    Ui::CommandReader *ui;
    MediatorInterface * mediator = nullptr;
};

inline void CommandReader::keyPressEvent(QKeyEvent *e)
{
    try{
        mediator->keyPressEvent(e);
    } catch(...) {

    }
}
#endif // COMMANDREADER_H
