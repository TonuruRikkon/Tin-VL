#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    vector<long long> tien={1,  2,  5,  10,  20,  50,  100,  200,  500,  1000,  2000,  5000,  10000, 
20000, 50000};
    tien.push_back(n);
    sort(tien.begin(), tien.end(), greater<int>());
    long long inp;
    while (cin>>inp)
    {
        int rem=inp;
        long long ans=0;
        for(long long x:tien){
            ans+=rem/x;
            rem=rem%x;
            if(rem==0) break;
        }
        
        cout<<ans<<'\n';
    }
    
}