#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> extres(n);
    for (int i = 0; i < n; ++i) cin >> extres[i];

    vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
    for (int j = 0; j < m; ++j) {
        int x, y, c;
        cin >> x >> y >> c;
        graph[x].push_back({c, y});
        graph[y].push_back({c, x});
    }

    int x, y;
    while (cin >> x >> y) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, x});

        vector<int> dist(n, INF);
        dist[x] = 0;

        while (!pq.empty()) {
            int c2 = pq.top().first;
            int x2 = pq.top().second;
            pq.pop();

            if (dist[x2] < c2) continue;

            if (x2 != x && x2 != y) {
                dist[x2] += extres[x2];
            }

            if (x2 == y) break;

            for (auto conjunt : graph[x2]) {
                int c3 = conjunt.first;
                int x3 = conjunt.second;
                if (dist[x3] > dist[x2] + c3) {
                    dist[x3] = dist[x2] + c3;
                    pq.push({dist[x3], x3}); 
                }
            }
        }

        cout << "c(" << x << ',' << y << ") = ";

        if (dist[y] != INF) cout << dist[y];
        else cout << "+oo";
        cout << endl;
    }
}
