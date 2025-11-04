#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    string inp,inp2;
    cin>>inp>>inp2;
    
    int tol0=0;
    int temp=1;
    for (int i = 1; i < n; i++)
    {
        if(inp[i]==inp[i-1]){
            temp++;
        }
        else{
            tol0+=temp*temp;
            temp=1;
        }
    }
    tol0+=temp*temp;

    if(m==0){
        cout<<tol0;
        return 0;
    }

    vector<int> cnt(n+1,0);


    for (int i = 0; i < n; i++)
    {
        string inp3=inp; 
        inp3[i]=inp2[i];
        cnt[i]=0;
        int temp=1;
        for (int j = 1; j < n; j++)
        {
            if(inp3[j]==inp3[j-1]){
                temp++;
            }
            else{
                cnt[i]+=temp*temp;
                temp=1;
            }
        }
        cnt[i]+=temp*temp;
    }
    sort(cnt.begin(),cnt.end(),greater());
    int ans=tol0;
    for (int i = 0; i < m; i++)
    {
        ans=max(ans,ans+(cnt[i]-tol0));
    }
    
    cout<<ans;

}
