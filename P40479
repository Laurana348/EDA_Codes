#include <iostream>
#include <vector>
using namespace std;

void dfs(vector <vector <char> >& v, int x, int y, char lletra) {
    if (x < 0 || x >= (int)v.size() || y < 0 || y >= (int)v[x].size()) return;
    
    
    if (v[x][y] == '#' || v[x][y] == lletra) return;
    v[x][y] = lletra;

    dfs(v, x-1, y, lletra);
    dfs(v, x+1, y, lletra);
    dfs(v, x, y-1, lletra);
    dfs(v, x, y+1, lletra);

    return;
}

int main() {
    int n, m;

    while(cin >> n >> m) {
        vector <vector <char> > v(n, vector<char>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> v[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (v[i][j] != '#' && v[i][j] != '.') {
                    char lletra = v[i][j];
                    dfs(v, i, j+1, lletra);
                    dfs(v, i, j-1, lletra);
                    dfs(v, i-1, j, lletra);
                    dfs(v, i+1, j, lletra);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << v[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
  }
}
