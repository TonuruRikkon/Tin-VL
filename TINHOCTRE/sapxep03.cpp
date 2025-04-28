#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d = 0;
    cin >> n;
    vector<int> inp(n);
    for (int i = 0; i < n; i++) {
        cin >> inp[i];
    }

    vector<pair<int, int>> ans;
    vector<int> ref=inp;
    sort(ref.begin(),ref.end());
    for (int i = 0; i < n; i++) {
        if(inp[i]==ref[i]) continue;
        auto it = min_element(inp.begin() + i, inp.end());
        if (it != inp.begin() + i) {
            int x = *it;
            ans.push_back({x, inp[i]});
            d++;
            swap(inp[i], *it);
        }
    }

    cout << d << '\n';
    for (const auto& x : ans) {
        cout << x.first << ' ' << x.second << '\n';
    }

    return 0;
}