#include <iostream>
#include <vector>
using namespace std;

vector<char> cons;
vector<char> vows;

void write(const vector<char>& paraula) {
    int n = paraula.size();

    for (int i = 0; i < n; ++i) {
        cout << paraula[i];
    }
    cout << endl;
}

void cons_vows(int indx, vector<char>& paraula, vector<bool>& used_cons, vector<bool>& used_vows, bool consonant) {
    int n = used_cons.size();
    
    if (indx == n+n) {
        write(paraula);
    }

    if (consonant) {
        for (int i = 0; i < n; ++i) {
            if (!used_cons[i]) {
                paraula[indx] = cons[i];
                used_cons[i] = true;
                cons_vows(indx + 1, paraula, used_cons, used_vows, false);
                used_cons[i] = false;
            }
        }
    }

    else {
        for (int i = 0; i < n; ++i) {
            if (!used_vows[i]) {
                paraula[indx] = vows[i];
                used_vows[i] = true;
                cons_vows(indx + 1, paraula, used_cons, used_vows, true);
                used_vows[i] = false;
            }
        }
    }
}

void exhaustive(int n) {
    vector<char> paraula(n+n);
    vector<bool> used_cons(n, false);
    vector<bool> used_vows(n, false);
    cons_vows(0, paraula, used_cons, used_vows, true);
}

int main() {
    int n;
    cin >> n;
    cons = vector<char>(n);
    vows = vector<char>(n);
    for (int i = 0; i < n; ++i) cin >> cons[i];
    for (int i = 0; i < n; ++i) cin >> vows[i];
    exhaustive(n);

}
