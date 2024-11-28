#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen ("kitudautien.inp","r",stdin);
    freopen ("kitudautien.out", "w", stdout);
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        vector<bool> vis('z'+1,false);
        bool found=false;
        string str;
        cin>>str;
        for (int i = 0; i < str.size(); i++)
        {
            if(count(str.begin(),str.end(),str[i])==1&&vis[str[i]]==false){
                cout<<i+1<<"\n";
                vis[str[i]]=true;
                found=true;
                break;
            }
        }
        if(found==false) cout<<-1<<"\n";
    }
    
}