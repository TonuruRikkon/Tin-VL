#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> lop,cs;
    vector<int> dieuhoa(int(1e6),int(1e9));
    int n,ans=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        lop.push_back(x);
    }
    int m;
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        dieuhoa[x]=y;
    }
    for(int x:lop){
        ans+=*min_element(dieuhoa.begin()+x,dieuhoa.end());
    }
    cout<<ans;
}   