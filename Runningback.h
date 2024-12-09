#ifndef RUNNINGBACK_H
#define RUNNINGBACK_H

#include "FootballPlayer.h"

class Runningback : public FootballPlayer {
private:
    int rushingYd;
    int rushingTd;

public:
    Runningback() : FootballPlayer(), rushingYd(0), rushingTd(0) {}

    Runningback(string n, int a, string h, int w, int ry, int rt) 
        : FootballPlayer(n, a, h, w), rushingYd(ry), rushingTd(rt) {}

    void setPlayer(string n, int a, string h, int w, int s1, int s2) override {
        FootballPlayer::setPlayer(n, a, h, w, s1, s2);
        rushingYd = s1;
        rushingTd = s2;
    }

    void printInfo() override {
        FootballPlayer::printInfo();
        cout << "Rushing Yards: " << rushingYd << ", Rushing Touchdowns: " << rushingTd << endl;
    }

    virtual ~Runningback() = default;

    int getStat1()override {return rushingYd;}
    int getStat2()override {return rushingTd;}
};

#endif
