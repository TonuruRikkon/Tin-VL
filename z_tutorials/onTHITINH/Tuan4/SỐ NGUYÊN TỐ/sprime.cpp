#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 1e6;
vector<bool> is_prime(MAXN + 1, true);
vector<ll> checkPrime(MAXN + 1, 0);

bool tinh_tong_check(ll n) {
  ll res = 0;
  while (n > 0) {
    res += n % 10;
    n /= 10;
  }
  return (res % 5 == 0);
}

void sang() {
  is_prime[0] = is_prime[1] = false;

  for (ll i = 2; i * i <= MAXN; i++) {
    if (is_prime[i]) {
      for (ll j = i * i; j <= MAXN; j += i) {
        is_prime[j] = false;
      }
    }
  }

  for (ll i = 1; i <= MAXN; i++) {
    checkPrime[i] = checkPrime[i - 1];
    if (is_prime[i] && tinh_tong_check(i)) {
      checkPrime[i]++;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  sang();

  int T;
  cin >> T;

  while (T--) {
    ll l, r;
    cin >> l >> r;
    if (l < 1)
      l = 1;
    cout << checkPrime[r] - checkPrime[l - 1] << "\n";
  }
}
