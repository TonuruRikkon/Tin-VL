#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 3; i++)
    {
        if(i!=0) cout<<'\n';
        string s1;
        cin>>s1;
        int sz1=s1.size();
        map<int,int> cnt;
        for (int j = 0; j < sz1; j++)
        {
            cnt[s1[j]]++;
        }
        string s2;
        cin>>s2;
        int sz2=s2.size();
        bool check=true;
        for (int j = 0; j < sz2; j++)
        {
            if(cnt[s2[j]]==0){
                check=false;
            }
        }
        if(check==false) cout<<"NO";
        else cout<<"YES";
    }
    
}