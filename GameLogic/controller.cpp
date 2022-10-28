#include "controller.h"
#include "./Events/EventField/eventField.h"
#include "./Events/EventPlayer/eventPlayer.h"
#include "./Logger/filelogger.h"
#include "Logger/consolelogger.h"
#include "generatelevel.h"
#include "./Observer/loggerobserver.h"

Controller::Controller()
{
    obs = new LoggerObserver();
    obs->addLogger(new ConsoleLogger());
    FileLogger * ofs = new FileLogger("../Mediator/newTest.txt");
    obs->addLogger(ofs);
    field.setObs(obs);
    player.setObs(obs);
    generateLevel.setEventObs(obs);
}

Controller::~Controller()
{
    obs->update(Level::Info,"Exit game");
    delete obs;
}

void Controller::start(QTableWidget * table, int n, int m)
{
    started = true;
    state = 1;
    field = Field(n + level, m + level);
    if(n > 0 && m > 0){
        obs->update(Level::Info,"Started new game");
        player = HumanPlayer(field.getPositionPlayer());
        nextLevel(table);
    } else {
        obs->update(Level::Error,"invalid size for field");
    }
}

void Controller::makeMove(QTableWidget * table, int x, int y)
{
    try {
        if(field.getHeight() > 0 && field.getWidth() > 0) {
            field.playerMove(x, y);
            player.makeMove(field.getPositionPlayer());
            if(field.getCurrentEvent() == dynamic_cast<EventField *>(field.getCurrentEvent()))
                ((EventField *)field.getCurrentEvent())->newField(field);
            else if(field.getCurrentEvent() == dynamic_cast<EventPlayer *>(field.getCurrentEvent()))
               ((EventPlayer *)field.getCurrentEvent())->makeAction(player);
            checkState();
            fieldView.drowField(field, table);
        } else {
            throw(field.getHeight());
        }
    } catch(int a) {
        obs->update(Level::Error, "Invalid Game, can't move");
    }
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

void Controller::checkState()
{
    if(player.keyState()) {
        field.unlockWin();
    }
    if(field.isWin()) {
        state = 2;
        level++;
        started = false;
    }
    if(player.getHealth() == 0){
        state = 0;
        level = 0;
        started = 0;
    }
}

void Controller::nextLevel(QTableWidget * table)
{
    if(field.getHeight() > 0 && field.getWidth() > 0) {
        generateLevel.generateLevel(field);
        fieldView = FieldView(field, table);
    }
}

bool Controller::getStarted() const
{
    return started;
}

void Controller::deleteLevel(Level level)
{
    obs->deleteLevel(level);
}

void Controller::addLevel(Level level)
{
    obs->addLevel(level);
}


