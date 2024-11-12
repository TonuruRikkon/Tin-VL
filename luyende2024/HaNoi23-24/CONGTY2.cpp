#include <bits/stdc++.h>
using namespace std;

struct diem{
    int id,sal;
    vector<int> empl;
};

vector<diem> point((2*int(1e5))+1);
vector<int> outp((2*int(1e5))+1,0);
vector<long long> ans((2*int(1e5))+1);
long long tol=0;

void dfs(int s)
{
    int u=s;
    ans[u]=1;
    for(int v:point[u].empl){
        dfs(v);
        if(point[v].sal<=point[u].sal){
            if(tol>ans[v]){
                ans[u]+=tol;
                tol=0;
            }
            else ans[u]+=ans[v];
        }
        else{
            tol+=ans[v];
        }
    }
    outp[u]=max(ans[u],tol);
}

int main()
{
    outp.resize((2*int(1e5))+1,0);
    ans.resize((2*int(1e5))+1,0);
    int n,q;
    cin>>n>>q;
    for (int i = 1; i <= n; i++)
    {
        cin>>point[i].sal;
        point[i].id=i;
    }for (int i = 1; i <= n-1; i++)
    {
        int x;
        cin>>x;
        point[x].empl.push_back(i+1);
    }
    dfs(1);
    for (int i = 0; i < q; i++)
    {
        int x;
        cin>>x;
        cout<<outp[x]<<endl;
    }
    
    
}