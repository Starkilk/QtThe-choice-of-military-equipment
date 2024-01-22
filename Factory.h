#ifndef FACTORY_H
#define FACTORY_H
#include <QString>
#include <iostream>
#include "Interface.h"


#endif // FACTORY_H
class Factory{
public:
    Interface *factoryMetod(QString name, double weight, int value, int type){
        switch (type) {
        case 0:
            qDebug() << 1;
            return new Tank(name, weight, value, type);
            break;
        case 1:
            qDebug() << 2;
            return new Plane(name, weight, value, type);
            break;
        case 2:
            qDebug() << 3;
            return new Helicopter(name, weight, value, type);
            break;
        }

    }

};


