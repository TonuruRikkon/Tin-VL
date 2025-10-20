#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> bb(n), bl(n);
    for (int i = 0; i < n; ++i) cin >> bb[i];
    long long base = 0;
    for (int i = 0; i < n; ++i) {
        cin >> bl[i];
        base += bl[i];
    }
    vector<long long> diff(n);
    for (int i = 0; i < n; ++i) diff[i] = bb[i] - bl[i];
    sort(diff.begin(), diff.end(), greater<long long>());
    vector<long long> pref(n+1, 0);
    for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] + diff[i-1];

    for (int k = 1; k <= n; ++k) {
        cout << base + pref[k];
        if(k!=n) cout<<' ';
    }
    return 0;
}