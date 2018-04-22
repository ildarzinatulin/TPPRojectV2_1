//классы армии Эльфов (изначально более сильные, имеют слабую систему прокачки)


#include <stdio.h>
#include <iostream>
#include "BasicUnit.cpp"


using std::cout;


class InfantryElfs : public Infantry{
public:
    void improve(){
        maxMana = maxMana * 4;
        Health = maxHealth;
        Mana = maxMana;
    }
    InfantryElfs(){
        maxHealth = 50;
        maxMana = 75;
        Health = 50;
        Mana = 75;
        Force = 50;
    }
    ~InfantryElfs(){}
};


class ArchersElfs : public Archers{
public:
    void improve(){
        Health = maxHealth;
        Mana = maxMana;
        Force = Force * 2;
    }
    ArchersElfs(){
        maxHealth = 50;
        maxMana = 75;
        Health = 50;
        Mana = 75;
        Force = 75;
    }
    
    ~ArchersElfs(){}
};


class WizardElfs : public Wizard{
public:
    virtual void improve(){
        maxHealth = maxHealth * 2;
        Health = maxHealth;
        Mana = maxMana;
    }
    WizardElfs(){
        maxHealth = 75;
        maxMana = 75;
        Health = 75;
        Mana = 75;
        Force = 50;
    }
    
    ~WizardElfs(){}
};


class CavalryElfs : public Cavalry{
public:
    void improve(){
        maxHealth = maxHealth * 2;
        Health = maxHealth;
        Mana = maxMana;
    }
    CavalryElfs(){
        maxHealth = 100;
        maxMana = 75;
        Health = 100;
        Mana = 75;
        Force = 100;
    }
    ~CavalryElfs(){}
};
