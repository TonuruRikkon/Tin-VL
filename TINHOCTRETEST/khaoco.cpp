#include <bits/stdc++.h>   
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin>>k;
    string V;
    cin>>V;
    if(k==1){
        reverse(V.begin(),V.end());
    }
    map<char,int> tol;
    char doub;
    for(int i=0;i<V.size();i++){
        tol[V[i]]++;
    }
    for (char i = 'a'; i <= 'z'; i++)
    {
        if(tol[i]%2!=0) doub=i;
    }
    string ans="";
    for (int i = 0; i <= V.size(); i++)
    {
        if(V[i]==doub){
            string U=V;
            U.erase(i,1);
            if(U.substr(0,U.size()/2)==U.substr(U.size()/2)){
                cout<<V[i]<<'\n';
                cout<<U.substr(0,U.size()/2);
                return 0;
            }
        }
    }
    cout<<V[V.size()-1]<<'\n';
    V.erase(V.size()-1,1);
    cout<<V.substr(V.size()/2);
    return 0;
}