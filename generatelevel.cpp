#include "generatelevel.h"
#include <cstdlib>

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
        if(i % 2 == 0)field.setNewEvent(eventAdd, rand() % h, rand() % w);
        field.setNewEvent(eventUnlock, rand() % h, rand() % w);
        field.setNewEvent(eventLock, rand() % h, rand() % w);
    }
    field.setNewEvent(eventWin, rand() % h, rand() % w);
}
