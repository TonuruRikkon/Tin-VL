#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> ans; 
    for (int i = 0; i < n; i++) {
        while (a[i] != i + 1) {
            int j = a[i] - 1; 
            swap(a[i], a[j]);
            ans.push_back({i + 1, j + 1});
        }
    }
    cout<<ans.size()<<'\n';
    for (auto x : ans) {
        cout <<x.first<<" "<<x.second<<'\n';
    }

    return 0;
}