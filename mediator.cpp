#include "mediator.h"
#include "QJsonDocument"
#include "QJsonObject"
#include <iostream>
Mediator::Mediator(Controller *controller, CommandReader * commandReader)
{
    readFile();
    this->controller = controller;
    this->commandReader = commandReader;
    commandReader->show();
}

void Mediator::startGame(QTableWidget *t, int x, int y)
{
    controller->start(t,x,y);
}

void Mediator::makeMove(QTableWidget *t, int x, int y)
{
    try {
        if(controller->getStarted())
            controller->makeMove(t,x,y);
        else
            throw(controller->getStarted());
    } catch(bool is) {
        controller->getObserver()->update(Level::Error, "Game not started");
    }
}

void Mediator::keyPressEvent(QKeyEvent *key)
{
    try {
        if(controller->getStarted()) {
            if(up == (key->text())) {
                controller->makeMove(commandReader->get_table(), -1, 0);
            } else if(down == (key->text())) {
                controller->makeMove(commandReader->get_table(), 1, 0);
            } else if(left == (key->text())) {
                controller->makeMove(commandReader->get_table(), 0, -1);
            } else if(right == (key->text())) {
                controller->makeMove(commandReader->get_table(), 0, 1);
            }
            commandReader->setup_game();
        } else {
            throw(controller->getStarted());
        }
    } catch(bool isStart) {
        controller->getObserver()->update(Level::Error, "Game not started");
    }
}

void Mediator::parseData(QString& val)
{
    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    QVariantList array = doc.toVariant().toList();
    for(auto& v : array)
    {
        QJsonObject data = v.toJsonObject();
        up = data["up"].toString();
        down = data["down"].toString();
        left = data["left"].toString();
        right = data["right"].toString();
    }
}

void Mediator::readFile()
{
    QString val;
    QString filename =  "../Mediator/settings.json";
    QFile file(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!file.isOpen()) {
        std::cout<< "Can't open file."<<std::endl;
     }
     val = file.readAll();
     parseData(val);
}
