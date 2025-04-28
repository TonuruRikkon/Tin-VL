#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Map to track groups of indices
    map<int, vector<int>> tol;
    for (int i = 0; i < n; i++) {
        tol[i].push_back(i); // Store indices instead of characters
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        // Merge group x into group y
        if (tol.count(x)) {
            for (int j : tol[x]) {
                tol[y].push_back(j);
            }
            tol.erase(x); // Remove group x after merging
        }
    }

    // Create the result vector
    vector<int> ans(n);
    for (const auto& x : tol) {
        for (int y : x.second) {
            ans[y] = x.first; // Map each index to its group
        }
    }

    // Output the result
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}