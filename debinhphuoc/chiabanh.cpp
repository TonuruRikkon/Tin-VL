#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    set<long long> a;
    for (long long i = 1; i*i <= n; i++)
    {
        if(n%i==0){
            a.insert(i);
            a.insert(n/i);
        }
    }
    for (auto i:a)
    {
        cout<<i<<" "<<n/i<<endl;
    }
    
}