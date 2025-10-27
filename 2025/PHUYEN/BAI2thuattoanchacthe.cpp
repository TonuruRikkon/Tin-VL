#include <bits/stdc++.h>
using namespace std;

int hamming(int a, int b) {
    return __builtin_popcount(a ^ b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> a(N);
    for(int &x : a) cin >> x;

    sort(a.begin(), a.end());

    int ans = INT_MAX;

    for(int i = 0; i < N; i++) {
        int range = min(N, i + 64);
        for(int j = i + 1; j < range; j++) {
            ans = min(ans, hamming(a[i], a[j]));
            if(ans == 0) break;
        }
        if(ans == 0) break;
    }

    cout << ans;

    return 0;
}