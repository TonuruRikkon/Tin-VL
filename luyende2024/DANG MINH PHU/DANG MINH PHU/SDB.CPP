#include <bits/stdc++.h>
using namespace std;

bool ngt[int(1e7)];

void sangnt(){
    memset(ngt,true,sizeof(ngt));
    ngt[0]=ngt[1]=false;
    int p=2;
    while(p*p<int(1e6)){
        for(int i=2;i<int(1e6)/p;i++){
            ngt[i*p]=false;
        }
        for(p++;p*p<int(1e6)&&ngt[p]==false;p++);
    }
}

int main()
{
    freopen("SDB.INP","r",stdin);
    freopen("SDB.OUT","w",stdout);
    int n;
    cin>>n;
    vector<int> inp,ngto;
    sangnt();
    for(int i=2;i<=int(1e6);i++){
        if(ngt[i]==true) ngto.push_back(i*i);
    }
    sort(ngto.begin(),ngto.end());
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        cout<<*upper_bound(ngto.begin(),ngto.end(),x)<<" ";
    }
}


