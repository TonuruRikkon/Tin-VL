#include <bits/stdc++.h>
using namespace std;

bool ngto[int(1e6)+1];
int uoc[int(1e6)+1];

void sangnt()
{
    memset(ngto,false,sizeof(ngto));
    memset(uoc,0,sizeof(uoc));
    ngto[0]=ngto[1]=false;
    uoc[1]=1;
    int p=2;
    while (p*p<=int(1e6))
    {
        for (int i = 0; i < int(1e6)/p; i++)
        {
            
        }
        
    }
    
}

int main()
{
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int x;
        long long tol=1;
        cin>>x;
        for (int i = 2; i <= x; i++)
        {
            tol*=i;
        }
        cout<<tol<<endl;
    }
    
}
