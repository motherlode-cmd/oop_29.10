#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../Views/fieldview.h"
#include "generatelevel.h"
#include "humanPlayer.h"
#include <QObject>

class Controller
{
public:
    Controller();
    ~Controller();
    void start(QTableWidget * table, int n = 3, int m = 3/*, std::vector <Logger *> & svec*/);
    void makeMove(QTableWidget * table, int x, int y);
    int getPlayerHealth();
    QString currentState();
    int getState() const;
    bool getStarted() const;
    void addLevel(Level level);
    void deleteLevel(Level level);
    Observer * getObserver(){return obs;}
signals:
    void signal();
private:
    void ntfLggs();
    void checkState();
    void nextLevel(QTableWidget *table);
    FieldView fieldView;
    HumanPlayer player;
    Field field;
    int state = 1;
    int level = 0;
    bool started = false;
    GenerateLevel generateLevel;
    Observer * obs;
    //std::vector <Logger *> loggers;
};

#endif // CONTROLLER_H
