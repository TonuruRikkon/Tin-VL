#include <bits/stdc++.h>   
using namespace std;

int main()
{
    int k;
    cin>>k;
    string V;
    cin>>V;
    if(k==1){
        reverse(V.begin(),V.end());
    }
    int pos=V.size()/2;
    string ans="";
    for (int i = 0; i < V.size()/2; i++)
    {
        if(V[i]!=V[pos+i]){
            string U=V,E=V;
            E.erase(pos+i,1);
            U.erase(i,1);
            if(U.substr(0,U.size()/2)==U.substr(U.size()/2)){
                cout<<V[i]<<'\n';
                cout<<U.substr(0,U.size()/2);
                return 0;
            }
            else if(E.substr(0,E.size()/2)==E.substr(E.size()/2)){
                cout<<V[pos+i]<<'\n';
                cout<<E.substr(0,E.size()/2);
                return 0;
            }
        }
    }
    cout<<V[V.size()-1]<<'\n';
    V.erase(V.size()-1,1);
    cout<<V.substr(V.size()/2);
    return 0;
}