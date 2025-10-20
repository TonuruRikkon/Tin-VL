#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,ans=0;
    cin>>n>>m;
    vector<int> inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    sort(inp.begin(),inp.end());
    int maxi=0;
    while (m>0)
    {
        bool check=false;
        for (int i = 1; i < n; i++)
        {
            if(inp[i]<maxi){
                m--;
                check=true;
            }
        }
        if(check==false){
            maxi+=inp[0];
            m--;
        }
    }
    cout<<maxi;
}