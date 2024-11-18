#include <bits/stdc++.h>
using namespace std;

int ngto[int(1e6)+1];
vector<int> ngt;

void sangnt()
{
    memset(ngto,true,sizeof(ngto));
    ngto[0]=ngto[1]=false;
    int p=2;
    while (p*p<int(1e6))
    {
        ngt.push_back(p);
        for (int i = 2; i < int(1e6)/p; i++)
        {
            ngto[i*p]=false;
        }
        for(p++;p*p<int(1e6)&&ngto[p]==false;p++);
    }
}

int demnguyen(int s)
{
    int x=s,p=2,ans=0;
    for(int p:ngt){
        if(x>=p){
            x-=p;
            ans++;
        }
        else if(x>0&&x<p){
            x+=s-x;
        }
        else{
            break;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("COUNTPRIME.INP","r",stdin);
    freopen("COUNTPRIME.OUT","w",stdout);
    sangnt();
    int ref=0;
    int x;
    while(cin>>x)
    {
        cout<<demnguyen(x)<<endl;
    }
    
}