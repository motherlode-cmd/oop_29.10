#include "controller.h"
#include "eventlock.h"
#include "eventunlock.h"
#include "eventwin.h"

void Controller::start(QTableWidget * table, int n, int m)
{
    Position playerPosition(0,0);
    field = Field(n,m);
    player = Player(playerPosition);
    field.setNewEvent(new EventUnlock(), 1, 1);
    field.setNewEvent(new EventLock(), 0, 1);
    field.setNewEvent(new EventWin(), 2, 2);
    fieldView = FieldView(field, table);
    state = 1;
}

void Controller::makeMove(QTableWidget * table, int x, int y)
{
    field.playerMove(x, y, player);
    player.makeMove(field.getPositionPlayer());
    if(field.getWidth() == table->columnCount() && field.getHeight() == table->rowCount())
        fieldView.drowField(field, table);
    else
        fieldView = FieldView(field, table);
    if(player.getHealth() == 0){ state = 0;}
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

int Controller::getState() const
{
    return state;
}

