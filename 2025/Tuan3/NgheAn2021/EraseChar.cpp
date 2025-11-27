#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    string temp;
    bool check=false;
    for (int i = 0; i+(n-k) <= n; i++)
    {
        temp=str.substr(i,n-k);
        string rev=temp;
        reverse(rev.begin(),rev.end());
        // cout<<temp<<' '<<rev<<'\n';
        if(rev==temp) {
            check=true;
            cout<<rev;
            break;
        }
    }
    if(check==false) cout<<"NO";
    
}