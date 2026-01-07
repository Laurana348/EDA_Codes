#include <iostream>
#include <vector>
using namespace std;

void plantar(int indx, vector<int>& sol, bool& juntes, 
            vector<int>& used) {
    int n3 = sol.size();
    int n = n3/3;
    if (indx == n3 && juntes) {
        for (int i = 0; i < n3; ++i) {
            cout << sol[i];
        }
        cout << endl;
    }
    else {
        for (int i = 0; i < 3; ++i) {
            if (used[i] == n) continue;
            int prev = 0;
            if (indx != 0) prev = sol[indx-1];
            if (prev == (i+1)) {
                if (!juntes) {
                    sol[indx] = (i+1);
                    juntes = true;
                    ++used[i];
                    plantar(indx+1, sol, juntes, used);
                    juntes = false;
                    --used[i];
                }
            }
            else {
                sol[indx] = (i+1);
                ++used[i];
                plantar(indx+1, sol, juntes, used);
                --used[i];
            }

        }
    }
}

int main() {
    int n;
    while(cin >> n) {
        vector<int> sol(3*n);
        bool juntes = false;
        vector<int> used(3);
        plantar(0, sol, juntes, used);
        cout << "**********" << endl;
    }
}
