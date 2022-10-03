#ifndef MEDIATOR_H
#define MEDIATOR_H
#include "controller.h"
class Mediator
{
public:
    Mediator() = default;
private:
    Controller * controller;
};

#endif // MEDIATOR_H
