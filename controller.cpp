#include "controller.h"

void Controller::start(QTableWidget * table, int n, int m)
{
    Position playerPosition(0,0);
    field = Field(n,m);
    player = Player(playerPosition);
    //table = new QTableWidget();
    fieldView = FieldView(field, table);
}

void Controller::makeMove(QTableWidget * table, int x, int y)
{
    field.playerMove(x, y, player);
    fieldView.drowField(field, table);
}

void Controller::newEvent(QTableWidget *table, Event *event, int x, int y)
{
    field.setNewEvent(event, x, y);
    fieldView.drowField(field, table);
}

int Controller::getPlayerHealth()
{
    return player.getHealth();
}

QString Controller::currentState()
{
    return QString::number(player.getCurrentPosition().getX()) + " " + QString::number(player.getCurrentPosition().getY());
}

