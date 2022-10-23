#include "generatelevel.h"
#include <cstdlib>
#include "math.h"
GenerateLevel::GenerateLevel()
{

}

GenerateLevel::~GenerateLevel()
{
    delete eventAdd;
    delete eventNone;
    delete eventLock;
    delete eventUnlock;
    delete eventWin;
    delete eventKey;
}

void GenerateLevel::setEventObs(Observer *obs)
{
    eventAdd->setObs(obs);
    eventNone->setObs(obs);
    eventLock->setObs(obs);
    eventUnlock->setObs(obs);
    eventWin->setObs(obs);
    eventKey->setObs(obs);
}

void GenerateLevel::generateLevel(Field & field)
{
    int h = field.getHeight();
    int w = field.getWidth();
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            field.setNewEvent(eventNone, i, j);
        }
    }
    for(int i = 0; i < h; i++) {
        if(i % 2 == 0)field.setNewEvent(eventAdd, abs(rand()) % h, abs(rand()) % w);
        field.setNewEvent(eventUnlock, abs(rand()) % h, abs(rand()) % w);
        field.setNewEvent(eventLock, abs(rand()) % h, abs(rand()) % w);
    }
    int xWin = abs(rand()) % h;
    int yWin = abs(rand()) % w;
    field.setCell(xWin, yWin, Cell(eventWin, Position(xWin, yWin), false));
    int xKey = abs(rand()) % h;
    int yKey = abs(rand()) % w;
    field.setCell(xKey, yKey, Cell(eventKey, Position(xKey, yKey), true));
    field.setPositionWin(xWin, yWin);
}
