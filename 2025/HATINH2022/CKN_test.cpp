#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(false), cin.tie(nullptr)

#define DVA delete_vector_algorithm
#define rtc raw_to_copy

#define supalg super_algorithm
#define con connect
#define cnc connect_copy

#define dv delete_value
#define isdv is_delete_value
#define pdv position_of_delete_value

#define DFS Depth_First_Search
#define CCC Count_Connected_Component

#define st start_value
#define ev end_value

using namespace std;
bool visited[1000];

struct data{
    int start;
    int end;
    bool operator == (const data & other) const{
        return (start == other.start) && (end == other.end);
    }
};

// Hàm xóa gía trị
vector<data> DVA(vector <data> raw, int dv){
    vector<data> rtc(raw.begin(), raw.end());
    copy(raw.begin(), raw.end(), rtc.begin());

    auto isdv = [dv](const data& lambda){
        return lambda.start == dv || lambda.end == dv;
    };
    
    auto pdv = remove_if(rtc.begin(), rtc.end(), isdv);
    rtc.erase(pdv, rtc.end());

    return rtc;
}

// void DFS(int n, int st, int ev){
//     visited[n] = true;
//     st = min(st, n);
//     ev = max(ev, n);

//     for(int i=st; i<=ev; i++){
//         if(!visited[i]) DFS(i, st, ev);
//     }
// }

// int CCC(int st, int ev){
//     int count = 0;
//     for(int i=st; i<=ev; i++){
//         if(!visited[i]){
//             count++;
//             DFS(i, st, ev);
//         }
//     }
//     return count;
// }

void supalg(vector <data> raw, int dv){
    vector <data> cnc = DVA(raw, dv);
    int st = INT_MAX, ev = INT_MIN;

    for(auto it=cnc.begin(); it!=cnc.end(); ++it){
        st = min(st, min(it->start, it->end));
        ev = max(ev, max(it->start, it->end));

        cout << it->start << " " << it->end << " " << cnc.size()<< " ";
        cout << st << " " << ev << "\n";
    }
    cout << CCC(st, ev) << "\n";
}

int main(){
    fast();
    int n, m;
    int fir, sec;
    vector <data> con;
    cin >> n >> m;

    for(int i=1; i<=m; i++){
        cin >> fir >> sec;
        con.push_back({fir, sec});
    }

    cout << "\n";    
    for(int i=1; i<=n; i++){
        cout << i << "\n";
        memset(visited, false, sizeof(visited));
        supalg(con, i);
        cout << "\n";
    }
}