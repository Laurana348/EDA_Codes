#include <iostream>
#include <vector>
using namespace std;

bool es_pot(string first, string second) {
    int n = first.size();

    if (first[n-1] == second[0]) return false;
    else return true;
}

void no_connection(int indx, vector<string>& sol, const vector<string>& words, vector<bool>& used) {
    int n = sol.size();
    if (indx == n) {
        for (int i = 0; i < n; ++i) cout << sol[i];
        cout << endl;
        return;
    }

    else {
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                string lletres = "."; //en el cas de que sigui el primer element
                if (0 < indx) {
                    lletres = sol[indx-1];
                }

                if (es_pot(lletres, words[i])) {
                    sol[indx] = words[i];
                    used[i] = true;
                    no_connection(indx+1, sol, words, used);
                    used[i] = false;
                }
            }
        }   
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; ++i) cin >> words[i];

    vector<bool> used(n, false);
    vector<string> sol(n);
    no_connection(0, sol, words, used);
}
