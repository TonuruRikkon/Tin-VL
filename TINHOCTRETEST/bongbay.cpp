#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        s.push_back(x);
    }
    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int l,r;
        cin>>l>>r;
        int d=0;
        for(int j=l-1; j<=r-1; j++){
            for(int j2=j+1;j2<=r-1;j2++){
                if(s[j]>s[j2]){
                    d++;
                }
            }
        }
        cout<<d<<"\n";
    }
    return 0;
}