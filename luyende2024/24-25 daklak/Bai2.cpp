#include <bits/stdc++.h>
using namespace std;

bool ngt[2*int(1e6)];

void sangnt(){
    memset(ngt,true,sizeof(ngt));
    ngt[0]=ngt[1]=false;
    for (int i = 2; i*i <= int(1e7); i++)
    {
        if(ngt[i]==true){
            for (int j = i*i; j < int(1e7); j+=i)
            {
                ngt[j]=false;
            }
        
        }

    }
    
}

int main()
{
    
    vector<pair<int,int>> trv; 
    int n,m;
    cin>>n;
    vector<long long> inp,ngto;
    for(long long int i=2; i<=int(1e7);i++){
        if(ngt[i]==true){
            ngto.push_back(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
        int endd;
        auto it=lower_bound(ngto.begin(),ngto.end(),x);
        if(it != ngto.end()){
            endd=it-ngto.begin();   
        }
        else endd=0;
        for (int j = 0; j <= endd; j++)
        {
            if(x%ngto[i]==0) 
        }
        
    }
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        trv.push_back(make_pair(x,y));
    }

}