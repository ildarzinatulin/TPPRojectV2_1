#include <stdio.h>

class Castle{
public:
    float defense = 0.75;
    int capacity = 50;
    int taxis = 100;
};

class CastleDecorator{
public:
    Castle *mCastle;
    CastleDecorator(){
        mCastle = new Castle();
    }
};

class CastleDefender : public CastleDecorator{
public:
    CastleDefender(CastleDecorator *castle){
        mCastle = castle->mCastle;
        mCastle->defense = 0.95;
    }
    
};

class CastleBig : public CastleDecorator{
public:
    CastleBig(CastleDecorator *castle){
        mCastle = castle->mCastle;
        mCastle->capacity = 120;
    }
};

class CastleRich : public CastleDecorator{
public:
    CastleRich(CastleDecorator *castle){
        mCastle = castle->mCastle;
        mCastle->taxis = 200;
    }
};

