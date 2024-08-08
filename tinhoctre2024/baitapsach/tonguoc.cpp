#include <bits/stdc++.h>
using namespace std;

int long long tol[int(1e6)+1];

void tonguoc()
{
    memset(tol,0,sizeof(tol));
    for (int i = 1; i < int(1e6); i++)
    {
        for (int j = i; j < int(1e6); j+=i)
        {
            tol[j]+=i;
        }
    }
}

int main()
{
    tonguoc();
    int q;
    cin>>q;
    vector<pair<int,int>> a;
    for (int i = 0; i < q; i++)
    {
        int x,y;
        cin>>x>>y;
        a.push_back(make_pair(x,y));
    }
    for (int i = 1; i <= int(1e6); i++)
    {   

    }
    for(auto i:a){
        int d=0;
        for (int j = i.first; j <= i.second; j++)
        {
            if(tol[j]%2 == 0&&tol[j]!=0)
            {
                d++;
            }
        }
        cout<<d<<endl;
    }
}