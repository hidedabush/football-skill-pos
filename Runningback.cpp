
#include "Runningback.h"

using namespace std;

Runningback::Runningback() : FootballPlayer(), rushingYd(0), rushingTd(0) {}

Runningback::Runningback(string n, int a, string h, int w, int ry, int rt) 
    : FootballPlayer(n, a, h, w), rushingYd(ry), rushingTd(rt) {}

void Runningback::setPlayer(string n, int a, string h, int w, int s1, int s2) {
    FootballPlayer::setPlayer(n, a, h, w, s1, s2);
    rushingYd = s1;
    rushingTd = s2;

}

void Runningback::printInfo() {
    FootballPlayer::printInfo();
    cout << "Rushing Yards: " << rushingYd << ", Rushing Touchdowns: " << rushingTd << endl;
}

//int Runningback::getRushingYd() { return rushingYd; }
//int Runningback::getRushingTd() { return rushingTd; }