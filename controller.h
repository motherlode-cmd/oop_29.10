#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "fieldview.h"
#include "player.h"

class Controller
{
public:
    Controller() = default;
    void start(QTableWidget * table, int n, int m);
    void makeMove(QTableWidget * table, int x, int y);
    void newEvent(QTableWidget * table, Event * event, int x, int y);
    int getPlayerHealth();
    QString currentState();

    int getState() const;

private:
    FieldView fieldView;
    Player player;
    Field field;
    int state = 1;
};

#endif // CONTROLLER_H
