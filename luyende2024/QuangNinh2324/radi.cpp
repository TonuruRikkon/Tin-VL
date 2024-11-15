#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,q,d=0;
    cin>>m>>n>>q;
    vector<int> r(m+1,0);
    vector<int> c(n+1,0);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin>>x;
            r[i]=max(r[i],x);
            c[j]=max(c[j],x);
        }
    }
    map<int,bool> mineable_r,mineable_c;
    for(int i=1;i<=m;i++){
        mineable_r[r[i]]=true;
        cout<<r[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        mineable_c[c[i]]=true;
        cout<<c[i]<<" ";
    }
    cout<<endl;
    for(auto x:mineable_r){
        if(x.second==true){
            if(mineable_r[x.first]==mineable_c[x.first]){
                d++;
            }            
        }
    }
    for (int i = 0; i < q; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(r[x]<z){
            if(mineable_r[r[x]]==true) {
                mineable_r[r[x]]=false;
                mineable_r[z]=true;
                if(mineable_c[c[y]]==true){
                    d--;
                }
            }
        }
        if(c[y]<z){
            if(mineable_c[c[y]]==true){
                mineable_c[c[y]]=false;
                mineable_c[z]=true;
                if(mineable_r[r[x]]==true){
                    d--;
                }
            }
        }
        if(mineable_r[z]==true&&mineable_c[z]==true) d++;
        cout<<d<<endl;
    }
    
}