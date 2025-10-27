#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Fast I/O (often included by <bits/stdc++.h>)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n) || n == 0) {
        // Handle empty input or failed read
        cout << 0 << endl;
        return 0;
    }
    
    vector<int> inp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inp[i];
    }

    // Edge case for single element
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    int current_val = inp[0];
    int ans = 1; // The first element always starts a segment.
    bool current_is_pos = inp[0] > 0; // Tracks the sign of the segment leader.

    for (int i = 1; i < n; i++)
    {
        bool next_is_pos = inp[i] > 0;
        
        if (current_is_pos == next_is_pos)
        {
            // Case 1: Same Sign (e.g., P -> P or N -> N)
            // The segment continues. We must maintain a strictly decreasing sequence.
            if (current_val > inp[i]) {
                // Decreasing continuation is valid.
                current_val = inp[i];
                // ans does not increase here.
            }
            // else: inp[i] >= current_val, so it breaks the decreasing rule. We ignore inp[i].
            // current_val and ans remain unchanged.
        }
        else
        {
            // Case 2: Different Sign (P -> N or N -> P)
            // A new segment starts. This is a valid alternation.
            ans++; // Increment the segment count.
            current_val = inp[i]; // New segment leader.
            current_is_pos = next_is_pos; // Update the sign check.
        }
    }
    
    cout << ans << endl;
    
    return 0;
}