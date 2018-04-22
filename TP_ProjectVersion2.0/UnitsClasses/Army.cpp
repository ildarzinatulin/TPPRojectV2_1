#include <stdio.h>
#include <vector>
#include "Orcs.cpp"
#include "People.cpp"
#include "Elfs.cpp"


using std::vector;


class ArmyFactory {
public:
    virtual Infantry* makeInfantry() = 0;
    virtual Archers* makeArchers() = 0;
    virtual Wizard* makeWizard() = 0;
    virtual Cavalry* makeCavalry() = 0;
    virtual ~ArmyFactory(){}
};


class OrcsArmyFactory : ArmyFactory{
public:
    Infantry* makeInfantry(){
        return new InfantryOrcs;
    }
    Archers* makeArchers(){
        return new ArchersOrcs;
    }
    Wizard* makeWizard(){
        return new WizardOrcs;
    }
    Cavalry* makeCavalry(){
        return new CavalryOrcs;
    }
};


class PeopleArmyFactory : public ArmyFactory{
public:
    Infantry* makeInfantry(){
        return new InfantryHuman;
    }
    Archers* makeArchers(){
        return new ArchersHuman;
    }
    Cavalry* makeCavalry(){
        return new CavalryHuman;
    }
    Wizard* makeWizard(){
        return new WizardHuman;
    }
};


class ElfsArmyFactory : ArmyFactory{
public:
    Infantry* makeInfantry(){
        return new InfantryElfs;
    }
    Archers* makeArchers(){
        return new ArchersElfs;
    }
    Wizard* makeWizard(){
        return new WizardElfs;
    }
    Cavalry* makeCavalry(){
        return new CavalryElfs;
    }
};

class Army{
public:
    ~Army() {
        for(int i = 0; i < infantries.size(); ++i)  delete infantries[i];
        for(int i = 0; i < archers.size(); ++i)  delete archers[i];
        for(int i = 0; i < wizards.size(); ++i)  delete wizards[i];
        for(int i = 0; i < cavalries.size(); ++i)  delete cavalries[i];
    }
    void info() {
        cout << infantries.size();
        cout << archers.size();
        cout << wizards.size();
        cout << cavalries.size();
    }
    void update(){
        for (int i = 0; i < infantries.size(); i++){
            infantries[i]->improve();
        }
        for (int i = 0; i < archers.size(); i++){
            archers[i]->improve();
        }
        for (int i = 0; i < wizards.size(); i++){
            wizards[i]->improve();
        }
        for (int i = 0; i < cavalries.size(); i++){
            cavalries[i]->improve();
        }
        updateForce();
    }
    
    void updateForce(){
        int nForce = 0;
        for (int i = 0; i < infantries.size(); i++){
            nForce += infantries[i]->Force;
        }
        for (int i = 0; i < archers.size(); i++){
            nForce += archers[i]->Force;
        }
        for (int i = 0; i < wizards.size(); i++){
            nForce += wizards[i]->Force;
        }
        for (int i = 0; i < cavalries.size(); i++){
            nForce += cavalries[i]->Force;
        }
        force = nForce;
    }
    
    void increaseCntOfInfantries(ArmyFactory& factory, int cnt){
        for (int i = 0; i < cnt; i++){
            infantries.push_back(factory.makeInfantry());
            force += infantries[infantries.size() - 1]->Force;
        }
    }
    void increaseCntOfArchers(ArmyFactory& factory, int cnt){
        for (int i = 0; i < cnt; i++){
            archers.push_back(factory.makeArchers());
            force += archers[archers.size() - 1]->Force;
        }
    }
    void increaseCntOfWizards(ArmyFactory& factory, int cnt){
        for (int i = 0; i < cnt; i++){
            wizards.push_back(factory.makeWizard());
            force += wizards[wizards.size() - 1]->Force;
        }
    }
    void increaseCntOfCavalries(ArmyFactory& factory, int cnt){
        for (int i = 0; i < cnt; i++){
            cavalries.push_back(factory.makeCavalry());
            force += cavalries[cavalries.size() - 1]->Force;
        }
    }
    
    vector<Infantry*> infantries;
    vector<Archers*> archers;
    vector<Wizard*> wizards;
    vector<Cavalry*> cavalries;
    
    int force = 0;
    
};

class DecoratorArmy{
public:
    
    Army otherArmy;
    Army thisArmy;
    
    DecoratorArmy(Army previousArmy){
        otherArmy = previousArmy;
    }
    void updateForce(){
        otherArmy.updateForce();
        thisArmy.updateForce();
    }
    
};

class ArmyCreator{
public:
    Army* create(ArmyFactory& factory){
        Army * newArmy = new Army;
        for (int i = 0; i < 5; i++){
            newArmy -> infantries.push_back(factory.makeInfantry());
            newArmy -> archers.push_back(factory.makeArchers());
            newArmy -> wizards.push_back(factory.makeWizard());
            newArmy -> cavalries.push_back(factory.makeCavalry());
        }
        return newArmy;
    }
    
};
