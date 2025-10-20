#include <bits/stdc++.h>
using namespace std;

void fibonaci(vector<long long> &fibo){
    fibo.push_back(1);
    fibo.push_back(2);
    for (int i = 2; i < 20; i++)
    {
        fibo.push_back(fibo[i-1]+fibo[i-2]);
    }
}

int main()
{
    int m;
    cin>>m;
    vector<long long> fibo;
    fibonaci(fibo);
    cout<<lower_bound(fibo.begin(),fibo.end(),m)-fibo.begin()+1;
}