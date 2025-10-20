// ...existing code...
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }

    auto countAtMost = [&](int K)->long long {
        if (K < 0) return 0;
        deque<int> maxd, mind;
        long long res = 0;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            while (!maxd.empty() && inp[maxd.back()] < inp[r]) maxd.pop_back();
            maxd.push_back(r);
            while (!mind.empty() && inp[mind.back()] > inp[r]) mind.pop_back();
            mind.push_back(r);
            while (!maxd.empty() && !mind.empty() && inp[maxd.front()] - inp[mind.front()] > K) {
                if (maxd.front() == l) maxd.pop_front();
                if (mind.front() == l) mind.pop_front();
                ++l;
            }
            res += r - l + 1;
        }
        return res;
    };

    long long ans = countAtMost(k) - countAtMost(k-1);
    cout << ans << '\n';
    return 0;
}
// ...existing code...