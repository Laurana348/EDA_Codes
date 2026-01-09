#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int main() {
    int n; //n senar
    while (cin >> n) {

        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> mat[i][j];
            }
        }

        int mid = n/2;
        int valor = mat[mid][mid];

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({valor, {mid, mid}});

        vector<vector<int>>dist(n, vector<int>(n, INF));
        dist[mid][mid] = valor;

        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int x = 0;
        int y = 0;

        while (!pq.empty()) {
            x = pq.top().second.first;
            y = pq.top().second.second;
            int cost = pq.top().first;
            pq.pop();

            if (x == 0 || y == 0 || x == (n-1) || y == (n-1)) break;
            if (cost > dist[x][y]) continue;

            for (int i = 0; i < 4; ++i) {
                int x2 = x + dir[i].first;
                int y2 = y + dir[i].second;
                int cost2 = mat[x2][y2];

                if (0 <= x2 && x2 < n && 0 <= y2 && y2 < n) {
                    if (dist[x2][y2] > dist[x][y] + cost2) {
                        dist[x2][y2] = dist[x][y] + cost2;
                        pq.push({dist[x2][y2], {x2, y2}});
                    }
                }
            }
        }

        cout << dist[x][y] << endl;
    }
}
