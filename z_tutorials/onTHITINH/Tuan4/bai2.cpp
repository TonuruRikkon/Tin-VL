#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 1e6 + 5;
vector<bool> is_prime(MAXN, 1);
vector<ll> prime(MAXN, 0);

void sang() {
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i * i < MAXN; i++) {
    if (is_prime[i]) {
      for (ll j = i * i; j < MAXN; j += i) {
        is_prime[j] = false;
      }
    }
  }
  for (ll i = 2; i < MAXN; i++) {
    prime[i] = prime[i - 1];
    if (is_prime[i])
      prime[i]++;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  sang();
  ll n;
  cin >> n;
  while (n--) {
    ll l, r;
    cin >> l >> r;
    cout << prime[r] - prime[l - 1] << "\n";
  }
}
