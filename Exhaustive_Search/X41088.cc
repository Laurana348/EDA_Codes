#include <iostream>
#include <vector>
using namespace std;

bool pou(int prev_prev, int prev, int num) {
    int suma = prev_prev + num;
    if (suma > 2*prev) return true;
    else return false;
}

void tripleta(int indx, vector<int>& sol, vector<bool>& used) {
    int n = sol.size();
    if (indx == n) {
        cout << '(';
        for (int i = 0; i < n; ++i) {
            if (0 < i) cout << ',';
            cout << sol[i];
        }
        cout << ')' << endl;
    }

    else {
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                if (2 <= indx) {
                    int prev_prev = sol[indx-2];
                    int prev = sol[indx-1];

                    if (!pou(prev_prev, prev, i+1)) {
                        used[i] = true;
                        sol[indx] = i+1;
                        tripleta(indx+1, sol, used);
                        used[i] = false;
                    }
                }

                else {
                    used[i] = true;
                    sol[indx] = i+1;
                    tripleta(indx+1, sol, used);
                    used[i] = false;
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> sol(n); //cuidado perque s'ha de sumar 1 a i
    vector<bool> used(n, false);
    tripleta(0, sol, used);
}
