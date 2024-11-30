#include <bits/stdc++.h>
using namespace std;

vector<bool> ngto(int(1e7)+1,true);
void sangnt()
{
    ngto.resize(int(1e7)+1,true);
    ngto[0]=ngto[1]=false;
    int p=2;
    while (p*p<=int(1e7))
    {   
        for (int i = 2; i <= int(1e7)/p; i++)
        {
            ngto[p*i]=false;
        }
        for(p++;p*p<=int(1e7)&&ngto[p]==false;p++);
    }
    
}

int main()
{
    vector<int> slngto;
    slngto.push_back(0);
    int t;
    cin>>t;
    sangnt();
    int ans=0;
    for(int i; i<=int(1e7);i++){
        if(ngto[i]==true){
            int u=i,tol=0;
            while (u>0)
            {
                tol+=u%10;
                u/=10;
            }
            if(tol%5==0) ans++;
        }
        slngto.push_back(ans);
    }
    for (int i = 0; i < t; i++)
    {
        int L,R;
        cin>>L>>R;
        cout<<slngto[R]-slngto[L]<<"\n";
    }
    
}