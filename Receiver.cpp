
#include "Receiver.h"
using namespace std;

Receiver::Receiver() : FootballPlayer(), receivingYd(0), receivingTd(0) {}

Receiver::Receiver(string n, int a, string h, int w, int ry, int rt) : FootballPlayer(n, a, h, w), receivingYd(ry), receivingTd(rt) {}



void Receiver::setPlayer(string n, int a, string h, int w, int s1, int s2) {
    FootballPlayer::setPlayer(n, a, h, w, s1, s2);
    receivingYd = s1;
    receivingTd = s2;
}

void Receiver::printInfo() {
    FootballPlayer::printInfo();
    cout << "Receiving Yards: " << receivingYd << ", Receiving Touchdowns: " << receivingTd << endl;
}

//int Receiver::getReceivingYd() { return receivingYd; }
//int Receiver::getReceivingTd() { return receivingTd; }