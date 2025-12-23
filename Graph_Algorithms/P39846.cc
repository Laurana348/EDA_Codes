#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char>> map;

int main() {
    int n, m;
    cin >> n >> m;
    map = vector<vector<char>>(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char caracter;
            cin >> caracter;
            map[i][j] = caracter;
        }
    }

    int f, c;
    cin >> f >> c;
    --f; //0-indexed
    --c;

    queue<pair<int, int>> q;
    q.push({f, c});

    vector<vector<int>> dist(n, vector<int> (m, -1));
    dist[f][c] = 0;
    int dist_max = -1;

    const vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};


    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (pair<int, int> d : dirs) {
            int x2 = x + d.first;
            int y2 = y + d.second;

            if (-1 < x2 && x2 < n && -1 < y2 && y2 < m) {
                if (map[x2][y2] != 'X' && dist[x2][y2] == -1) {
                    dist[x2][y2] = dist[x][y] + 1;

                    if (map[x2][y2] == 't') {
                        if (dist[x2][y2] > dist_max) {
                            dist_max = dist[x2][y2];
                        }
                    }

                    q.push({x2, y2});
                }
            }
        }
    }

    if (dist_max == -1) cout << "no es pot arribar a cap tresor";
    else cout << "distancia maxima: " << dist_max;
    cout << endl;
}
