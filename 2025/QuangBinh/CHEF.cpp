#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0,tol=0;
    cin>>n;
    vector<int> bb,bl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        bb.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        bl.push_back(x);
        tol+=x;
    }
    vector<int> deltaNGOL;
    for (int i = 0; i < n; i++)
    {
        deltaNGOL.push_back(bb[i]-bl[i]);
    }
    sort(deltaNGOL.begin(),deltaNGOL.end(),greater());
    vector<int> sumNgol;
    sumNgol.push_back(0);
    for (int i = 0; i < n; i++)
    {
        sumNgol.push_back(sumNgol[i]+deltaNGOL[i]);
    }
    
    for (int i = 1; i <= n; i++)
    {
        cout<<tol+sumNgol[i];
        if(i!=n) cout<<' ';
    }
    

}