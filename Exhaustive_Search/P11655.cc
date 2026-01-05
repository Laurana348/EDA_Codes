#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;

void sums(int indx, vector<int>& sol, int suma, int s, int sum_rest) {
    int n = nums.size();
    if (suma > s ||suma + sum_rest < s) return;
    if (indx == n) {
        if (suma == s) {
            cout << '{';
            bool first = true;
            int mida = sol.size();
            for (int i = 0; i < mida; ++i) {
                if (!first) cout << ',';
                first = false;
                cout << sol[i];
            }
            cout << '}' << endl;
        }
    }

    else {
        sol.push_back(nums[indx]);
        sums(indx+1, sol, suma + nums[indx], s, sum_rest - nums[indx]);
        sol.pop_back();
        sums(indx+1, sol, suma, s, sum_rest - nums[indx]);
    }
}

int main() {
    int s, n;
    cin >> s >> n;
    nums = vector<int>(n);
    int sum_rest = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        sum_rest += nums[i];
    }
    vector<int> sol;
    sums(0, sol, 0, s, sum_rest);
}
