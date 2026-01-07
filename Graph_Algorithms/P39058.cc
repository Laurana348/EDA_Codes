#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char>> mapa;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);

    int n, m;
    cin >> n >> m;

    mapa = vector<vector<char>>(n, vector<char>(m));
    int x, y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char casella;
            cin >> casella;
            mapa[i][j] = casella;
            if (casella == 'C') {
                x = i;
                y = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({x, y});

    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[x][y] = 0;

    vector<pair<int, int>> dir = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    int flors = 0;
    double suma_dist = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int x2 = x + dir[i].first;
            int y2 = y + dir[i].second;

            if (0 <= x2 && x2 < mapa.size() && 0 <= y2 && y2 < mapa[0].size()) {
                if (dist[x2][y2] == -1 && mapa[x2][y2] != 'a') {
                    dist[x2][y2] = dist[x][y] + 1;
                    if (mapa[x2][y2] == 'F') {
                        ++flors;
                        suma_dist += dist[x2][y2];
                    }
                    q.push({x2, y2});
                }
            }
        }
    }

    if (flors == 0) {
        cout << "el cavall no pot arribar a cap flor" << endl;
    }
    else {
        double total = suma_dist/flors;
        cout << "flors accessibles: " << flors << endl;
        cout << "distancia mitjana: " << total << endl;
    }
}
