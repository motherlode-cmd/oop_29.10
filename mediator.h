#ifndef MEDIATOR_H
#define MEDIATOR_H
#include "commandreader.h"
#include "controller.h"
class Mediator
{
public:
    //Mediator(CommandReader * commandTranslater, Controller * controller);
    Mediator() = default;
private:
    CommandReader * commandTranslater;
    Controller * controller;
};

#endif // MEDIATOR_H
