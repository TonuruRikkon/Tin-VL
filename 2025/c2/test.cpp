#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define for(z) for(int i=1;i<=(z);i++)
ll b[100000],n,q,l,r;
int main()
{
    pair<ll,ll> a[100000];
    a[0]={0,0};
    cin >> n>>q;
    for (n){
    cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+1+n);
    for (n){
    b[i]=a[i].second;
    }
    for(q){
        cin>>l>>r;
        if(lower_bound(a+1,a+1+n,r)-a>=1){
            r=lower_bound(a+1,a+1+n,r)-a;
        }
        else l=1;
        if(lower_bound(a+1,a+1+n,r)-a<=n){
            r=lower_bound(a+1,a+1+n,r)-a;
        }
        else r=n;
        cout<<b[max_element(a+l,a+l+r)-a+l]<<endl;
    }

    return 0;
}