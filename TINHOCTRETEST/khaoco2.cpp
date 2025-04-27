#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin>>k;
    char doub;
    string V;
    cin>>V;
    if(k==1) reverse(V.begin(),V.end());
    long long tolV=0;
    for (int i = 0; i < V.size(); i++)
    {
        tolV+=V[i];
    }
    for (char i = 'a'; i <= 'z'; i++)
    {
        if((tolV-i)%2==0){
            doub=i;
            break;
        } 
    }
    cout<<'\n'<<doub<<'\n';
    for(int i=0; i<V.size();i++)
    {
        if(V[i]==doub){
            string U=V;
            U.erase(i,1);
            if(U.substr(0,U.size()/2)==U.substr(U.size()/2)) {
                cout<<doub<<'\n';
                cout<<U.substr(0,U.size()/2);
                break;
            }
        }
    }
    return 0;
    
}