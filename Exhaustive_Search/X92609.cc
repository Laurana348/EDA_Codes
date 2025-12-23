#include <iostream>
#include <vector>
using namespace std;

vector<int> m;

void money(int indx, int suma, int x, int& count, int n) {

    if (suma == x) ++count;
    else if (suma > x || indx == n) return;
    else {
        money(indx+1, suma, x, count, n);
        money(indx+1, suma + m[indx], x, count, n);
        money(indx+1, suma + 2*m[indx], x, count, n);
    }
}

int main() {
    int x, n;
    while (cin >> x >> n) {
        m = vector<int>(n);
        for (int i = 0; i < n; ++i) cin >> m[i];

        int count = 0;
        money(0, 0, x, count, n);
        cout << count << endl;
    }
}
