#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>,greater<int>> q;
    int n;
    double tol=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    while (q.empty()==false)
    {   
        if(q.size()==1) break;
        int u=q.top();
        q.pop();
        int v=q.top();
        q.pop();
        tol+=(u+v)*0.05;
        q.push(u+v);
    }
    cout<<fixed<<setprecision(2)<<tol;
}