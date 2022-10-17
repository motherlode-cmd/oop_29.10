#include "controller.h"
#include "eventField.h"
#include "eventPlayer.h"
#include "generatelevel.h"
#include "logger.h"

void Controller::start(QTableWidget * table, int n, int m, std::vector<Logger *> & vec)
{
    loggers =  vec;
    started = true;
    state = 1;
    field = Field(n + level,m + level);
    player = Player(field.getPositionPlayer());
    nextLevel(table);
}

void Controller::makeMove(QTableWidget * table, int x, int y)
{
    field.playerMove(x, y);
    player.makeMove(field.getPositionPlayer());
    //log();
    if(field.getCurrentEvent() == dynamic_cast<EventField *>(field.getCurrentEvent()))
        ((EventField *)field.getCurrentEvent())->newField(field);
    else
       ((EventPlayer *)field.getCurrentEvent())->makeAction(player);
    checkState(table);
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

void Controller::logging(Logger * loger)
{
    loger->log(field);
    loger->log("\n");
    loger->log(*field.getCurrentEvent());
    loger->log("\n");
    loger->log(player);
    loger->log("\n");
}

//void Controller::log()
//{
//    if(logger != nullptr){
//        logger->log(player);
//        logger->log(field);
//        logger->log(field.getCurrentEvent());
//    }
//}

void Controller::exit(QTableWidget *table)
{
    field = Field(0,0);
    fieldView = FieldView(field, table);
}
//условия для выхода (найти ключ)
//приверка на валидность уровня

void Controller::checkState(QTableWidget *table)
{
    if(player.keyState()) {
        field.unlockWin();
    }
    if(field.getHeight() == 1 && field.getWidth() == 1 && player.keyState()) {
        exit(table);
        state = 2;
        level++;
    }
    if(player.getHealth() == 0){
        state = 0;
        level = 0;
    }
}

void Controller::nextLevel(QTableWidget * table)
{
    generateLevel.generateLevel(field);
    fieldView = FieldView(field, table);
}

bool Controller::getStarted() const
{
    return started;
}


