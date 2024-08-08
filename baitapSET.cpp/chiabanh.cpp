#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    set<int> a;
    for (int i = 1; i*i <= n; i++)
    {
        if(n%i==0){
            a.insert(i);
            a.insert(n/i);
        }
    }
    for (auto i:a)
    {
        cout<<i<<" "<<n/i<<endl;
    }
    
}