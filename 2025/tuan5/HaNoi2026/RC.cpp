#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

int main()
{
    // Fast I/O is good practice in competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // Read class IDs (inp[i])
    vector<int> inp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inp[i];
    }

    // Read heights and group them by class
    vector<vector<long long>> h(m + 1); // h[class_id] stores heights for that class
    vector<long long> all_heights(n); // Stores all n heights
    for (int i = 0; i < n; i++)
    {
        long long hi;
        cin >> hi;
        h[inp[i]].push_back(hi);
        all_heights[i] = hi;
    }

    // 1. Sort ALL heights
    // Sorting the entire list allows us to use prefix sums efficiently later.
    sort(all_heights.begin(), all_heights.end());

    // 2. Calculate Prefix Sums
    // prefix_sum[i] will store the sum of the first i heights in the sorted list.
    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        prefix_sum[i + 1] = prefix_sum[i] + all_heights[i];
    }

    // 3. Calculate Total Answer
    long long ans = 0;
    
    // We iterate through each class 'i' (1 to m)
    for (int i = 1; i <= m; ++i)
    {
        // Calculate the sum of differences *between* trees in class 'i'
        // and *all other* trees.
        
        for (long long x : h[i]) // For each tree 'x' in class 'i'
        {
            // Find the split point in the sorted 'all_heights' list.
            // 'it' points to the first element > x.
            auto it = upper_bound(all_heights.begin(), all_heights.end(), x);
            
            // 'k' is the count of trees (y) where y <= x
            int k = it - all_heights.begin(); 
            
            // The remaining trees (count 'n - k') are those where y > x
            int n_minus_k = n - k;
            
            // --- Contribution from trees y <= x ---
            // Sum of y's in this range: prefix_sum[k]
            // Sum of differences = sum(x - y) = k*x - sum(y)
            long long diff_le = k * x - prefix_sum[k];

            // --- Contribution from trees y > x ---
            // Sum of y's in this range: prefix_sum[n] - prefix_sum[k]
            // Sum of differences = sum(y - x) = sum(y) - (n-k)*x
            long long diff_gt = (prefix_sum[n] - prefix_sum[k]) - n_minus_k * x;

            // This is the sum of |x - y| for ALL other trees y (including those in class i).
            long long total_diff_all = diff_le + diff_gt;
            
            // --- Correction Step ---
            // The problem requires differences only between *different* classes.
            // We must subtract the differences *within* class i.
            // The internal differences are always 0 because |x - x| = 0.
            // **HOWEVER**, we need to subtract the difference calculated against trees
            // that are also in class 'i', which are included in 'total_diff_all'.
            
            // Since x is in class 'i', the total_diff_all includes |x - x| for this one tree.
            // Since |x - x| is 0, no subtraction is necessary for the tree itself.
            
            // Wait, the calculation `total_diff_all` is the sum of $|x - y|$ over **all** trees $y$ ($n$ trees).
            // We only want the sum of $|x - y|$ where $y \notin \text{Class } i$.
            
            // We must calculate and subtract the sum of differences within class $i$:
            long long internal_diff_sum = 0;
            for (long long y_in_i : h[i]) {
                internal_diff_sum += abs(x - y_in_i);
            }
            
            // Subtract the difference accumulated with trees y that are in the SAME class i.
            // Note: This must be done for *every* tree $x$ in $h[i]$.
            ans += (total_diff_all - internal_diff_sum);
        }
    }

    // Since we computed the sum of $|x-y|$ where $x$ and $y$ are in the SAME class,
    // the final answer has been counted TWICE (once for pair (x, y) and once for (y, x)).
    // However, the *internal* subtraction already accounts for double counting *within* a class.
    
    // The total difference is between tree A in class i, and tree B in class j (j != i).
    // The code calculates: sum_{x in i} ( sum_{y in ALL} |x-y| - sum_{y in i} |x-y| )
    
    // Final Answer Counting:
    // Pair (A in i, B in j) is counted:
    // 1. When x=A, y=B (in the total_diff_all step)
    // 2. When x=B, y=A (in a later loop iteration, when x is in class j)
    
    // Since every valid pair (A, B) is counted twice, we must divide the final result by 2.
    cout << ans / 2;

    return 0;
}