#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    vector<int> inp(n);
    for (int i = 0; i < n; i++) cin >> inp[i];
    cin >> k;

    vector<bool> dp(k, false);
    dp[0] = true;
    for (int x : inp) {
        for (int s = k - 1; s >= x; s--) {
            if (dp[s - x]) dp[s] = true;
        }
    }
    int count = 0;
    for (int s = 1; s < k; s++) {
        if (dp[s]) count++;
    }
    cout << count << '\n';
}