#include <bits/stdc++.h>
using namespace std;


/* 
Tính tổng chi phí từ tất cả các đỉnh về s.(lưu ý rằng trong khuôn khổ bài này thì s=0)
Ta tối ưu hóa chi phí bằng cách thả học sinh tại các điểm giao (do không chở học sinh thì không mất phí).
Sau đó tập hợp tất cả học sinh về điểm giao rồi mới chuyển về s.

Việc này được thực hiện bằng cách duyệt xâu (Deep-First search) đồ thị cây
đến ngọn sau đó quay lui và mang theo trọng số 
"count[s]=w[s]" -> count[s(điểm giao được đã quay lui)]+=count[v(trọng số được mang về từ ngọn)].
Chiều đi của học sinh: Các ngọn cây -> nút giao -> gốc s.
*/
void DFSI(int s,/*Điểm bắt đầu(start)*/
    int cha,/*Cha (parent) của s*/
    vector<vector<pair<int,int>>> &inp,/*cạnh liền kề*/
    vector<int> &w/*trọng số gốc*/,
    vector<long long> &count /*Trọng số các đỉnh đang mang theo*/,
    vector<long long> &path/*Độ dài đường đi từ điểm bắt đầu nến i*/)
{
    count[s]=w[s]; //set các trọng số của điểm là chính nó (vì khi bắt đầu hoặc đi qua điểm thì cũng mang theo trọng số)
    for(pair<int,int> x:inp[s]) //duyệt các đỉnh liền kề s
    {
        if(x.first==cha) continue; //Nếu gặp điểm cha(điểm xuất phát đến s) thì bỏ qua
        int v=x.first; //Đỉnh được xét tiếp theo
        int c=x.second; //Trọng số của điểm đang xét
        DFSI(v,s,inp,w,count,path);

        //Bắt đầu quay lui

        count[s]+=count[v]; //Cập nhật trọng số đang mang tại s
        path[0]+=1LL*count[v]*c; //cập nhật đường đi từ v->s(0)

    }
}


/* Duyệt xâu lại cây
Lần này thay vì tính tổng chi phí từ tất cả các ngọn đến s,
chúng ta tính chi phí từ tất cả các ngọn đến v.

Điều này được thực hiện bằng cách tính tổng các nhánh của v.
các nhánh đến v và không đi đến gốc s vốn đã được tính toán và lưu
trữ trướctrong vector path.



*/
void DFSII(int s,/*Điểm bắt đầu(start)*/
    int cha,/*Cha (parent) của s*/
    long long tol, /* Tổng số trọng số điểm */
    vector<vector<pair<int,int>>> &inp,/*cạnh liền kề*/
    vector<int> &w,/*trọng số gốc*/
    vector<long long> &count,/*Trọng số các đỉnh đang mang theo*/
    vector<long long> &path /*Độ dài đường đi từ điểm bắt đầu nến i*/)
{
    for(pair<int,int> x:inp[s]){
        if(x.first==cha) continue;
        int v=x.first;//đỉnh đang xét
        int c=x.second;//Trọng số của đỉnh đang xét

        path[v]=path[s] //đặt chi phí đường đi đến v là đường đi đến s
        -(1LL*count[v]*c) //trừ chi phí đi đoạn từ v->s
        +(1LL*(tol-count[v])*c);//cộng lại chi từ s->v
        DFSII(v,s,tol,inp,w,count,path); //Tiếp tục duyệt xâu(DFS)
    }
}




int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<pair<int,int>>> inp(n);
    vector<int> trsodiem(n);
    for (int i = 0; i < n-1; i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        u--;
        v--;
        inp[u].push_back({v,c});
        inp[v].push_back({u,c});
    }
    long long tol=0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        trsodiem[i]=x;
        tol+=x;
    }

    vector<long long> count(n);
    vector<long long> d(n);

    DFSI(0,-1,inp,trsodiem,count,d);
    DFSII(0,-1,tol,inp,trsodiem,count,d);

    long long minn = LLONG_MAX, maxx = LLONG_MIN;
    for (int i=0; i<n; ++i) {
        minn = min(minn, d[i]);
        maxx = max(maxx, d[i]);
    }

    cout<<minn<<' '<<maxx<<' ';
    if(k>=minn){
        if(k<=maxx){
            cout<<"YES";
        }
        else{
            cout<<"GOOD";
        }
    }
    else{
        cout<<"NO";
    }
    return 0;    
}