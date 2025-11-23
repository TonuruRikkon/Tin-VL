#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Kích thước tối đa của đáy gạch (tối đa 10^6)
const int MAX_SIZE = 1000000;

// Cấu trúc lưu trữ thông tin về viên gạch
struct Brick {
    int id;          // Chỉ số ban đầu (1-based)
    int a;           // Đáy nhỏ
    int b;           // Đáy lớn
    long long h;     // Chiều cao
};

// Cấu trúc lưu trữ trạng thái Segment Tree Node
// max_h: Chiều cao tối đa, index: Chỉ số 1-based của viên gạch đạt được chiều cao đó
struct Node {
    long long max_h;
    int index;       
};

// Mảng cho Segment Tree. Kích thước khoảng 4 * MAX_SIZE
Node tree[4 * (MAX_SIZE + 1)];

// Mảng lưu trữ các viên gạch sau khi sắp xếp
vector<Brick> bricks;

// Mảng DP và Truy vết
vector<long long> dp;
// Prev[i]: Lưu chỉ số 0-based của viên gạch ngay dưới viên bricks[i]
vector<int> prev_brick; 

// --- Hàm so sánh (Sắp xếp) ---
// Sắp xếp theo a tăng dần, b giảm dần
bool compareBricks(const Brick& x, const Brick& y) {
    if (x.a != y.a) {
        return x.a < y.a;
    }
    return x.b > y.b;
}

// --- Các hàm cho Segment Tree ---

// Hợp nhất hai Node, chọn Node có max_h lớn hơn.
Node merge_nodes(const Node& left, const Node& right) {
    if (left.max_h > right.max_h) {
        return left;
    }
    if (right.max_h > left.max_h) {
        return right;
    }
    // Chiều cao bằng nhau, chọn bên trái (hoặc chỉ số nhỏ hơn) để có quy tắc nhất quán
    return left.index < right.index ? left : right;
}

// Cập nhật giá trị (DP, index) tại vị trí pos (giá trị a_i)
void update_max(int pos, long long new_h, int new_index, int node, int start, int end) {
    if (start == end) {
        // Chỉ cập nhật nếu giá trị mới LỚN HƠN giá trị hiện tại
        if (new_h > tree[node].max_h) {
            tree[node].max_h = new_h;
            tree[node].index = new_index;
        }
        return;
    }

    int mid = start + (end - start) / 2;
    if (pos <= mid) {
        update_max(pos, new_h, new_index, 2 * node, start, mid);
    } else {
        update_max(pos, new_h, new_index, 2 * node + 1, mid + 1, end);
    }

    // Hợp nhất lại kết quả từ các nút con
    tree[node] = merge_nodes(tree[2 * node], tree[2 * node + 1]);
}

// Truy vấn giá trị tối đa trong khoảng [L, R]
Node query_max(int L, int R, int node, int start, int end) {
    // Nếu phạm vi truy vấn nằm ngoài phạm vi node
    if (R < start || L > end) {
        return {0, 0}; // Chiều cao 0, Index 0 (sentinel)
    }
    
    // Nếu phạm vi node nằm hoàn toàn trong phạm vi truy vấn
    if (L <= start && end <= R) {
        return tree[node];
    }

    int mid = start + (end - start) / 2;
    Node p1 = query_max(L, R, 2 * node, start, mid);
    Node p2 = query_max(L, R, 2 * node + 1, mid + 1, end);
    
    return merge_nodes(p1, p2);
}

// --- Hàm chính giải quyết bài toán ---

void solve() {
    int n;
    if (!(cin >> n)) return;

    bricks.resize(n);
    dp.resize(n);
    prev_brick.resize(n, -1); 

    // Đọc dữ liệu
    for (int i = 0; i < n; ++i) {
        bricks[i].id = i + 1;
        cin >> bricks[i].a >> bricks[i].b >> bricks[i].h;
    }

    // Sắp xếp các viên gạch
    sort(bricks.begin(), bricks.end(), compareBricks);

    long long max_total_h = 0;
    int best_ending_index = -1; 

    // Lặp qua từng viên gạch đã sắp xếp
    for (int i = 0; i < n; ++i) {
        // 1. Truy vấn: Tìm chiều cao tối đa của tháp có đáy nhỏ >= bricks[i].b
        // Range truy vấn: [bricks[i].b, MAX_SIZE]
        int query_start = bricks[i].b;
        
        // Đảm bảo query_start không vượt quá phạm vi MAX_SIZE, nếu không sẽ truy vấn sai
        if (query_start > MAX_SIZE) { 
             query_start = MAX_SIZE; 
        }

        // Lấy kết quả (H_max và j* - index 1-based)
        Node result = query_max(query_start, MAX_SIZE, 1, 1, MAX_SIZE);
        
        // 2. Tính DP[i]
        long long H_max_below = result.max_h;
        int j_star = result.index; 

        dp[i] = bricks[i].h + H_max_below;
        
        // 3. Truy vết
        if (j_star != 0) {
            prev_brick[i] = j_star - 1; // Chuyển 1-based index (j*) về 0-based
        } else {
            prev_brick[i] = -1; // Viên i là viên dưới cùng
        }

        // 4. Cập nhật: Cập nhật DP[i] vào Segment Tree tại vị trí bricks[i].a
        if (bricks[i].a <= MAX_SIZE) {
            update_max(bricks[i].a, dp[i], i + 1, 1, 1, MAX_SIZE); // i+1 là index 1-based
        }
        
        // 5. Cập nhật kết quả cuối cùng
        if (dp[i] > max_total_h) {
            max_total_h = dp[i];
            best_ending_index = i;
        }
    }

    // --- Ghi kết quả ---
    
    // Dòng 1: Chiều cao tối đa
    cout << max_total_h << "\n";

    // Dòng 2: Truy vết và in ra các ID theo thứ tự từ dưới lên
    vector<int> tower_ids;
    int current_index = best_ending_index; 

    while (current_index != -1) {
        tower_ids.push_back(bricks[current_index].id);
        current_index = prev_brick[current_index];
    }

    // Đảo ngược để có thứ tự từ dưới lên
    reverse(tower_ids.begin(), tower_ids.end()); 
    
    for (size_t i = 0; i < tower_ids.size(); ++i) {
        cout << tower_ids[i] << (i == tower_ids.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

// Hàm main đọc/ghi file
int main() {
    // Tối ưu hóa I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Đổi hướng I/O từ file
    freopen("TOWER.INP", "r", stdin);
    freopen("TOWER.OUT", "w", stdout);

    solve();

    return 0;
}