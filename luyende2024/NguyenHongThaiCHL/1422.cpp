#include <bits/stdc++.h>
using namespace std;

vector<int> inp[10];
vector<bool> vis(10);
vector<int> tim(10,0),low(10,0);
vector<int> DinhKhop;
int timer=0;

void dfs(int s,int father)
{
    int u=s,child=0;
    vis[u]=true;
    tim[u]=low[u]=timer++;
    for(auto v:inp[u]){
        if(v==father) continue;
        if(vis[v]==false){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=tim[u]&&father!=-1) DinhKhop.push_back(u); 
            child++;
        }
        else{
            low[u]=min(low[u],low[v]);
        }
    }
    if(child>1&&father==-1) DinhKhop.push_back(u);
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
    dfs(0,-1);
    if(DinhKhop.size()==0) cout<<"Granny can make the circuit.";
    else cout<<"Granny can not make the circuit.";
}