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
    }
    for(int i=1;i<=n;i++){
        int temp=c[i];
        mineable_c[temp]=true;
        if(mineable_r[temp]==true&&mineable_c[temp]==true) d++;
    }
    for (int i = 0; i < q; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        int temp_r=r[x],temp_c=c[y];
        if(r[x]<z){
            if(mineable_r[temp_r]==true) {
                if(mineable_c[temp_r]==true){
                    d--;
                }
            }
            mineable_r[temp_r]=false;
            mineable_r[z]=true;
            r[x]=z;
        }
        if(c[y]<z){
            if(mineable_c[temp_c]==true){
                if(mineable_r[temp_c]==true){
                    d--;
                }
            }
            mineable_c[temp_c]=false;
            mineable_c[z]=true;
            c[y]=z;
            if(mineable_r[z]==true&&mineable_c[z]==true) d++;
        }
        
        cout<<d<<endl;
    }
    
}