#include <bits/stdc++.h>
using namespace std;

void Dijkstra(int in, int n,vector<vector<pair<int,int>>> inp, vector<int> dis)
{
    priority_queue<pair<int,int>> q; //Mảng hàng đợi 
    dis[in]=0; //set đường đi đến node đầu tiên là 0 (chưa đi)
    q.push({0,n}); //Đưa node đầu tiên vào hàng đợi để bắt đầu BFS
    while (!q.empty())
    {
        int d=q.top().first; //Lấy trọng số của u
        int u=q.top().second; //đỉnh đang xét
        q.pop();
        //d ở đây là d được đưa vào hàng đợi sớm nhất, đường đi ngắn nhất của u đã có thể được tính toán ở các bước trước nên có thể bỏ qua nếu d>dis[u]
        if(d>dis[u]) continue; 
        for(pair<int,int> x:inp[u]){
            int v=x.first; //cạnh kề của u
            int w= x.second; //trọng số giữa u và v
            if(dis[u]+w<dis[v]) // nếu đường đi từ u -> v ngắn hơn đường đi từ start-> trước đó
            {
                dis[v]=dis[u]+w; //Đắt lại giá trị đường đi cho v theo Dijkstra
                q.push({dis[v],v}); //Cho v vào hàng đợi để tiếp tục 
            }
        }
        
    }
    

}


int main()
{
    int n, k;
    cin>>n>>k;
    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < n-1; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;

        x--;y--; //giảm 1 đơn vị để khiến thứ tự các điểm bắt đầu từ 0(tránh lỗi khi triển khai thuật toán gốc)

        adj[x].push_back({z,y});
        adj[y].push_back({z,x});
    }
    vector<int> dis(n,INT_MAX); //mảng chiều dài đường đi
    vector<int> trecon(n); //Trọng sô của điểm i;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        trecon[i]=x;
    }
    
    

}