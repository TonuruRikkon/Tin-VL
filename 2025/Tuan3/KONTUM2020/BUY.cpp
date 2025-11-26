#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    int T;
    cin>>T;
    for (int t = 0; t < T; t++)
    {
        long long x;
        cin>>x;
        long long temp=x;
        while (temp/10!=0)
        {
            x+=temp/10;
            temp=temp%10+temp/10;
        }
        cout<<x<<'\n';
        
    }
    
}