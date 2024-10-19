#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0;
    cin>>n;
    vector<int> a,b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        b.push_back(x);
    }
    sort(a.rbegin(),a.rend());
    sort(b.begin(),b.end());
    int win=*max_element(b.begin(),b.end());
    for(int x:a){
        if(x<win){
            if((lower_bound(b.begin(),b.end(),x)-b.begin()) != x+1){
                b[lower_bound(b.begin(),b.end(),x)-b.begin()]=0;
                ans++;
            }
        }
    }
    cout<<ans;
}