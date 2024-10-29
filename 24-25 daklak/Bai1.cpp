#include <bits/stdc++.h>
using namespace std;

bool check(long long x){
    long long u=x;
    while (u>0)
    {
        long long v=u%10;
        if(v==0||x%v!=0) return false;
        u=u/10;
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