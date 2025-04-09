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
    map<int,int> inp;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin>>x;
        inp[ThuaSo(x)]++;
    }
    cout<<inp.size();
}