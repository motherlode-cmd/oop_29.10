#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "fieldview.h"
#include "generatelevel.h"
#include "logger.h"
#include "player.h"
#include <QObject>

class Controller //: public QObject
{
    //Q_OBJECT
public:
    Controller() = default;
    void start(QTableWidget * table, int n, int m, std::vector <Logger *> & svec);
    void makeMove(QTableWidget * table, int x, int y);
    int getPlayerHealth();
    QString currentState();
    int getState() const;
    void logging( Logger * loger);
    bool getStarted() const;

signals:
    void signal();
private:
//    void log();
    void ntfLggs();
    void exit(QTableWidget *table);
    void checkState(QTableWidget *table);
    void nextLevel(QTableWidget *table);
    FieldView fieldView;
    Player player;
    Field field;
    int state = 1;
    int level = 0;
    bool started = false;
    GenerateLevel generateLevel;
    std::vector <Logger *> loggers;
};

#endif // CONTROLLER_H
