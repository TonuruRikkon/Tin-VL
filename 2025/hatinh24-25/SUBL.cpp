#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a,tol;
    unsigned long long n,m,t=0;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        t+=x;
        a.emplace_back(x);
        tol.emplace_back(t);
    }   
    auto it=lower_bound(tol.begin(),tol.end(),m);
    int k=it-tol.begin();
    bool ansok=false;
    for (int i = k; i < n; i++)
    {
        bool tf=true;
        for (int j = i; j < n; j++)
        {
            if(tol[j]-tol[j-i]<m){
                tf=false;
                break;
            }         
        }
        if(tf==true){
            cout<<i;
            ansok=true;
            break;
        }
    }
    if(ansok==false) cout<<-1; 
}