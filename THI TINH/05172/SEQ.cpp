#include<bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000];
int biendoi[100000];
int n,m,i,j,ans=0;
int main()
{
    freopen("SEQ.INP","r",stdin);
    freopen("SEQ.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for( i=0;i<n;i++)
    {
        cin>>a[i];
        biendoi[i]=a[i]+biendoi[i-1];
    }
    for( j=0;j<m;j++)
    {
        cin>>b[j];
    }
    for(int i=0;i<n;i++)
    {
        if(b[j]==biendoi[i])
            cout<<i<<" ";
        else
            cout<<-1<<" ";
    }
}
