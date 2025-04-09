#include <bits/stdc++.h>
using namespace std;

int ThuaSo(long long a)
{
    int d=1;
    long long tol=1;
    while(a!=1){
        d++;
        int count=0;
        while(a%d==0){
            a/=d;
            count++;
        }
        if(count%2!=0){
            tol*=d;
        }
    }
    return tol;
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
        int temp=ThuaSo(x);
        if(inp.find(temp)==inp.end()){
            inp.insert(temp);
        }
        else{
            inp.erase(inp.begin(),inp.end());
            d++;
        }

    }
    cout<<d;
}