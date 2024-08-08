#include <bits/stdc++.h>
using namespace std;

int long long tol[int(1e6)+1];

void tonguoc()
{
    memset(tol, 0,sizeof(tol));
    
    for (int i = 1; i <= int(1e6); i++)
    {
        for (int j = 1; j <= int(1e6); j+=i)
        {
            tol[j]+=1;
        }
    
    }

}

int main()
{
    int a;
    cin>>a;
    for (int i = 0; i < a; i++)
    {
        cout<<tol[i];
    }
    
}