#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, t;
    //n = num vertex, t = num arestes

    while(cin >> n >> t) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < t; ++i) {
            int n2;
            cin >> n2;
            vector<int>coautors(n2);

            for (int j = 0; j < n2; ++j) {
                int x;
                cin >> x;
                coautors[j] = x;
            }

            for (int j = 0; j < n2; ++j) {
                for (int k = 0; k < n2; ++k) {
                    int u = coautors[j];
                    int v = coautors[k];
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
            }
        }

        vector<int> sol(n, -1);
        sol[0] = 0; //Erdos

        vector<bool> visited(n, false);
        visited[0] = true;

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for(int g : graph[x]) {
                if (!visited[g]) {
                    visited[g] = true;
                    sol[g] = sol[x] + 1;
                    q.push(g);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << i << " : ";
            if (sol[i] == -1) cout << "no";
            else cout << sol[i];
            cout << endl;
        }
        cout << "----------" << endl;
    }
}
