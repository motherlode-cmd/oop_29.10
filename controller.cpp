#include "controller.h"



void Controller::start(QTableWidget * table,int n,int m)
{
    Position playerPosition(0,0);
    fieldView.setSize(n, m, table);
    player = Player(playerPosition);
    //field = fieldView.getField();
    //field = Field(n,m);
    //fieldView.setField(field);
}

void Controller::makeMove(int x, int y)
{
    //field.playerMove(x,y,player);
    fieldView.playerMove(x,y,player);
}

void Controller::newEvent(Event *event, int x, int y)
{
    //field.setNewEvent(event, x, y);
    fieldView.createNewEvent(event, x, y);
}

int Controller::getPlayerHealth()
{
    return player.getHealth();
}

QString Controller::currentState()
{
    return QString::number(player.getCurrentPosition().getX()) + " " + QString::number(player.getCurrentPosition().getY());
}

