#include <bits/stdc++.h>
using namespace std;

int main()
{
    int_fast64_t n,d=0,sq;
    cin>>n;
    for (int i=1;i*i<=n;i++){
        d++;
        }
    cout<<d<<endl;
    for (int i=1;i*i<=n;i++){
        cout<<i*i<<" ";
    }
    return 0;
}