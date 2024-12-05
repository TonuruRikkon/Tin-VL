#include<bits/stdc++.h>
using namespace std;
void ktra(vector<string> k)
{

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ARCHA.INP","r",stdin);
    freopen("ARCHA.OUT","w",stdout);
    int n;
    string s;
    cin>>n;
    cin>>s;
    vector<char>nhandoi(0);
    vector<string>luu;
    map<char,int>mp;
    for(int i=0;i<s.size();i++)
    {

        if(s[i]==s[i+1]) {
            nhandoi.push_back(s[i]);
            continue;
        }
        mp[s[i]]++;
        for(auto x:mp){
            if(x.second!=1) break;
        }
    }
    vector<char>kq;
    for(char h:nhandoi) cout<<h<<endl ;
    for(auto k:mp)
    {
           kq.push_back(k.first);
    }

    if(n==1) {
    reverse(kq.begin(),kq.end());
        for(auto m:kq)
        {
               cout<<m;
        }
    }
    if(n==0) {
        for(auto m:kq)
        {
               cout<<m;
        }
    }
}

