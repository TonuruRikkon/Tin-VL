#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,d=0;
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
    for(int i:a){
        if(sotien-i<0) continue;
        else{
            while (sotien>=i)
            {
                sotien-=i;
                d++;
            }

        }
    }
    
    cout<<d;
}