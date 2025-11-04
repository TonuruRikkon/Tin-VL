#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    long long max_reachable = 0;
    for (int i = 0; i < n; i++)
    {
        if (coins[i] > max_reachable + 1)
        {
            break;
        }
        max_reachable += coins[i];
    }
    cout << max_reachable + 1 << endl;
    return 0;
}