#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool vocal(char lletra) {
    if (lletra == 'a' || lletra == 'e' || lletra == 'i' || lletra == 'o' || lletra == 'u') {
        return true;
    }

    return false;
}

void ruines(int indx, const vector<char>& lletres, bool vocals,
            vector<char>& sol) {

    int n = sol.size();
    if (indx == n) {
        for (int i = 0; i < n; ++i) {
            cout << sol[i];
        }
        cout << endl;
    }
    else {
        int m = lletres.size();
        for (int i = 0; i < m; ++i) {
            if (vocal(lletres[i])) {
                if (!vocals) {
                    sol[indx] = lletres[i];
                    ruines(indx+1, lletres, true, sol);
                }
            }

            else {
                sol[indx] = lletres[i];
                ruines(indx+1, lletres, false, sol);
            }
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {

        vector<char> lletres(m);
        vector<int> vocals_count(m, -1);
        for (int i = 0; i < m; ++i) {
            cin >> lletres[i];
        }

        sort(lletres.begin(), lletres.end());
        vector<char> sol(n);
        ruines(0, lletres, false, sol);
        cout << "----------" << endl;
    }
}
