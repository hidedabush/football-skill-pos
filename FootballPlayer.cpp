#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "FootballPlayer.h"
using namespace std;

FootballPlayer::FootballPlayer() : name("no name"), age(0), height("ft"), weight(0) {}

FootballPlayer::FootballPlayer(string n, int a, string h, int w) : name(n), age(a), height(h), weight(w) {}

string FootballPlayer::getName() { return name; }
int FootballPlayer::getAge() { return age; }
string FootballPlayer::getHeight() { return height; }
int FootballPlayer::getWeight() { return weight; }
