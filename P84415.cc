#include <iostream>
#include <map>

using namespace std;

int main() {
    string command;
    map<string, int> bag;
    while (cin >> command) {
        if (command == "store") {
            string word;
            cin >> word;
            bag[word]++;
        }

        else if (command == "minimum?") {
            if (bag.empty()) {
                cout << "indefinite minimum" << endl;
            }

            else {
                auto it = bag.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }

        else if (command == "maximum?") {
            if (bag.empty()) {
                cout << "indefinite maximum" << endl;
            }

            else {
                auto it = bag.end();
                it--;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }

        else if (command == "delete") {
            string word;
            cin >> word;
            if (bag[word] > 0) bag[word]--;
            if (bag[word] == 0) bag.erase(word);
        }
    }

}
