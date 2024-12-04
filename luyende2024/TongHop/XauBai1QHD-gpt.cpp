#include <bits/stdc++.h>
using namespace std;

int main() {

    string S1, S2;
    getline(cin, S1);
    getline(cin, S2);

    int m = S1.size();
    int n = S2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (S1[i-1] == S2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[m][n] << endl;
    return 0;
}
