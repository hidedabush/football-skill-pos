#ifndef QUARTERBACK_H
#define QUARTERBACK_H

#include "FootballPlayer.h"

class Quarterback : public FootballPlayer {
private:
    int passingYd;
    int passingTd;

public:
    Quarterback() : FootballPlayer(), passingYd(0), passingTd(0) {}

    Quarterback(string n, int a, string h, int w, int py, int pt) 
        : FootballPlayer(n, a, h, w), passingYd(py), passingTd(pt) {}

    void setPlayer(string n, int a, string h, int w,int s1, int s2) override {
        FootballPlayer::setPlayer(n, a, h, w, s1, s2);
        passingYd = s1;
        passingTd = s2;
    }

    void printInfo() override {
        FootballPlayer::printInfo();
        cout << "Passing Yards: " << passingYd << ", Passing Touchdowns: " << passingTd << endl;
    }

    virtual ~Quarterback() = default;
    int getStat1()override {return passingYd;}
    int getStat2()override {return passingTd;}
};

#endif
