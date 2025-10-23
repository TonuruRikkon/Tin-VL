#include <bits/stdc++.h>
using namespace std;

long long C(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    // Tối ưu hóa: C(n, k) = C(n, n-k)
    if (k > n / 2) {
        k = n - k;
    }
    long long res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int main()
{
    long long n,k,ans=0;
    cin>>n>>k;
    int fst = __builtin_ffsll(n)-1;
    ans+=C(fst,k);
    int lst = 64-__builtin_clzll(n)-1;
    ans+=C(lst,k);
    cout<<ans;
}