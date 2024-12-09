#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>

#include "FootballPlayer.h"
#include "Quarterback.h"
#include "Receiver.h"
#include "Runningback.h"

using namespace std;

void loadPlayers(vector<FootballPlayer*>& roster, const string& filename) {
    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
    cout << "Error: File not opened!" << endl;
    }
    

    string type, name, height;
    int age, weight, stat1, stat2;
    int length;
    file >> length;
    file.ignore();
    for(int i = 0; i<length; i++){
        getline(file, type);
        getline(file, name); 
        file >> age;
        file.ignore(); 
        getline(file, height); 
        file >> weight >> stat1 >> stat2;
        file.ignore(); 


        if (type == "Quarterback") {
            roster.push_back(new Quarterback(name, age, height, weight, stat1, stat2));
        } else if (type == "Runningback") {
            roster.push_back(new Runningback(name, age, height, weight, stat1, stat2));
        } else if (type == "Receiver") {
            roster.push_back(new Receiver(name, age, height, weight, stat1, stat2));
        }
    }

    file.close();
    cout << "Players loaded successfully." << endl;
}
 

void savePlayers(const vector<FootballPlayer*>& roster, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Failed to open file. Please try again." << endl;
        return;
    }

    for (const auto& player : roster) {
        string type;
        if (dynamic_cast<Quarterback*>(player)) {
            type = "Quarterback";
        } else if (dynamic_cast<Receiver*>(player)) {
            type = "Receiver";
        } else if (dynamic_cast<Runningback*>(player)) {
            type = "Runningback";
        }

        file << type << endl;
        file << player->getName() << endl;
        file << player->getAge() << endl;
        file << player->getHeight() << endl;
        file << player->getWeight() << endl;
        file << player->getStat1() << endl;
        file << player->getStat2() << endl;
    }

    file.close();
    cout << "Players saved successfully to " << filename << "." << endl;
}

void editPlayer(vector<FootballPlayer*>& roster, const string& playerName) {
    for (auto& player : roster) {
        if (player->getName() == playerName) {
            string newHeight;
            int newAge, newWeight, stat1, stat2;
            cout << "Enter new age: ";
            cin >> newAge;
            cin.ignore();
            cout << "Enter new height: ";
            getline(cin, newHeight);
            cout << "Enter new weight: ";
            cin >> newWeight;
            if (dynamic_cast<Quarterback*>(player)) {
            cout << "Enter new passing yard: ";
            cin >> stat1;
            cout << "Enter new passing touchdown: ";
            cin >> stat2;
            } else if (dynamic_cast<Receiver*>(player)) {
            cout << "Enter new receiving yard: ";
            cin >> stat1;
            cout << "Enter new receiving touchdown: ";
            cin >> stat2;
            } else if (dynamic_cast<Runningback*>(player)) {
            cout << "Enter new rushing yard: ";
            cin >> stat1;
            cout << "Enter new rushing touchdown: ";
            cin >> stat2;
            }
            

            player->setPlayer(playerName, newAge, newHeight, newWeight, stat1, stat2);
            cout << "Player updated." << endl;
            return;
        }
    }
    cout << "Player not found." << endl;
}

void printPlayerInfo(const vector<FootballPlayer*>& roster, const string& playerName) {
    cout << playerName << endl;

    for (const auto& player : roster) {
        if (player->getName() == playerName) {
            player->printInfo();
            return;
        }
    }
    cout << "Player not found." << endl;
}

void printAllPlayers(const vector<FootballPlayer*>& roster) {
    if (roster.empty()) {
        cout << "No players in the roster." << endl;
        return;
    }
    for (const auto& player : roster) {
        player->printInfo();
        cout << "---------------------------------" << endl;
    }
}

int main() {
    
    vector<FootballPlayer*> roster;
    int choice;
    string filename, playerName;
    int count = 0;

    do {
        cout << "1. Load Players\n2. Save Players\n3. Edit Player\n4. Print Player Info\n5. Print All Players\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter filename: ";
            cin >> filename;
            loadPlayers(roster, filename);
            break;
        case 2:
            cout << "Enter filename: ";
            cin >> filename;
            savePlayers(roster, filename);
            break;
        case 3:
            cout << "Enter player name: ";
            cin.ignore();
            getline(cin, playerName);
            editPlayer(roster, playerName);
            break;
        case 4:
            cout << "Enter player name: ";
            cin.ignore();
            getline(cin, playerName);
            printPlayerInfo(roster, playerName);
            break;
        case 5:
            printAllPlayers(roster);
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice, please try again" << endl;
            count ++;
        }
    } while (choice != 6 && count < 2);

    for (auto player : roster) {
        delete player;
    }

    return 0;
}
