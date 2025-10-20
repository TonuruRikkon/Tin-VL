#include <bits/stdc++.h>
using namespace std;

long long modpow(long long base, long long exp, long long mod) {
    base %= mod;
    long long res = 1 % mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    if (!(cin >> a >> b)) return 0;

    int x = (int)modpow(a, b, 100);
    int y = (int)modpow(b, a, 100);
    int ans = (x + y) % 100;

    cout << setw(2) << setfill('0') << ans << '\n';
    return 0;
}