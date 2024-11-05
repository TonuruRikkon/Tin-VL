#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,ans=0;
    cin>>n>>k;
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
    int date=-*max_element(a.begin(),a.end())-k;
    while (a.empty()==false)
    {
        int maxx=max_element(b.begin(),b.end())-b.begin();
        if(abs(date-a[maxx])>=k){
            date=a[maxx];
            ans+=b[maxx];
        }
        int lowest=lower_bound(a.begin(),a.end(),a[maxx]-k)-a.begin();
        int highest=upper_bound(a.begin(),a.end(),a[maxx]+k)-a.begin()-1;
        a.erase(a.begin()+lowest,a.begin()+highest);
        b.erase(b.begin()+lowest,b.begin()+highest);
    }
    cout<<ans;
}