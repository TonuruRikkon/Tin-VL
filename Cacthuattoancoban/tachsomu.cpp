#include <bits/stdc++.h>
using namespace std;

int main()
{
    int long long n,k=0;
    cin>>n;
    vector<int> a; //so
    vector<int> p; //mu
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(n%i==0){
            a.push_back(i);
            while (n%i==0)
            {
                k++;
                n/=i;
            }
            p.push_back(k);
            k=0;
        }
    }
    if(n>1){
        a.push_back(n);
        p.push_back(1);
    }
    for (int i = 0; i < a.size()-1; i++)
    {
        cout<<a[i]<<"^"<<p[i]<<" x ";
    }
    cout<<a[a.size()-1]<<"^"<<p[a.size()-1];
}