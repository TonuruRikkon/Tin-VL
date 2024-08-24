#include<bits/stdc++.h>
using namespace std;
bool ktra1(string x,string y,string z)
{
    if(x==y&&y==z||x!=y&&y!=z&&x!=z) return true;
    return false;
}
int main()
{
    struct labai{
    string sl,mau,hinh,to;
    }a[82];
    long n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].sl>>a[i].mau>>a[i].to>>a[i].hinh;
        if(a[i].sl=="one")a[i].hinh+="s";
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int h=j+1;h<=n;h++)
            {
                if(ktra1(a[i].sl,a[j].sl,a[h].sl)==true&&ktra1(a[i].mau,a[j].mau,a[h].mau)==true&&ktra1(a[i].hinh,a[j].hinh,a[h].hinh)==true&&ktra1(a[i].to,a[j].to,a[h].to)==true)
                    ans++;
            }
        }
    }
    cout<<ans;
}