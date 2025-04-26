#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    cin>>n;
    long long tol=0;
    for (int i = 0; i < n.size(); i++)
    {
        tol+=n[i]-'0';
    }
    if(tol==int(sqrt(tol))*(sqrt(tol))){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}