#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,max_size=0;
    cin>>n;
    vector<int> inp[101];
    for (int i = 0; i < n; i++)
    {
        int d=0;
        string str;
        cin>>str;
        reverse(str.begin(),str.end());
        for (int i = 0; i < str.size(); i++)
        {
            inp[i].push_back(str[i]-'0');
            d++;
        }
        max_size=max(max_size,d);
    }
    string ans="";
    long long tol=0;
    for (int i = 0; i < max_size; i++)
    {
        for(int v:inp[i]){
            tol+=v;
        }
        ans=char((tol%10)+'0')+ans;
        tol/=10;
    }
    if(tol!=0){
        ans=to_string(tol)+ans;
    }
    cout<<ans;
}