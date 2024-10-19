#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0;
    cin>>n;
    vector<string> str;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin>>x;
        str.push_back(x);
    }
    for(string x:str){
        char ref=x[0];
        int temp=1;
        for(int i=1; i<=x.size();i++){
            if(x[i]==ref) temp++;
            else{
                ref=x[i];
                ans=max(ans,temp);
                temp=1;
            }
        }
    }
    cout<<ans;
}