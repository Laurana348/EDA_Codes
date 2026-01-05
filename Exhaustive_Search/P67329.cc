#include <iostream>
#include <vector>
using namespace std;

void adn(int indx, vector<char>& sol, const vector<char>& lletres) {
    int n = sol.size();
    if (indx == n) {
        for (int i = 0; i < n; ++i) {
            cout << sol[i];
        }
        cout << endl;
    }

    else {
        for (int i = 0; i < 4; ++i) {
            sol[indx] = lletres[i];
            adn(indx+1, sol, lletres);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<char> lletres = {'A', 'C', 'G', 'T'};
    vector<char> sol(n);
    adn(0, sol, lletres);
}
