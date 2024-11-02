#include<bits/stdc++.h>
using namespace std;
bool ngt[31624];vector<int_fast64_t> q;
void sdb()
{
    memset(ngt,true,sizeof(ngt));
    ngt[0]=false;
    ngt[1]=false;
    long p=2;
    while(p<=31624)
    {
        if(ngt[p]==true){
            q.push_back(p);
            for(int i=2;i<=31524/p;i++)
                ngt[p*i]=false;
        }
        for(p++;!ngt[p];p++);
    }
}
int main(){
    freopen("SDB.OUT","w",stdout);
    sdb();
    int_fast64_t n,a;
    cin>>n;
    while(n--)
    {
        cin>>a;
        int_fast64_t x=*upper_bound(q.begin(),q.end(),sqrt(a));
        cout<<x*x<<"\n";
    }
}
