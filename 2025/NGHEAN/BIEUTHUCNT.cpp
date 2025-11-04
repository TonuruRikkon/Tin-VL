#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

void sangnt(vector<int> &nt, vector<bool> &tfnt) {
  tfnt[0] = tfnt[1] = false;
  for (int i = 2; i * i < int(1e7); i++) {
    if (tfnt[i] == true) {
      nt.push_back(i);
      for (int j = i * i; j < int(1e7); j++) {
        tfnt[j] = false;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> nt(int(1e7));
  vector<bool> tfnt(int(1e7), true);
  sangnt(nt, tfnt);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (tfnt[i + 2] == true) {
      int pos1 = upper_bound(nt.begin(), nt.end(), i * 2 * n) - nt.begin();
      int pos2 = lower_bound(nt.begin(), nt.end(), i + 2) - nt.begin();
      ans += pos1 + pos2;
    }
  }
  cout << ans;
  return 0;
}
