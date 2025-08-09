#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    for (int i = 0; i < k; i++)
    {
        int l,r;
        cin>>l>>r;
        string str=s.substr(l-1,r-l+1),ref=str;
        reverse(ref.begin(),ref.end());
        cout<<str<<' '<<ref<<'\n';
        if(str==ref) cout<<1<<'\n';
        else cout<<-1<<'\n';
    }
    
}