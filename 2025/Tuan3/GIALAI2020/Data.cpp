#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> inp(n);

    int ans=0;
    for (int i = 0; i < n; i++)
    {
        cin>>inp[i];
    }
    int last=0,first=0,tol=1;
    int ansl=0,ansf=0;
    for (int i = 0; i < n; i++)
    {
        if(inp[last]<=inp[i]){
            last=i;
            tol++;
        }
        else{
            if(tol>ans){
                ans=tol;
                ansl=last;
                ansf=first;
            }
            first=i;
            last=0;
            tol=1;
        }
    }
    cout<<ansf+1<<' '<<ansl+1;
    
}