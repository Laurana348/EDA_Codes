#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char>> mapa;

int main() {
    int n, m;
    cin >> n >> m;
    mapa = vector<vector<char>>(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char caracter;
            cin >> caracter;
            mapa[i][j] = caracter;
        }
    }

    int f, c;
    cin >> f >> c;
    --f; //0-indexed
    --c;

    queue<pair<int, int>> q;
    q.push({f, c});

    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[f][c] = 0;

    int dist_max = -1;
    int second_dist_max = -1;
    int count = 0;

    const vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (mapa[x][y] == 't') {
            int d = dist[x][y];

            if (d > dist_max) {
                second_dist_max = dist_max;
                dist_max = d;
            }

            else if (d > second_dist_max) {
                second_dist_max = d;
            }
        }

        for (pair<int, int> d : dirs) {
            int x2 = x + d.first;
            int y2 = y + d.second;

            if (-1 < x2 && x2 < n && -1 < y2 && y2 < m) {
                if (mapa[x2][y2] != 'X' && dist[x2][y2] == -1) {
                    dist[x2][y2] = dist[x][y] + 1;
                    q.push({x2, y2});
                }
            }
        }

    }

    if (second_dist_max == -1) cout << "no es pot arribar a dos o mes tresors";
    else cout << "segona distancia maxima: " << second_dist_max;
    cout << endl;
}
