#ifndef INTERFACE_H
#define INTERFACE_H


#endif // INTERFACE_H


#include <QString>
#include <iostream>

class Interface{

};

///////////////
class Tank: public Interface{
private:
    QString name;
    double weight;
    int crew;
    int type;

public:
    Tank(QString name,double weight,int crew,int type)
    {
        this->name = name;
        this->weight = weight;
        this->crew = crew;
        this->type = type;
    }


};


///////////////
class Helicopter: public Interface{
private:
    QString name;
    double weight;
    int flightRange;
    int type;

public:
    Helicopter(QString name,double weight,int flightRange,int type){
        this->name = name;
        this->weight = weight;
        this->flightRange = flightRange;
        this->type = type;
    }
};


///////////////
class Plane: public Interface{
private:
    QString name;
    double weight;
    int flightRange;
    int type;

public:
    Plane(QString name,double weight,int flightRange, int type){
        this->name = name;
        this->weight = weight;
        this->flightRange = flightRange;
        this->type = type;
    }
};



