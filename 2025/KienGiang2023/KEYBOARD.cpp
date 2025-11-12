#include <bits/stdc++.h>
using namespace std;

bool check(string &s)
{
    int i=0;
    while (i<s.size()-2)
    {
        if(s[i+1]!=s[i+2])
        {
            return false;
        }
        else{
            i+=3;
        }
    }
    return true;
    
}

int main()
{
    int n;
    cin>>n;
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        ans+=check(s);
    }
    cout<<ans;
        
}