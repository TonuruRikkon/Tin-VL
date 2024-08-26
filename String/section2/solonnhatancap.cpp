#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,z;
    long d[10],b=0,a[10],x[10];
    memset(d,0,sizeof(d));memset(a,0,sizeof(a));
    cin>>s>>z;
    for(int i=0;i<=s.size()-1;i++)
        d[s[i]-'0']++;
    for(int i=0;i<=z.size()-1;i++)
        a[z[i]-'0']++;
    for(int i=9;i>=0;i--)
    {
        if(d[i]>0&&a[i]);else b++;
        x[i]=min(d[i],a[i]);
        if(b==9&&i==0&&d[i]>0)cout<<0;
        else
            while(x[i]>0)
            {
                cout<<i;
                x[i]--;
            }

    }
    if(b==10) cout<<-1;
}
