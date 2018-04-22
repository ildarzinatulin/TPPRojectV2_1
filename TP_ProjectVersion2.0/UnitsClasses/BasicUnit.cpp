#include <stdio.h>

#ifndef BasicUnit_CPP
#define BasicUnit_CPP

//Базывай класс всего
class BasicUnit{
public:
    int Health = 0;
    int maxHealth = 0;
    int Mana = 0;
    int maxMana = 0;
    int Force = 0;
    virtual void improve() = 0;
    virtual ~BasicUnit(){}
};

//Базовые типы
class Infantry : public BasicUnit{
public:
    virtual void improve() = 0;
    virtual ~Infantry(){}
};

class Archers : public BasicUnit{
public:
    virtual void improve() = 0;
    virtual ~Archers(){}
};

class Wizard : public BasicUnit{
public:
    virtual void improve() = 0;
    virtual ~Wizard(){}
};

class Cavalry : public BasicUnit{
public:
    virtual void improve() = 0;
    virtual ~Cavalry(){}
};

#endif BasicUnit_CPP
