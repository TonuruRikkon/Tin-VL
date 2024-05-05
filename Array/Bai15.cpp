#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,d=0,s[1000],s_d=0;
    double a[1000];
    memset(s, 0, sizeof(s));
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]>0) d++;
        else{
            s[s_d] = d;
            d=0;
            s_d++;
        }
    }
    cout<<*max_element(s,s+n);
}