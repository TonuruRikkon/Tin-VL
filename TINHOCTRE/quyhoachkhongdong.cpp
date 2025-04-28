#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> inp;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    vector<pair<int, int>> ans; 
    for (int i = 0; i < n; i++) {
        while (inp[i] != i + 1) {
            int j = inp[i] - 1; 
            swap(inp[i], inp[j]);
            ans.push_back({i + 1, j + 1});
        }
    }
    cout<<ans.size()<<'\n';
    for (auto x : ans) {
        cout <<x.first<<" "<<x.second<<'\n';
    }

    return 0;
}