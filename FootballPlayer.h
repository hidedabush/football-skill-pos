#ifndef FOOTBALLPLAYER_H
#define FOOTBALLPLAYER_H

#include <iostream>
#include <string>
using namespace std;

class FootballPlayer {
protected:
    string name;
    int age;
    string height;
    int weight;

public:
    FootballPlayer() : name("no name"), age(0), height("ft"), weight(0) {}

    FootballPlayer(string n, int a, string h, int w) : name(n), age(a), height(h), weight(w) {}

    string getName() { return name; }
    int getAge() { return age; }
    string getHeight() { return height; }
    int getWeight() { return weight; }

    virtual void setPlayer(string n, int a, string h, int w, int s1, int s2) {
        name = n;
        age = a;
        height = h;
        weight = w;
    }

    virtual void printInfo() {
        cout << "Name: " << name << ", Age: " << age 
             << ", Height: " << height << ", Weight: " << weight << endl;
    }

    virtual ~FootballPlayer() = default;

    virtual int getStat1(){return 0;}
    virtual int getStat2(){return 0;}
};

#endif
