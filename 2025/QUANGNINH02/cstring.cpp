#include <bits/stdc++.h>
using namespace std;

int main()
{
    string ref,str;
    cin>>ref>>str;
    int l=0,r=1;
    long long tol=str[0];
    int sz=1;
    int refsz=ref.size();
    int n=str.size();
    string temp=str.substr(0,refsz);
    int ans=0;
    for(int i=refsz; i<n;i++)
    {
        if(temp==ref) ans++;
        temp.erase(0,1);
        temp.push_back(str[i]);
    }
    if(temp==ref) ans++;
    cout<<ans;

}