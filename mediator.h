#ifndef MEDIATOR_H
#define MEDIATOR_H
#include "./GameLogic/controller.h"
#include "commandreader.h"
#include "MediatorInterface.h"
#include <QObject>
#include <QKeyEvent>
class Mediator : public MediatorInterface
{
public:
    Mediator(Controller * controller, CommandReader * commandReader);
    void startGame(QTableWidget * t, int x, int y) override;
    void makeMove(QTableWidget * t, int x, int y) override;
    int getPlayerHealth() override {return controller->getPlayerHealth();}
    int getState() override {return controller->getState();}
    Observer * getObserver() override {return controller->getObserver();}
    void addLevel(Level level) override {controller->addLevel(level);}
    void deleteLevel(Level level) override {controller->deleteLevel(level);}
    void keyPressEvent(QKeyEvent * key) override;
protected:
private:
    void parseData(QString & val);
    void readFile();
    Controller * controller;
    CommandReader * commandReader;
    QString up;
    QString down;
    QString left;
    QString right;
};

#endif // MEDIATOR_H
