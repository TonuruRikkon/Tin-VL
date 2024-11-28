#include <bits/stdc++.h>
using namespace std;

vector<int> inp[int(11)];
int vis[11];

void dfs(int s){
    for(int v:inp[s]){
        if(vis[v]==false) {
            dfs(v);
        }
    }
}

bool print(int n)
{
    for(int i=0;i<=n;i++){
        if(vis[i]!=1) return false;
    }    
    return true;
}

int main()
{
    memset(vis,0,sizeof(vis));
    int n;
    cin>>n;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        string str;
        getline(cin,str);
        for(char x:str){
            if(x!=' ') {
                inp[i].push_back(x-'0');
                inp[x-'0'].push_back(i);
            }
        }
    }
    dfs(0);
    cout<<print(n);
}