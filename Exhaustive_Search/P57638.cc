#include <iostream>
#include <vector>
using namespace std;

void move(const vector<vector<char>>& mapa, int x, int y, 
    vector<char>& sol) {
    int n = mapa.size();
    int m = mapa[0].size();
    if (x == n || y == m) {
        int mida = sol.size();
        for (int i = 0; i < mida; ++i) {
            cout << sol[i];
        }
        cout << endl;
    }

    else {
        if (mapa[x][y] == '.') {
            sol.push_back('A');
            move(mapa, x+1, y, sol);
            sol.pop_back();

            sol.push_back('D');
            move(mapa, x, y+1, sol);
            sol.pop_back();
        }

        else if (mapa[x][y] == 'D') {
            sol.push_back('D');
            move(mapa, x, y+1, sol);
            sol.pop_back();
        }

        else if (mapa[x][y] == 'A') {
            sol.push_back('A');
            move(mapa, x+1, y, sol);
            sol.pop_back();
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<char>> mapa(n, vector<char>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> mapa[i][j];
            }
        }
        vector<char> sol;
        move(mapa, 0, 0, sol);
        cout << "----------" << endl;
    }
}
