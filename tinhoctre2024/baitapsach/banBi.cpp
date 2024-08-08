#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    int long long tol=0;
    cin>>n>>q;
    vector<int> A;
    A.push_back(0);
    vector<pair<int,int>> Q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        tol+=x;
        A.push_back(tol);
    }
    for (int i = 0; i < q; i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<A[y]-A[x-1]<<endl;
    }
}