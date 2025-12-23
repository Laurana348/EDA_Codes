#include <iostream> 
#include <vector>
using namespace std;

vector<vector<int>> mat;

void digits(int indx, vector<bool>& used, int prev,
    int& best_case, int current_case, int m, int num) {
    int n = used.size();
    if (indx == n) {
        if (best_case < current_case) best_case = current_case;
    }

    else {
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                int aux_num = num*10 + (i+1);

                if (aux_num % m != 0) {
                    //cout << "num: " << aux_num << " true" << endl;
                    int premi = 0;
                    if (prev != -1) {
                        premi = mat[prev][i];
                    }
                    used[i] = true;
                    digits(indx+1, used, i, best_case, premi + current_case, m, aux_num);
                    used[i] = false;
                }
            }
        }
    }
}

int main() {
    int m, n;
    while(cin >> m >> n) {
        mat = vector<vector<int>> (n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> mat[i][j];
            }
        }

        vector<bool> used(n);
        int best_case = 0;
        digits(0, used, -1, best_case, 0, m, 0);
        cout << best_case << endl;
    }
}
