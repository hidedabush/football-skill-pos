
#include "Quarterback.h"

using namespace std;

Quarterback::Quarterback() : FootballPlayer(), passingYd(0), passingTd(0) {}

Quarterback::Quarterback(string n, int a, string h, int w, int py, int pt) : FootballPlayer(n, a, h, w), passingYd(py), passingTd(pt) {}

void Quarterback::setPlayer(string n, int a, string h, int w, int s1, int s2) {
    FootballPlayer::setPlayer(n, a, h, w, s1, s2);
    passingYd = s1;
    passingTd = s2;
}

void Quarterback::printInfo() {
    FootballPlayer::printInfo();
    cout << "Passing Yards: " << passingYd << ", Passing Touchdowns: " << passingTd << endl;
}

//int Quarterback::getPassingYd() { return passingYd; }
//int Quarterback::getPassingTd() { return passingTd; }