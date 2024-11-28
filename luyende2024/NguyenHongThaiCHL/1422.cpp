#include <bits/stdc++.h>
using namespace std;

vector<int> inp[10];
vector<bool> vis(10);
vector<int> num(10,0),low(10,0);
int timer=0;

void dfs(int s,int father)
{
    int u=s,child=0;
    vis[u]=true;
    num[u]=low[u]=timer++;
    for(auto v:inp[u]){
        if(v==father) continue;
        if(vis[v]==false){
            
        }
    }
}

int main()
{
    int n;
    cin>>n;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        string str;
        getline(cin,str);
        for(int x:str){
            if(x!=' '){
                inp[i].push_back(x-'0');
                inp[x-'0'].push_back(i);
            }
        }

    }
    
}