#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,dem=0;
    cin>>n;
    vector<int> d;
    while(n!=1){
        if(n%7==0){
            n=n/7;
            d.push_back(7);
        }
        else if(n%5==0){
            n=n/5;
            d.push_back(5);
        }
        else if(n%2==0){
            n=n/2;
            d.push_back(2);
        }
        dem++;
    }
    sort(d.begin(),d.end());
    for (int i = 0; i < dem; i++)
    {
        cout<<d[i];
        if(i!=dem-1)cout<<" x ";
    }
    
}