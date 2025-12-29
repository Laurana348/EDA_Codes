#include <iostream>
#include <vector>
using namespace std;

void cents(int indx, const int n, int num, vector<int>& coints,
    const vector<int> possibilitats) {
    if (n == num) {
        int mida = coints.size();
        bool first = true;
        for (int i = 0; i < mida; ++i) {
            if (!first) cout << ' ';
            first = false;
            cout << coints[i];
        }
        cout << endl;
        return;
    }

    else if (num > n) return;

    else {
        for (int i = indx; i < 6; ++i) {
            num += possibilitats[i];
            coints.push_back(possibilitats[i]);
            cents(i, n, num, coints, possibilitats);
            num -= possibilitats[i];
            coints.pop_back();
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> coints;
        vector<int> possibilitats = {50, 20, 10, 5, 2, 1};
        cents(0, n, 0, coints, possibilitats);
        cout << endl;
    }
}
