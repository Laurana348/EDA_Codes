#include <iostream>
#include <map>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    map<int, int> mymap;
    string command;
    double total = 0;
    int count = 0;

    while (cin >> command) {
        if (command == "number") {
            int number;
            cin >> number;
            auto it = mymap.find(number);
            
            if (it != mymap.end()) {
                ++it->second;
            }

            else mymap.insert({number, 1});

            total += number;
            ++count;
        }

        else if (command == "delete") {
            if (not mymap.empty()) {
                auto it = mymap.begin();

                int erase_num = it->first;

                if (it->second > 1) {
                    --it->second;
                }

                else mymap.erase(it);

                total -= erase_num;
                --count;
            }
        }

        if (mymap.empty()) cout << "no elements" << endl;
        else cout << "minimum: " << (mymap.begin()->first) << ", maximum: " << (mymap.rbegin()->first) << ", average: " << total/count << endl;
    }
}
