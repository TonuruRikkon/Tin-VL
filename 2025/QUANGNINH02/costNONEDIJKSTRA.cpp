#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Định nghĩa alias cho cặp {đỉnh_kề, trọng_số_cạnh}
typedef pair<int, int> Edge;
// Định nghĩa kiểu dữ liệu cho chi phí (rất lớn)
typedef long long ll;

// Biến toàn cục để lưu trữ dữ liệu đồ thị và tiền xử lý
vector<vector<Edge>> adj; // Danh sách kề: adj[u] = {{v1, w1}, {v2, w2}, ...}
vector<ll> P;             // Trọng số điểm (Point weight) của mỗi đỉnh. P[i]
vector<ll> S;             // Tổng trọng số điểm (Sum weight) của cây con gốc i. S[i]

// --- Bước 1: Tiền xử lý (Tính tổng trọng số điểm của các cây con) ---
void calculate_subtree_sum(int u, int parent) {
    S[u] = P[u]; // Bắt đầu với trọng số của chính đỉnh u
    for (const auto& edge : adj[u]) {
        int v = edge.first;
        if (v != parent) {
            calculate_subtree_sum(v, u);
            S[u] += S[v]; // Cộng dồn tổng trọng số từ các cây con
        }
    }
}

// --- Bước 2: DFS Giải quyết Bài toán (Tính chi phí) ---
// total_remaining_weight: Tổng trọng số điểm của tất cả các đỉnh CHƯA được duyệt (bao gồm u và tất cả các cây con)
ll solve_traversal_cost(int u, int parent, ll total_remaining_weight, bool is_minimal) {
    ll current_cost = 0;
    
    // 1. Lấy danh sách các nhánh con
    vector<Edge> children_edges;
    for (const auto& edge : adj[u]) {
        int v = edge.first;
        if (v != parent) {
            children_edges.push_back(edge);
        }
    }
    
    // 2. Sắp xếp các nhánh con theo nguyên tắc tham lam
    // A. Chi phí TỐI THIỂU: Ưu tiên duyệt nhánh con có S[v] LỚN HƠN 
    // B. Chi phí TỐI ĐA: Ưu tiên duyệt nhánh con có S[v] NHỎ HƠN
    sort(children_edges.begin(), children_edges.end(), 
         [&](const Edge& a, const Edge& b) {
             if (is_minimal) {
                 return S[a.first] > S[b.first]; // Tối thiểu: S[v] giảm dần (lớn trước)
             } else {
                 return S[a.first] < S[b.first]; // Tối đa: S[v] tăng dần (nhỏ trước)
             }
         });

    // 3. Duyệt và tính chi phí
    for (const auto& edge : children_edges) {
        int v = edge.first;
        int weight = edge.second; // Trọng số cạnh L_uv
        
        // Chi phí cho cạnh (u, v): L_uv * total_remaining_weight 
        current_cost += (ll)weight * total_remaining_weight;
        
        // Tổng trọng số còn lại trước khi đi vào cây con v
        ll next_remaining_weight = total_remaining_weight - S[v]; 
        
        // Tính chi phí trong nhánh con v (và gán kết quả đệ quy)
        current_cost += solve_traversal_cost(v, u, next_remaining_weight, is_minimal);
        
        // Cập nhật total_remaining_weight sau khi đã hoàn thành duyệt cây con v
        total_remaining_weight = next_remaining_weight;
    }
    
    return current_cost;
}

int main() {
    // Tăng tốc độ I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K; 
    cin >> N >> K; // Nhập N (số đỉnh) và K (tham số không dùng trong bài toán này)

    // Kích thước N+1 vì đỉnh đếm từ 1
    adj.resize(N + 1);
    P.resize(N + 1);
    S.resize(N + 1);

    // 1. NHẬP TRỌNG SỐ ĐIỂM P[i] (Thay đổi so với code trước)
    cout << "Nhập trọng số điểm cho " << N << " đỉnh (P[1] đến P[" << N << "]):\n";
    for (int i = 1; i <= N; ++i) {
        cin >> P[i]; 
    }
    
    // 2. Nhập các cạnh (Đồ thị cây có N-1 cạnh)
    cout << "Nhập " << N - 1 << " cạnh (u v w):\n";
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // Lưu ý: u, v là chỉ số từ 1
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Đồ thị vô hướng
    }

    // Chọn đỉnh gốc để bắt đầu duyệt (Thường là đỉnh 1)
    int root = 1; 
    
    // 3. Thực hiện tiền xử lý
    calculate_subtree_sum(root, 0); 

    // Tổng trọng số điểm ban đầu là tổng trọng số của toàn bộ cây
    ll initial_total_weight = S[root]; 
    
    // 4. Tính Chi phí Tối thiểu (Tiết kiệm nhất)
    // total_remaining_weight ban đầu = Tổng tất cả các điểm trừ đi điểm gốc (vì nó đã được "thăm" ngay khi bắt đầu)
    ll min_cost = solve_traversal_cost(root, 0, initial_total_weight - P[root], true); 

    // 5. Tính Chi phí Tối đa (Tốn kém nhất)
    ll max_cost = solve_traversal_cost(root, 0, initial_total_weight - P[root], false);

    // 6. Kết quả cuối cùng
    cout << "\nKết quả:\n";
    cout << "Chi phí duyệt TIẾT KIỆM NHẤT: " << min_cost << endl;
    cout << "Chi phí duyệt TỐN KÉM NHẤT: " << max_cost << endl;

    return 0;
}