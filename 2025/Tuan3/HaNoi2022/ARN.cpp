#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ARN.INP", "r", stdin);
    freopen("ARN.OUT", "w", stdout);
    string str;
    cin>>str;
    string ref;
    cin>>ref;
    string temp;
    int sz=ref.size();
    int ans=0;
    bool check=false;
    for (char c : str)
    {
        if(temp.size()==sz) temp.erase(0,1);
        temp.push_back(c);
        if(temp==ref) {
            if(check==false) ans++;
            check=true;
        }
        else{
            check=false;
        }
    }
    cout<<ans;
}