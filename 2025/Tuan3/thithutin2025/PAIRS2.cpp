#include <bits/stdc++.h>
using namespace std;
static const int MAXA = 1e6;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("PAIRS.INP","r",stdin);
    freopen("PAIRS.OUT","w",stdout);
    int n;
    cin >> n;
    vector<int> a(MAXA + 1, 0);
    int x;
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
        m = max(m, x);
    }

    long long ans = 0;
    for (int x = 1; x <= m; x++) {
        if (a[x] == 0) continue;
        if (a[x] >= 2) {
            ans += 1LL * a[x] * (a[x] - 1) / 2;
        }
        for (int j = x * 2; j <= m; j += x) {
            if (a[j] > 0) {
                ans += 1LL * a[x] * a[j];
            }
        }
    }
    cout << ans;
    return 0;
}