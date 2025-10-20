#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long l;
    if (!(cin >> n >> l)) return 0;

    vector<long long> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < n; ++i) cin >> d[i];

    unordered_map<long long, long long> cnt;
    cnt.reserve((size_t)n * n);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ++cnt[a[i] + b[j]];

    long long ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            long long need = l - (c[i] + d[j]);
            auto it = cnt.find(need);
            if (it != cnt.end()) ans += it->second;
        }

    cout << ans << '\n';
    return 0;
}