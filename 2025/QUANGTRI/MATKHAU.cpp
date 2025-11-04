#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int sz=str.size();
    if(str.size()<6){
        cout<<0;
        return 0;
    }
    map<char,int> check;
    int l=0,r=5,ans=0;

    for (int i = 0; i <= 5; i++)
    {
        if(isupper(str[i])) check['A']++;
        if(islower(str[i])) check['a']++;
        if(isdigit(str[i])) check['0']++;
    }

    while (l<r)
    {
        if(r-l+1==6) {
            if(check['A']>0&&check['a']>0&&check['0']>0)ans+=sz-r;
        }
        if(r<sz-1){
            r++;
            if(isupper(str[r])) check['A']++;
            if(islower(str[r])) check['a']++;
            if(isdigit(str[r])) check['0']++;
        }
        if(isupper(str[l])) check['A']--;
        if(islower(str[l])) check['a']--;
        if(isdigit(str[l])) check['0']--;
        l++;
    }

    cout<<ans;
    
}