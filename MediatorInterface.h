#ifndef MEDIATORINTERFACE_H
#define MEDIATORINTERFACE_H
#include "Observer/Observer.h"
#include "qtablewidget.h"
class MediatorInterface : public QObject {
public:
    virtual void startGame(QTableWidget * t, int x, int y) = 0;
    virtual void makeMove(QTableWidget * t, int x, int y) = 0;
    virtual int getPlayerHealth() = 0;
    virtual int getState() = 0;
    virtual Observer * getObserver() = 0;
    virtual void addLevel(Level level) = 0;
    virtual void deleteLevel(Level level) = 0;
    virtual void keyPressEvent(QKeyEvent * key) = 0;
protected:
};
#endif // MEDIATORINTERFACE_H
