#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ARCHA.INP","r",stdin);
    freopen("ARCHA.OUT","w",stdout);
    int n; cin>>n;
    string s; cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]==s[i+1]){
            cout<<s[i]<<"\n";
            break;
        }
    for(int i=0;i<s.size();i++){
        if(s[i]==s[i+1]){
        s.erase(i,1);
        if(s.size()%2==0){
            string a=s.substr(0,s.size()/2);
            string b=s.substr(s.size()/2,s.size());
            if(a==b and n==0){
                cout<<a;
                return 0;
            }
            if(a==b and n==1){
                reverse(a.begin(),a.end());
                cout<<a;
                return 0;
            }
            }
        }
    }
}
