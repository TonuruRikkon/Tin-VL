#include <bits/stdc++.h>
using namespace std;


vector<bool> isNto(int(1e6)+1,true);
void sangnt(){
    isNto[0]=isNto[1]=false;
    for (int i = 2; i*i <= int(1e6); i++)
    {
        if(isNto[i]==true){
            for (int j = i*i; j <= int(1e6); j+=i)
            {
                isNto[j]=false;
            }
            
        }
    }
    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("DAYCON.INP", "r", stdin);
    freopen("DAYCON.OUT", "w", stdout);
    int n;
    cin>>n;
    int x,pos=-1;
    int ans=INT_MAX;
    sangnt();
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        if(isNto[x]==true){
            if(pos==-1){
                pos=i;
            } 
            else{
                ans=min(ans,i-pos+1);
                pos=i;
            }
        }
    }
    if(ans==INT_MAX) cout<<-1;
    else cout<<ans;
    return 0;
}