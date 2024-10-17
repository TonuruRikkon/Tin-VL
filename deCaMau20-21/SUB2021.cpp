#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,temp=0,ans=int(1e9);
    cin>>n;
    vector<int> inp,tol;
    tol.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
        temp+=x;
        tol.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if((tol[j]-tol[i])%2021==0) 
            {
                ans=min(ans,tol[j]-tol[i]);
                break;
            }
        }
        if(ans==2021){
            cout<<ans;
            return 0;
        }
    }
    cout<<ans;
}