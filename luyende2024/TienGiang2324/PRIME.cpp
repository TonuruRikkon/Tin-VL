#include <bits/stdc++.h>
using namespace std;

vector<int> ngto(int(1e6));
vector<int> dUoc(int(1e6)+1,0);

void sangnt(){
    ngto.resize(int(1e6),true);
    dUoc.resize(int(1e6)+1,0);
    fill(ngto.begin(),ngto.end(),true);
    ngto[0]=ngto[1]=false;
    int p=2;
    while (p*p<=int(1e6))
    {
        for (int i = 2; i <= int(1e6)/p; i++)
        {
            ngto[i*p]=false;
            dUoc[i*p]++;
        }
        dUoc[p]=1;
        for(p++;p*p<=int(1e6)&&ngto[p]==false;p++);
    }
    
}

int main()
{
    int n,maxx=0,ans;
    cin>>n;
    sangnt();
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        if(maxx<dUoc[x]){
            maxx=dUoc[x];
            ans=x;
            
        }
    }
    cout<<ans;
    
}