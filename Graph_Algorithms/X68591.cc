#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;
vector<vector<int>> graph;

void dfs(int x, vector<bool>& used, int& num) {
    if (used[x]) return;

    used[x] = true;
    ++num;

    for (int x2 : graph[x]) {
        dfs(x2, used, num);
    }
}

int main() {
    int n, m;
    while(cin >> n >> m) {
        graph = vector<vector<int>> (n, vector<int>());
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y); //Graf no dirigit
            graph[y].push_back(x);
        }

        int min = INF;
        int max = -1;

        vector<bool> used(n, false);

        int i = 0;
        while (i < n) {
            if (!used[i]) {
                int vertex = 0;
                dfs(i, used, vertex);
                if (vertex < min) min = vertex;
                if (vertex > max) max = vertex;
            }
            ++i;
        }

        cout << min << ' ' << max << endl;
    }
}
