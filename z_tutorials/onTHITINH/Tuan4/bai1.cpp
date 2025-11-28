#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll n;
  cin >> n;
  if (n == 1) {
    cout << "NO";
    return 0;
  } else {
    for (ll i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
}
