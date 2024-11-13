#include<bits/stdc++.h>
using namespace std;

#define MOD 100000007
set<pair<int,int>> visited;
int Ox[4]={1,0,-1,0},Oy[4]={0,-1,0,1};

void bfs(vector<string>& inp,int n,int m)
{
    queue<pair<int,int>> q;
    q.push({0,0});
    vector<vector<int>> steps(n,vector<int>(m,-1));
    vector<vector<int>> ways(n,vector<int> (m,0));

    steps[0][0]=0;
    ways[0][0]=1;

    while (q.empty()==false)
    {
        int fst=q.front().first,sec=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int fsti=fst+Oy[i],seci=sec+Ox[i];
            if(fsti>=0 && fsti<n && seci>=0 && seci<m && inp[fsti][seci]== '1')
            {
                if(steps[fsti][seci]==-1){
                    q.push({fsti,seci});
                    steps[fsti][seci]=steps[fst][sec]+1;
                    ways[fsti][seci]=ways[fst][sec];       
                }
                else if(steps[fsti][seci]==steps[fst][sec]+1){
                    ways[fsti][seci]=(ways[fsti][seci]+ways[fst][sec])% MOD;
                }
            }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<steps[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<ways[n-1][m-1]<<endl<<steps[n-1][m-1];
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
    bfs(inp,n,m);
}

