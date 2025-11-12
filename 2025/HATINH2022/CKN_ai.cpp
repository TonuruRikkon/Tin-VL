#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Hằng số cho kích thước tối đa của đồ thị
const int MAXN = 100005;

// Danh sách kề cho đồ thị
vector<int> adj[MAXN];

// Các mảng theo dõi cho thuật toán Khớp (Articulation Points)
int disc[MAXN];          // Thời gian khám phá (Discovery time)
int low[MAXN];           // Giá trị low-link
bool visited[MAXN];      // Đã thăm (dùng cho DFS AP)
int timer;               // Bộ đếm thời gian
int N, M;                // Số đỉnh, số cạnh

// Mảng lưu kết quả: Số thành phần liên thông mới khi xóa đỉnh i
// results[i] = số TPLT mới khi xóa đỉnh i
int results[MAXN];

// Số lượng thành phần liên thông ban đầu (TPLT_gốc)
int initial_cc_count;


/**
 * @brief Hàm DFS để tìm khớp và tính số TPLT bị tách ra.
 * * @param u Đỉnh hiện tại
 * @param p Đỉnh cha
 * @param root_of_cc Đỉnh gốc của thành phần liên thông hiện tại
 */
void dfs_ap(int u, int p, int root_of_cc) {
    // Đánh dấu u là đã thăm (trong ngữ cảnh của AP)
    visited[u] = true;
    
    // Khởi tạo thời gian khám phá và low-link
    disc[u] = low[u] = ++timer;

    int children_in_dfs_tree = 0; // Đếm số cây con trong cây DFS
    int separation_count = 0;     // Số lượng thành phần mới bị tách ra (chỉ áp dụng cho u không là gốc)

    for (int v : adj[u]) {
        if (v == p) continue; // Bỏ qua cạnh đến cha

        if (visited[v]) {
            // Cạnh ngược (Back-Edge): Cập nhật low-link của u
            low[u] = min(low[u], disc[v]);
        } else {
            // Cạnh cây (Tree-Edge)
            children_in_dfs_tree++;
            dfs_ap(v, u, root_of_cc);

            // Cập nhật low-link của u sau khi thăm v
            low[u] = min(low[u], low[v]);

            // Quy tắc xác định Khớp (Articulation Point) cho đỉnh không phải gốc
            // Nếu low[v] >= disc[u], v và cây con của nó bị tách rời khỏi phần còn lại
            if (p != 0 && low[v] >= disc[u]) {
                separation_count++;
            }
        }
    }

    // --- Cập nhật Kết quả ---

    if (u == root_of_cc) {
        // Trường hợp 1: Gốc của TPLT
        if (children_in_dfs_tree > 1) {
            // Gốc là Khớp: TPLT_mới = (TPLT_gốc - 1) + children_in_dfs_tree
            results[u] = initial_cc_count - 1 + children_in_dfs_tree;
        } else {
            // Gốc KHÔNG là Khớp: TPLT_mới = TPLT_gốc
            results[u] = initial_cc_count;
        }
    } else {
        // Trường hợp 2: Đỉnh không phải là gốc
        if (separation_count > 0) {
            // Phi-gốc là Khớp: TPLT_mới = TPLT_gốc + separation_count
            // (1 phần chứa parent(u) + separation_count phần bị cắt)
            results[u] = initial_cc_count + separation_count;
        } else {
            // Phi-gốc KHÔNG là Khớp: TPLT_mới = TPLT_gốc
            // (TPLT_gốc - 1 component của u + 1 component còn lại)
            results[u] = initial_cc_count;
        }
    }
}


/**
 * @brief Hàm tìm số TPLT ban đầu của đồ thị.
 */
void find_initial_cc() {
    // Dùng mảng visited mới (temp_visited) để không ảnh hưởng đến mảng chính cho AP
    bool temp_visited[MAXN];
    fill(temp_visited + 1, temp_visited + N + 1, false);
    initial_cc_count = 0;

    for (int i = 1; i <= N; ++i) {
        if (!temp_visited[i]) {
            initial_cc_count++;
            
            // Dùng DFS để đánh dấu tất cả các đỉnh trong TPLT này
            vector<int> stack;
            stack.push_back(i);
            temp_visited[i] = true;

            while (!stack.empty()) {
                int u = stack.back();
                stack.pop_back();

                for (int v : adj[u]) {
                    if (!temp_visited[v]) {
                        temp_visited[v] = true;
                        stack.push_back(v);
                    }
                }
            }
        }
    }
}


/**
 * @brief Hàm giải quyết bài toán chính.
 */
void solve() {
    // Tối ưu I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. Nhập liệu
    if (!(cin >> N >> M)) return;

    for (int i = 0; i < M; ++i) {
        int u, v;
        if (!(cin >> u >> v)) return;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 2. Tìm số TPLT ban đầu
    find_initial_cc();

    // 3. Khởi tạo kết quả cơ sở
    // Khi xóa một đỉnh, TPLT mà nó thuộc về sẽ bị xóa khỏi tổng số TPLT_gốc.
    // Trường hợp cô lập: TPLT_gốc giảm 1.
    for (int i = 1; i <= N; ++i) {
        results[i] = initial_cc_count - 1; 
    }

    // 4. Phân tích Khớp (Articulation Points) cho các TPLT lớn hơn 1
    fill(visited + 1, visited + N + 1, false);

    for (int i = 1; i <= N; ++i) {
        // Chỉ chạy nếu chưa được thăm VÀ không phải đỉnh cô lập (adj[i].size() > 0)
        if (!visited[i] && adj[i].size() > 0) { 
            timer = 0;
            // Gọi dfs_ap. i là gốc của TPLT.
            dfs_ap(i, 0, i); 
        }
    }
    
    // 5. In kết quả
    for (int i = 1; i <= N; ++i) {
        cout << results[i] << (i == N ? "" : "\n");
    }
}


// Hàm main chính
int main() {
    solve();
    return 0;
}