#include <iostream>
#include "UnitsClasses/Army.cpp"
#include "WorldsElements/Castles.cpp"

int main() {
    
    ArmyCreator creator;
    PeopleArmyFactory peopleFactory;
    OrcsArmyFactory orcsFactory;
    ElfsArmyFactory elfsFactory;
    
    Army *people = creator.create(peopleFactory);
    people->update();
    people->increaseCntOfArchers(peopleFactory, 100);
    
    CastleDecorator *castle = new CastleDecorator();
    castle = new CastleBig(castle);
    castle = new CastleRich(castle); //make rich and big castle
    
    delete people;
    delete castle;
    
    return 0;
}
