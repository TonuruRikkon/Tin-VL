#include <bits/stdc++.h>    
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }

    vector<int> DPpos(n,0),DPneg(n,0);

    int ans=0;

    for (int i = 0; i < n; i++)
    {
        if(inp[i]>0){
            DPpos[i]=1;
        }
        else if(inp[i]<0) DPneg[i]=1;
        else continue;

        for (int j = 1; j <= i; j++)
        {
            if(abs(inp[i])>abs(inp[j])){
                if(inp[i]>0&&inp[j]<0){
                    DPpos[j]=max(DPpos[i],DPneg[j-1]+1);
                }
                if(inp[i]<0&&inp[j]>0){
                    DPneg[j]=max(DPneg[i],DPpos[j-1]+1);
                }
            }
        }
        
        ans=max({ans,DPpos[i],DPneg[i]});

    }
    
    cout<<ans;
    
}