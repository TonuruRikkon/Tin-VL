#include <set>
#include <bits/stdc++.h>
using namespace std;

set<int> a;

void uoc(int n)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if(n%i==0){
            a.insert(i);
            if(i!=n/i) a.insert(n/i);
        }
    }
    
}

int main()
{
    int n;
    cin>>n;
    uoc(n);
    for(int i:a){
        cout<<i<<" "<<n/i<<endl;
    }
    
}