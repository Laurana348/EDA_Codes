#include <iostream>
#include <vector>
using namespace std;

void torres(int indx, vector<int>& sol, vector<bool>& col) {
    int f = sol.size();
    int c = col.size();
    if (indx == f) {
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                if (sol[i] == j) cout << 'R';
                else cout << '.';
            }
            cout << endl;
        }
        cout << endl;
    }

    else {
        for (int i = 0; i < c; ++i) {
            if (!col[i]) {
                col[i] = true;
                sol[indx] = i;
                torres(indx+1, sol, col);
                col[i] = false;
            }
        }
    }
}

int main() {
    int f, c;
    cin >> f >> c;
    vector<int> sol(f);
    vector<bool> col(c, false);
    torres(0, sol, col);
}
