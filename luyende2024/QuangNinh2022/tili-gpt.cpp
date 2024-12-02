#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ifstream infile("tili.inp");
    ofstream outfile("tili.out");

    int A, B;
    infile >> A >> B;

    vector<int> dp(A + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    if (B == 1) {
        int row, col;
        infile >> row >> col;
        for (int i = 2; i <= A; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
            if (i == col) {
                if (row == 1) {
                    dp[i] = dp[i - 1];
                } else {
                    dp[i] = dp[i - 2];
                }
            }
        }
    } else {
        for (int i = 2; i <= A; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
    }

    outfile << dp[A] << endl;

    infile.close();
    outfile.close();

    return 0;
}
