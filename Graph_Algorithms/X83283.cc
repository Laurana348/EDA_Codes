#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m) {

        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        vector<int>dist(n, -1);
        dist[0] = 0;

        queue<int> q;
        q.push(0);

        int llunya = 0;

        while(!q.empty()) {
            int x = q.front();
            q.pop();

            for (auto x2 : graph[x]) {
                if (dist[x2] == -1 || dist[x2] > dist[x]+1) {
                    dist[x2] = dist[x] + 1;

                    if (dist[llunya] < dist[x2]) {
                        llunya = x2;
                    }

                    else if (dist[llunya] == dist[x2]) {
                        if (llunya > x2) llunya = x2;
                    }
                    q.push(x2);
                }
            }
        }

        cout << llunya << endl;
    }
}
