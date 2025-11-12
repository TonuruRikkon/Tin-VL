#include <bits/stdc++.h>
using namespace std;

#define TPLT Thanh_Phan_Lien_Thong
//Khôi = khi loại bỏ 1 điểm trong khối không làm tăng lượng thành phần liên thông

int n=int(1e6),m;
vector<vector<int>> adj(n+1); //Lưu cạnh liền kề

vector<int> num(n+1,0); //Lưu thời điểm đầu tiên node được thăm.
vector<int> low(n+1,0); //Lưu thời điểm thấp nhất mà đỉnh có thể được thăm.
vector<int> parent(n+1,0); //Cha của node
vector<int> ans(n+1,0);


int TPLTG=0; //Số thành phần liên thông gốc (chưa bị xóa node)
int time_=0; //thời gian

vector<bool> visited(n+1,false);

//DFS cơ bản được dùng để tìm số lượng TPLT gốc
void dfs(int u){
    visited[u]=true;
    for(int v:adj[u]){
        if(visited[v]==false){
            dfs(v);
        }
    }
}

/* 
    Lưu ý rằng thời điểm nhỏ nhất chỉ là cách nói để quy định các mối quan hệ với khối(cùng thời điểm thì cùng khối)
*/

void tarjan(int u,bool root){
    num[u]=low[u]= ++time_;// ++time=time+1; set thời điểm đầu tiên và thời điểm nhỏ nhất là time+1
    int ConCNT=0;//Lượng khối liền kề u
    int Canh=0; //Lượng cành(TPLT) được tạo ra khi loại bỏ u
    //Duyệt qua các điểm liền kề của u
    for(int v:adj[u]){
        //Kiểm tra xem u đã được thăm chưa
        if(!num[v]){
            parent[v]=u;
            tarjan(v,false); //Tiếp tục duyệt xâu (deep-first search)
            low[u]=min(low[u],low[v]); //Lấy thời điểm nhỏ nhất để đến v
            
            /* 
                Thời điểm nhỏ nhất để đến v lớn hơn thời điểm đầu tiên đến u
                Nghĩa là đỉnh v không thể đến được các cạnh cha của u
                Hoặc nói đơn giản là khi xóa u, khối mà v thuộc về tách
                ra làm một TPLT riêng
            */
            
            if(low[v]>=num[u]){
                ConCNT++;
                if(!root){
                    Canh++; //Với mỗi đỉnh không phải gốc, mỗi khối là một cành riêng
                }
            }
        }
        //Nếu cạnh v đã được thăm nhưng v không phải cha của u, nghĩa là v thuộc một cảnh vòng(nếu loại bỏ v thì các cạnh vòng dù có bao nhiêu điểm liền kề với u thì đều chỉ tính là 1 TPLT)
        else if(v!=parent[u]){
            low[u]=min(low[v],low[u]);
        }
    }
    //Nếu là gốc thì lượng cành tương đương lượng khối kết nối với gốc -1 
    if(root){
        Canh=max(0,ConCNT-1);
    }
    ans[u]=TPLTG+Canh; //Số Thành phần liên thông được tạo ra tương đương với số TPLTGốc + Số TPLT được tạo ra khi loại bỏ u
}

int main()
{
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if(visited[i]==false) {
            TPLTG++;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if(num[i]==0){
            tarjan(i,true);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<ans[i]<<'\n';
    }
    
    
    
}