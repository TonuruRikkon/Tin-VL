#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll n, c;
  cin >> n >> c;
  vector<pair<ll, ll>> a(n);
  for (auto &x : a) {
    cin >> x.first >> x.second;
  }
  sort(a.begin(), a.end());
  ll res = 0;
  for (auto x : a) {
    if (x.first <= c) {
      res++;
      c += x.second;
    } else {
      break;
    }
  }
  cout << res;
}
