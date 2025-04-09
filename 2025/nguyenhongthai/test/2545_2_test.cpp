#include <bits/stdc++.h>
using namespace std;

bool isSQR(long long a, long long b)
{
    if(sqrt(a*b)==int(sqrt(a*b))){
        return true;
    }
    return false;
}

int main()
{
    set<int> inp;
    int n,d=1;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin>>x;
        for(int j:inp){
            if(isSQR(j,x)==true){
                d++;
                for(int k:inp) cout<<k<<" ";
                cout<<"\n";
                inp.erase(inp.begin(),inp.end());
                break;
            }
        }
        inp.insert(x);
    }
    for(int k:inp) cout<<k<<" ";
    cout<<"\n";
    cout<<d;   
}