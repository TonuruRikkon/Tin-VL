#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> inp(n);

    int ans=0,minn=0,maxx=0;
    for (int i = 0; i < n; i++)
    {
        cin>>inp[i];
    }
    int l=0,r=1,temp=0;
    while (r!=n)
    {
        if(inp[r]<inp[r-1]){
            if(ans<temp){
                ans=temp;
                minn=l;
                maxx=r-1;
            }
            l=r;
            temp=0;
        }
        r++;
        temp++;
        
    }
    cout<<minn+1<<' '<<maxx+1;
    
}