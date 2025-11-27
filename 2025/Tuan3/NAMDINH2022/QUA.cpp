#include <bits/stdc++.h>
using namespace std;

vector<int> Tuoc(3*int(1e5)+1,1);

void sanguoc()
{
    Tuoc[0]=Tuoc[1]=0;
    for (int i = 2; i <= int(3*1e5); i++)
    {
        for (int j = i*2; j <= int(3*1e5); j+=i)
        {
            Tuoc[j]+=i;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    sanguoc();
    int tol=0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        if(Tuoc[x]==x){
            tol++;
            ans.push_back(x);
        }
    }
    cout<<tol<<'\n';
    for (auto &&x : ans)
    {
        cout<<x<<' ';
    }
    
}