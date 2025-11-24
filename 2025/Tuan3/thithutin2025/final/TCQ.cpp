#include<bits/stdc++.h>
using namespace std;

// --- Khai báo hằng số và cấu trúc dữ liệu toàn cục ---
const int MAXN = 100005;
int N, Q;
int C[MAXN]; // Màu của đỉnh i (1-indexed)
vector<int> adj[MAXN]; // Danh sách kề

// Thông tin về DFS Order
int timer = 0;
int tin[MAXN]; // Thời điểm vào (vị trí trong mảng DFS_Order)
int tout[MAXN]; // Thời điểm ra (vị trí cuối cùng của cây con u trong DFS_Order)
int DFS_Order[MAXN]; // Mảng đỉnh theo thứ tự DFS (1-indexed)

// Cấu trúc cho truy vấn
struct Query {
    int L, R, K; // [L, R] là đoạn trên DFS_Order, K là tần suất tối thiểu
    int id; // ID của truy vấn
};

Query queries[MAXN];
int ans[MAXN];

// Kích thước khối cho Mo's Algorithm
int block_size;

// Cấu trúc dữ liệu Mo's
int cnt[MAXN]; // cnt[c]: số lần màu c xuất hiện trong đoạn [L, R] hiện tại
int freq[MAXN]; // freq[f]: số lượng màu xuất hiện đúng f lần
int current_ans = 0; // Biến này chỉ được dùng để duy trì freq, kết quả tính cuối cùng
                     // sẽ là sum(freq[f]) từ K đến N, không phải biến này.

// --- Hàm DFS (Tiền xử lý) ---
// Chuyển cây con thành đoạn trên mảng DFS_Order
void dfs(int u, int p) {
    timer++;
    tin[u] = timer;
    DFS_Order[timer] = u; // Đặt đỉnh u vào mảng DFS_Order

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }

    tout[u] = timer; // tout[u] là vị trí cuối cùng của cây con u trong DFS_Order
}

// --- Hàm so sánh cho Mo's Algorithm ---
// Phân khối theo L, nếu cùng khối, sắp xếp theo R
bool compareQueries(const Query& a, const Query& b) {
    int block_a = a.L / block_size;
    int block_b = b.L / block_size;
    
    if (block_a != block_b) {
        return block_a < block_b;
    }
    // Tối ưu chẵn lẻ (Snake order)
    if (block_a % 2 == 0) {
        return a.R < b.R;
    } else {
        return a.R > b.R;
    }
}

// --- Hàm cập nhật trạng thái (Thêm/Bớt đỉnh) ---

// Thêm đỉnh tại vị trí idx của DFS_Order
void add(int idx) {
    int u = DFS_Order[idx];
    int color = C[u];
    
    // Bớt màu này khỏi tần suất cũ
    if (cnt[color] > 0) {
        freq[cnt[color]]--;
    }
    
    // Tăng tần suất
    cnt[color]++;
    
    // Thêm màu này vào tần suất mới
    freq[cnt[color]]++;
}

// Loại bỏ đỉnh tại vị trí idx của DFS_Order
void remove(int idx) {
    int u = DFS_Order[idx];
    int color = C[u];

    // Bớt màu này khỏi tần suất cũ
    freq[cnt[color]]--;
    
    // Giảm tần suất
    cnt[color]--;
    
    // Thêm màu này vào tần suất mới (nếu cnt[color] > 0)
    if (cnt[color] > 0) {
        freq[cnt[color]]++;
    }
}

// --- Hàm xử lý chính ---
void solve() {
    // 1. Đọc input
    int u, v, k;
    if (!(cin >> N >> Q)) return;

    for (int i = 1; i <= N; ++i) {
        cin >> C[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 2. Tiền xử lý (DFS Order)
    // Gốc là đỉnh 1
    dfs(1, 0);

    // 3. Chuẩn bị truy vấn
    for (int i = 0; i < Q; ++i) {
        cin >> u >> k;
        queries[i].L = tin[u];
        queries[i].R = tout[u];
        queries[i].K = k;
        queries[i].id = i;
    }

    // 4. Khởi tạo Mo's Algorithm
    block_size = (int)sqrt(N);
    if (block_size == 0) block_size = 1;

    // 5. Sắp xếp truy vấn
    sort(queries, queries + Q, compareQueries);

    // 6. Xử lý truy vấn
    int currentL = 1;
    int currentR = 0; // Bắt đầu từ đoạn rỗng

    for (int i = 0; i < Q; ++i) {
        const auto& q = queries[i];
        int targetL = q.L;
        int targetR = q.R;
        int targetK = q.K;

        // Mở rộng/Thu hẹp R
        while (currentR < targetR) {
            currentR++;
            add(currentR);
        }
        while (currentR > targetR) {
            remove(currentR);
            currentR--;
        }

        // Mở rộng/Thu hẹp L
        while (currentL > targetL) {
            currentL--;
            add(currentL);
        }
        while (currentL < targetL) {
            remove(currentL);
            currentL++;
        }

        // Tính kết quả cho truy vấn hiện tại
        // Kết quả là số lượng màu c mà cnt[c] >= targetK
        int result = 0;
        // Ta chỉ cần tính tổng từ targetK đến N
        for (int f = targetK; f <= N; ++f) {
            result += freq[f];
        }

        ans[q.id] = result;
    }

    // 7. In kết quả
    for (int i = 0; i < Q; ++i) {
        cout << ans[i] << "\n";
    }
}

// --- Hàm main (đọc/ghi file) ---
int main() {
    // Tối ưu tốc độ I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Đọc từ TCQ.INP và ghi ra TCQ.OUT
    // (Nếu không dùng lệnh freopen, code sẽ đọc từ stdin và ghi ra stdout)
    freopen("TCQ.INP", "r", stdin);
    freopen("TCQ.OUT", "w", stdout);

    solve();

    return 0;
}