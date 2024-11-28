#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> inp[int(1e6)+1];
vector<int> steps('z'+1,int(1e9));

void Dijstra(pair<int,int> s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push(s);
    steps[s.second]=0;
    while (q.empty()==false)
    {
        auto topp=q.top();
        int u=topp.second;
        q.pop();
        if(topp.first>steps[u]) continue;
        for(auto v:inp[u]){
            if(steps[v.second]>steps[u]+v.first){
                steps[v.second]=steps[u]+v.first;
                q.push({steps[v.second],v.second});
            }
        }
    }
    
}

int main()
{
    vector<char> bo;
    int p,ans=int(1e9);
    char bonhat=0;
    cin>>p;
    for (int i = 0; i < p; i++)
    {
        char u,v;
        int c;
        cin>>u>>v>>c;
        if(u>='A'&&u<='Y') bo.push_back(u);
        if(v>='A'&&v<='Y') bo.push_back(v);
        inp[u].push_back({c,v});
        inp[v].push_back({c,u});
    }
    Dijstra({0,'Z'});
    for(char x:bo){
        if(ans>steps[x]){
            ans=steps[x];
            bonhat=x;
        }
    }
    cout<<bonhat<<" "<<ans;
}