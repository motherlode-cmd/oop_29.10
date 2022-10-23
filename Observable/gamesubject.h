#ifndef GAMESUBJECT_H
#define GAMESUBJECT_H
#include "Observable.h"

class GameSubject : public Observable
{
public:
    GameSubject();
    ~GameSubject();
    void setObs(Observer * obs) override {
        if(obs != nullptr)
            this->obs = obs;
    }
    void notify(Level level, std::string str) override {
        obs->update(level, str);
    }
protected:
    Observer * obs;
};
#endif // GAMESUBJECT_H
