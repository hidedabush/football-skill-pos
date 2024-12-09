#ifndef RECEIVER_H
#define RECEIVER_H

#include "FootballPlayer.h"

class Receiver : public FootballPlayer {
private:
    int receivingYd;
    int receivingTd;

public:
    Receiver() : FootballPlayer(), receivingYd(0), receivingTd(0) {}

    Receiver(string n, int a, string h, int w, int ry, int rt) 
        : FootballPlayer(n, a, h, w), receivingYd(ry), receivingTd(rt) {}

    void setPlayer(string n, int a, string h, int w, int s1, int s2) override {
        FootballPlayer::setPlayer(n, a, h, w, s1, s2);
        receivingYd = s1;
        receivingTd = s2;
    }

    void printInfo() override {
        FootballPlayer::printInfo();
        cout << "Receiving Yards: " << receivingYd << ", Receiving Touchdowns: " << receivingTd << endl;
    }

    virtual ~Receiver() = default;

    int getStat1()override {return receivingYd;}
    int getStat2()override {return receivingTd;}
};

#endif
