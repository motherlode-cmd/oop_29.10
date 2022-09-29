#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "fieldview.h"
#include "player.h"
class Controller
{
public:
    Controller() = default;
    void start(QTableWidget * table, int n, int m);
    void makeMove(int x, int y);
    void newEvent(Event * event, int x, int y);
    int getPlayerHealth();
    QString currentState();
private:
    FieldView fieldView;
    Player player;
    //Field field;
};

#endif // CONTROLLER_H
