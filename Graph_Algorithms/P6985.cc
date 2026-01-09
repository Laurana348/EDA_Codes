#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void cavall(int x, int y, int& total, vector<vector<char>>& mapa, vector<vector<bool>>& used) {
    if (x < 0 || x >= mapa.size() || y < 0 || y >= mapa[0].size()) return;
    if (used[x][y] || mapa[x][y] == 'T') return;

    used[x][y] = true;

    if (mapa[x][y] >= '0' && mapa[x][y] <= '9') { //monedes
        char num = mapa[x][y];
        mapa[x][y] = '.';
        total += (num - '0');
    }

    cavall(x+2, y+1, total, mapa, used);
    cavall(x+2, y-1, total, mapa, used);
    cavall(x-2, y+1, total, mapa, used);
    cavall(x-2, y-1, total, mapa, used);
    cavall(x-1, y+2, total, mapa, used);
    cavall(x+1, y+2, total, mapa, used);
    cavall(x-1, y-2, total, mapa, used);
    cavall(x+1, y-2, total, mapa, used);
}

void alfil(int x, int y, int& total, vector<vector<char>>& mapa, vector<vector<bool>>& used) {
    if (x < 0 || x >= mapa.size() || y < 0 || y >= mapa[0].size()) return;
    if (used[x][y] || mapa[x][y] == 'T') return;

    used[x][y] = true;

    if (mapa[x][y] >= '0' && mapa[x][y] <= '9') { //monedes
        char num = mapa[x][y];
        mapa[x][y] = '.';
        total += (num - '0');
    }

    alfil(x+1, y+1, total, mapa, used);
    alfil(x-1, y+1, total, mapa, used);
    alfil(x-1, y-1, total, mapa, used);
    alfil(x+1, y-1, total, mapa, used);
}

int main() {
    int n, m;
    while (cin >> n >> m) {

        vector<vector<char>> mapa(n, vector<char>(m));
        vector<pair<int, int>> cavalls;
        vector<pair<int, int>> alfils;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char lletra;
                cin >> lletra;
                mapa[i][j] = lletra;
                if (lletra == 'K') cavalls.push_back({i, j});
                else if (lletra == 'B') alfils.push_back({i, j});
            }
        }

        vector<vector<bool>> used(n, vector<bool>(m, false));
        int total = 0;

        int mida_ca = cavalls.size();
        for (int i = 0; i < mida_ca; ++i) {
            int x = cavalls[i].first;
            int y = cavalls[i].second;
            cavall(x, y, total, mapa, used);
        }

        used = vector<vector<bool>> (n, vector<bool>(m, false));
        int mida_al = alfils.size();
        for (int i = 0; i < mida_al; ++i) {
            int x = alfils[i].first;
            int y = alfils[i].second;
            alfil(x, y, total, mapa, used);
        }

        cout << total << endl;
    }
}
