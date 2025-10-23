#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;

i128 ipow(long long base, long long exp){
    i128 res = 1;
    i128 b = base;
    while(exp){
        if(exp & 1) res *= b;
        b *= b;
        exp >>= 1;
    }
    return res;
}

string toString(i128 x){
    if(x==0) return "0";
    bool neg = x < 0;
    if(neg) x = -x;
    string s;
    while(x>0){
        int d = (int)(x % 10);
        s.push_back('0' + d);
        x /= 10;
    }
    if(neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t)) return 0;
    vector<int> ns(t);
    int maxN = 0;
    for(int i=0;i<t;i++){ cin>>ns[i]; maxN = max(maxN, ns[i]); }

    // sieve primes up to maxN
    vector<int> primes;
    if(maxN >= 2){
        vector<char> isPrime(maxN+1, true);
        isPrime[0]=isPrime[1]=false;
        for(int p=2;p*p<=maxN;p++) if(isPrime[p])
            for(int q=p*p;q<=maxN;q+=p) isPrime[q]=false;
        for(int i=2;i<=maxN;i++) if(isPrime[i]) primes.push_back(i);
    }

    for(int n: ns){
        i128 ans = 1;
        for(int p: primes){
            if(p>n) break;
            long long e = 0;
            long long pp = p;
            while(pp <= n){
                e += n / pp;
                if(pp > n / p) break; // prevent overflow
                pp *= p;
            }
            // term = (p^(e+1) - 1) / (p - 1)
            i128 powp = ipow(p, e + 1);
            i128 term = (powp - 1) / (p - 1);
            ans *= term;
        }
        cout << toString(ans) << '\n';
    }
    return 0;
}