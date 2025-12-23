#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int INF = 1e9;

int main() {
    //read input
    int n, m;
    while(cin >> n >> m) {
        vector<vector<pair<int, int>>> g(n);

        for (int i=0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            g[u].push_back({v, c});
        }

        int x, y;
        cin >> x >> y;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> dist(n, INF);
        vector<int> dad(n, -1);

        dist[x] = 0;
        q.push({0, x});
        
        while (!q.empty()) {
            int u = q.top().second;
            int d = q.top().first;
            q.pop();
            if (dist[u] < d) continue; //Volem les distancies més petites

            //opcion: usar un map i guardar la distancia del camino i debajo el camino (puede tardar muchisimo)
            for (pair<int, int> p : g[u]) {
                int v = p.first;
                int c = p.second;
                if (dist[v] > dist[u] + c) { //Si la distancia de v és més gran posem la nova que és més petita
                    dist[v] = dist[u] + c;
                    dad[v] = u;
                    q.push({dist[v], v});
                }
            }
        }

        if (dist[y] == INF) {
            cout << "no path from " << x << " to " << y << endl;
        }

        else {
            vector<int> cami;
            int actual = y;
            while (actual != -1) {
                cami.push_back(actual);
                actual = dad[actual];
            }

            int mida = cami.size() - 1;
            cout << cami[mida];

            for (int i = mida - 1; -1 < i; --i) {
                cout << ' ' << cami[i];
            }

            cout << endl; 
        }  
    }

}
