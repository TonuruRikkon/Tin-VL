#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0;
    cin>>n;
    vector<int> a;
    for(int i=0; i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    int sotien;
    cin>>sotien;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for(auto i:a){
        while(sotien%i==0){
            sotien-=i;
            ans++;
            cout<<sotien<<" "<<i<<endl;
        }
    }
    cout<<ans;
}