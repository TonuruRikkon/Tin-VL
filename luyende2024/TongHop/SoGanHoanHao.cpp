#include <bits/stdc++.h>
using namespace std;

vector<long long> uoc(int(1e7),0);

void tonguoc()
{
    fill(uoc.begin(),uoc.end(),0);
    for (int i = 1; i*i <= int(1e6); i++)
    {
        for (int j = i; j <= int(1e6); j+=i)
        {
            uoc[j]+=i;
        }
    }
}

int main()
{
    tonguoc();
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin>>x;
        if(x*2<=uoc[x]) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
    
}