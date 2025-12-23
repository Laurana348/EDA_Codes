#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<set<int>> arcs(n, set<int>());
        int x, y;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            arcs[x].insert(y);
        }

        vector<int> dad(n, -1);
        
        vector<bool> used(n, false);
        used[0] = true;

        queue<int> q;
        q.push(0);

        while(!q.empty()) {
            int vertex = q.front();
            q.pop();

            if (vertex == n-1) break;

            for (auto& v : arcs[vertex]) {
                if (!used[v]) {
                    dad[v] = vertex;
                    used[v] = true;
                    q.push(v);
                }
            }
        }

        vector<int> cami;
        int actual = n - 1;
        while (actual != -1) {
            cami.push_back(actual);
            actual = dad[actual];
        }

        int mida = cami.size();
        bool first = true;
        for (int i = mida-1; -1 < i; --i) {
            if (!first) cout << ' ';
            first = false;
            cout << cami[i];
        }

        cout << endl;
    }
}
