#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,tol=0;
    cin>>n>>k;
    vector<int> inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        tol+=x;
        inp.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int pos=i,temp=0;
        while (pos<n)
        {
            temp+=inp[pos];
            pos+=k;
            for (int j = pos; j < n; j++)
            {
                tol+=temp+inp[j];
            }
        }
    }
    cout<<tol;
    
}