#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll n;
  cin >> n;
  vector<ll> a;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ll cnt = 0;
      while (n % i == 0) {
        n /= i;
        a.push_back(i);
      }
    }
  }
  if (n > 1) {
    a.push_back(n);
  }
  for (ll i = 0; i < a.size() - 1; i++) {
    cout << a[i] << " x ";
  }
  cout << a[a.size() - 1];
}
