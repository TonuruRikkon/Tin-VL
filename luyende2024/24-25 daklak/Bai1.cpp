#include <bits/stdc++.h>
using namespace std;

bool check(long long x){
    long long u=x;
    set<int> d;
    while (u>0)
    {
        long long v=u%10;
        if(v==0) return false;
        d.insert(v);
        u=u/10;
    }
    for(int y:d){
        if(x%y!=0) return false;
    }
    return true;
}

int main()
{
    vector<long long> inp,ans;
    int n,d=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin>>x;
        if(check(x)==true){
            d++;
            ans.push_back(x);
        }
    }
    cout<<d<<endl;
    for(long long x:ans){
        cout<<x<<" ";
    }

}