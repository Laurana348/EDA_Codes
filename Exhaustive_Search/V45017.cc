#include <iostream>
#include <vector>
using namespace std;

void count(int indx, int& sum, const vector<int>& pesos, int d,
    int e, vector<bool>& used) {
    int n = pesos.size();
    if (indx == n) {
        ++sum;
        return;
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                used[i] = true;
                count(indx+1, sum, pesos, d, e + pesos[i], used);

                if (d + pesos[i] <= e) {
                    count(indx+1, sum, pesos, d + pesos[i], e, used);
                }

                used[i] = false;
            }
        }
    }
}

int main() {
    int n;
    while(cin >> n) {
        vector<int> pesos(n);
        for (int i = 0; i < n; ++i) {
            cin >> pesos[i];
        }
        int sum = 0;
        vector<bool> used(n, false);
        count(0, sum, pesos, 0, 0, used);
        cout << sum << endl;
    }
}
