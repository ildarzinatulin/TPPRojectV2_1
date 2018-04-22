//классы армии людей   (имеют более крутую систему прокачки, но изначально слабее)


#include <stdio.h>
#include <iostream>
#include "BasicUnit.cpp"


using std::cout;


class InfantryHuman : public Infantry{
public:
    void improve(){
        maxMana = maxMana * 4;
        Health = maxHealth;
        Mana = maxMana;
    }
    InfantryHuman(){
        maxHealth = 25;
        maxMana = 50;
        Health = 25;
        Mana = 50;
        Force = 25;
    }
    ~InfantryHuman(){}
};


class ArchersHuman : public Archers{
public:
    void improve(){
        Health = maxHealth;
        Mana = maxMana;
        Force = Force * 4;
    }
    ArchersHuman(){
        maxHealth = 25;
        maxMana = 50;
        Health = 25;
        Mana = 50;
        Force = 25;
    }
    
    ~ArchersHuman(){}
};


class WizardHuman : public Wizard{
public:
    void improve(){
        maxHealth = maxHealth * 4;
        Health = maxHealth;
        Mana = maxMana;
    }
    WizardHuman(){
        maxHealth = 50;
        maxMana = 50;
        Health = 50;
        Mana = 50;
        Force = 25;
    }
    
    ~WizardHuman(){}
};


class CavalryHuman : public Cavalry{
public:
    void improve(){
        maxHealth = maxHealth * 4;
        Health = maxHealth;
        Mana = maxMana;
    }
    CavalryHuman(){
        maxHealth = 50;
        maxMana = 75;
        Health = 50;
        Mana = 75;
        Force = 75;
    }
    ~CavalryHuman(){}
};
