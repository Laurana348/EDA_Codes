#include <iostream>
#include <map>

using namespace std;

int main() {
    map <string, int> players;
    string name;

    while (cin >> name) {
        string command;
        cin >> command;
        auto it = players.find(name);

        if (command == "enters") {
            if (it != players.end()) {
                cout << name << " is already in the casino" << endl;
            }

            else {
                players.insert({name, 0});
            }
        }

        else if (command == "wins") {
            int x;
            cin >> x;

            if (it != players.end()) {
                it->second += x;
            }

            else {
                cout << name << " is not in the casino" << endl;
            }
        }

        else if (command == "leaves") {
            if (it != players.end()) {
                cout << it->first << " has won " << it->second << endl;
                players.erase(it);
            }

            else {
                cout << name << " is not in the casino" << endl;
            }
        }
    }

    cout << "----------" << endl;

    auto it = players.begin();

    while (it != players.end()) {
        cout << it->first << " is winning " << it->second << endl;
        ++it;
    }
 
}
