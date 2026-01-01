#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<char>> mapa(n, vector<char>(m));
        int x, y;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> mapa[i][j];
                if (mapa[i][j] == 'K') {
                    x = i;
                    y = j;
                }
            }
        }

        queue<pair<int, int>> q;
        q.push({x, y});

        vector<vector<int>> dist(n, vector<int>(m, -1));
        dist[x][y] = 0;

        vector<vector<pair<int, int>>> pare(n, vector<pair<int, int>>(m, {-1, -1}));
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1,1}, {1, -1}, {-1, 1}, {-1, -1}};
        int u, v;

        while (!q.empty()) {
            u = q.front().first;
            v = q.front().second;
            q.pop();

            if (mapa[u][v] == 'F') break;

            for (auto d : dirs) {
                int x2 = u + d.first;
                int y2 = v + d.second;

                if (0 <= x2 && x2 < n && 0 <= y2 && y2 < m) {
                   if (mapa[x2][y2] != 'X' && dist[x2][y2] == -1) {
                        dist[x2][y2] = dist[u][v] + 1;
                        pare[x2][y2] = {u, v};
                        q.push({x2, y2});
                    } 
                }
            }
        }

        vector<pair<int, int>> cami;
        int fin_u = u;
        int fin_v = v;
        while(u != -1 && v != -1) {
            cami.push_back({u, v});
            int aux_u = pare[u][v].first;
            int aux_v = pare[u][v].second;
            u = aux_u;
            v = aux_v;
        }

        int distancia = dist[fin_u][fin_v];
        if (distancia != -1 && mapa[fin_u][fin_v] == 'F') {
            cout << distancia + 1;
            int mida = cami.size();
            for (int i = mida-1; -1 < i; --i) {
                cout << "  " << cami[i].first << ' ' << cami[i].second;
            }
        }
        else cout << '0';
        cout << endl;
    }
}
