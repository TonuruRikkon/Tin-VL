#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    vector<int> ind(10,0);
    int tol=0,ans=0;
    for (int i = 0; i < str.size(); i++)
    {
        tol+=str[i]-'0';
    }
    for (int i = 0; i < str.size(); i++)
    {
        if(ind[str[i]-'0']) {
            ans++;
            if((tol-(str[i]-'0'))%3) tol-=str[i]-'0';
        }
        else if((tol-(str[i]-'0'))%3==0){
            ind[str[i]-'0']=1;
            tol-=str[i]-'0';
            ans++;
        }
    }
    cout<<ans;
}