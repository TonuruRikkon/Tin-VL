#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("ARCHA.INP","r",stdin);
    freopen("ARCHA.OUT","w",stdout);
    int n;
    cin>>n;
    string v;
    cin>>v;
    if(n==1){
        reverse(v.begin(),v.end());
    }
    string u1=v.substr(0,v.size()/2);
    string u2=v.substr(v.size()/2+1);
    int max_i=0,max_pos;
    char max_c;
    unordered_map<char,int> mp;
    for(int i=0;i<v.size();i++){
        int x=v[i];
        mp[x]++;
        if(mp[x]>max_i&&mp[x]%2!=0){
            max_i=mp[x];
            max_c=x;
            max_pos=i;
        }
    }
    cout<<max_c<<"\n";
    int u1_maxc=0;
    for(char x:u1){
        if(x==max_c){
            u1_maxc++;
        }
    }
    if(u1_maxc==max_i/2) cout<<u1;
    else cout<<u2;
}
