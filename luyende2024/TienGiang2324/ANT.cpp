#include<bits/stdc++.h>
using namespace std;

set<pair<int,int>> visited;
int Ox[4]={1,0,-1,0},Oy[4]={0,-1,0,1};
map<pair<int,int>,int> a;

void bfs(pair<int,int> s,vector<string> adudu,int n,int m)
{
    queue<pair<int,int>> q;
    q.push(s);
    pair<int,int> father=s;
    while (q.empty()==false)
    {
        bool re=false;
        int fst=q.front().first,sec=q.front().second;
        for(int i=0;i<4;i++){
            int fsti=fst+Oy[i],seci=sec+Ox[i];
            if(make_pair(fsti,seci)!=father)
            {
                if(fsti>=0&&fsti<n&&seci>=0&&seci<m){
                    if(adudu[fsti][seci]==1){
                        q.push({fsti,seci});
                        a[{fsti,seci}]=a[father]+1;
                    }                    
                }
            }
        }
        father={fst,sec};
        q.pop();
    }

}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<string> inp;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin>>x;
        inp.push_back(x);
    }
    bfs({0,0},inp,n,m);
}

