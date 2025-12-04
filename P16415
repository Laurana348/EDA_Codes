#include <iostream>
#include <vector>
using namespace std;

void queen(int indx, int& count, vector<bool>& col, 
    vector<bool>& diagonal_1, vector<bool>& diagonal_2) {
    int n = col.size();

    if (indx == n) {
        ++count;
        return;
    }

    else {
        for (int i = 0; i < n; ++i) { //columna
            int d1 = indx - i + n - 1;
            int d2 = indx + i;

            if (!col[i] && !diagonal_1[d1] && !diagonal_2[d2]) {
                col[i] = diagonal_1[d1] = diagonal_2[d2] = true;
                queen(indx+1, count, col, diagonal_1, diagonal_2);
                col[i] = diagonal_1[d1] = diagonal_2[d2] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int count = 0;
    vector<bool> col(n);
    vector<bool> diagonal_1(n);
    vector<bool> diagonal_2(n);
    queen(0, count, col, diagonal_1, diagonal_2);
    cout << count << endl;
}
