//классы армии орков (орки более выносливые, средняя система прокачки)


#include <stdio.h>
#include <iostream>
#include "BasicUnit.cpp"


using std::cout;


class InfantryOrcs : public Infantry{
public:
    void improve(){
        Health = maxHealth;
        maxMana = maxMana * 3;
        Mana = maxMana;
    }
    InfantryOrcs(){
        maxHealth = 50;
        maxMana = 75;
        Health = 50;
        Mana = 75;
        Force = 50;
    }
    
    ~InfantryOrcs(){}
};


class ArchersOrcs : public Archers{
public:
    void improve(){
        Health = maxHealth;
        Mana = maxMana;
        Force = Force * 3;
    }
    ArchersOrcs(){
        maxHealth = 50;
        maxMana = 75;
        Health = 50;
        Mana = 75;
        Force = 75;
    }
    
    ~ArchersOrcs(){}
};


class WizardOrcs : public Wizard{
public:
    void improve(){
        maxHealth = maxHealth * 3;
        Health = maxHealth;
        Mana = maxMana;
    }
    WizardOrcs(){
        maxHealth = 75;
        maxMana = 75;
        Health = 75;
        Mana = 75;
        Force = 50;        
    }
    
    ~WizardOrcs(){}
};


class CavalryOrcs : public Cavalry{
public:
    void improve(){
        maxHealth = maxHealth * 3;
        Health = maxHealth;
        Mana = maxMana;
    }
    CavalryOrcs(){
        maxHealth = 50;
        maxMana = 100;
        Health = 50;
        Mana = 100;
        Force = 75;
    }
    ~CavalryOrcs(){}
};
