#include <iostream>
#include <vector>
using namespace std;

void crear(int indx, vector<char>& sol, int a, int b) {
    int n = sol.size();
    if (indx == n) {
        for (int i = 0; i < n; ++i) cout << sol[i];
        cout << endl;
        return;
    }
    else {
        if (a < b+2) {
            sol[indx] = 'a';
            crear(indx+1, sol, a+1, b);
        }
        
        if (b < a+2) {
            sol[indx] = 'b';
            crear(indx+1, sol, a, b+1);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<char> sol(n);
    crear(0, sol, 0, 0);
}
