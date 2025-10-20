#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    long long acc=1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        acc*=x%40;
        if(sqrt(acc)*sqrt(acc)==acc) cout<<"YES";
        else cout<<"NO";
        if(i!=n-1) cout<<' ';
    }
    
}