#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n==1){
        string temp=s;
        for (int i = 0; i < s.size(); i++)
        {
            s[s.size()-i-1]=temp[i];
        }
    }
    char ans;
    int i=0,j=s.size()/2,indc=0;
    while (true)
    {
        if(s[i]!=s[j]){
            
        }
        else{
            i++;
            j++;
            if(j==s.size()) break;
        }
    }
    cout<<ans<<'\n';
    if(indc==1) cout<<s.substr(0,s.size()/2);
    else cout<<s.substr(s.size()/2,s.size()/2);
}