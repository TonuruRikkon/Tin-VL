#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// Hằng số cho giá trị không thể đạt được
const long long INF = -1e18; 

/**
 * @brief Hàm giải quyết bài toán tối đa hóa tổng bình phương độ dài các đoạn con
 * với tối đa M lần đổi ký tự bất kỳ.
 * @param n Độ dài chuỗi inp.
 * @param m Số lần đổi tối đa.
 * @param inp Chuỗi đầu vào.
 * @return Giá trị tol lớn nhất có thể.
 */
long long solve_max_square_sum(int n, int m, const string& inp) {
    // DP[i][j]: Giá trị tol lớn nhất đạt được trong tiền tố inp[0...i-1] 
    //           sử dụng chính xác j lần đổi.
    // Kích thước mảng: (n + 1) x (m + 1)
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INF));

    // Khởi tạo: Tiền tố rỗng (độ dài 0), 0 lần đổi, tol = 0.
    dp[0][0] = 0;

    // Duyệt qua độ dài tiền tố i (chỉ số cuối + 1)
    for (int i = 1; i <= n; ++i) {
        // Duyệt qua số lần đổi đã dùng j
        for (int j = 0; j <= m; ++j) {
            
            // Duyệt qua vị trí bắt đầu k của substring mới: inp[k...i-1]
            // k là vị trí ngay sau đoạn con trước, hoặc k=0 nếu đây là đoạn con đầu tiên
            for (int k = 0; k < i; ++k) {
                
                // Độ dài của substring mới: inp[k...i-1]
                int len = i - k;
                
                // Duyệt qua ký tự mục tiêu 'c' mà ta muốn substring inp[k...i-1] trở thành
                // Giả định chuỗi chỉ chứa chữ cái tiếng Anh in thường ('a' - 'z')
                for (char target_char = 'a'; target_char <= 'z'; ++target_char) {
                    
                    int cost = 0;
                    // Tính số lần đổi cần thiết để biến inp[k...i-1] thành chuỗi target_char
                    for (int l = k; l < i; ++l) {
                        if (inp[l] != target_char) {
                            cost++;
                        }
                    }

                    // Nếu số lần đổi (cost) không vượt quá số lần đổi còn lại (j)
                    if (j >= cost) {
                        // Trạng thái trước đó có thể đạt được và có thể kết hợp với đoạn con mới này
                        if (dp[k][j - cost] != INF) {
                            // Cập nhật DP: giá trị trước + bình phương độ dài đoạn con mới
                            long long new_val = dp[k][j - cost] + (long long)len * len;
                            dp[i][j] = max(dp[i][j], new_val);
                        }
                    }
                }
            }
        }
    }

    // Kết quả là giá trị lớn nhất trong hàng cuối cùng (toàn bộ chuỗi đã được xử lý)
    long long max_tol = 0;
    for (int j = 0; j <= m; ++j) {
        max_tol = max(max_tol, dp[n][j]);
    }

    return max_tol;
}

int main() {
    // Tăng tốc độ I/O (Tùy chọn)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    string inp, inp2; 
    cin >> inp; // Chuỗi inp
    // Đọc chuỗi inp2 theo yêu cầu đề bài, nhưng nó không được sử dụng 
    // trong giả định giải quyết này (đổi thành ký tự bất kỳ).
    // Nếu inp2 có vai trò khác, cần sửa đổi logic DP.
    if (m > 0) { // Đọc inp2 nếu m > 0 (theo logic code của bạn)
        cin >> inp2;
    }
    
    // Xử lý trường hợp m = 0 như đã định nghĩa ban đầu của bạn (tính tol bình thường)
    if (m == 0) {
        // Tính tổng bình phương độ dài các đoạn liên tiếp giống nhau
        long long max_tol = 0;
        if (n > 0) {
            int temp = 1;
            for (int i = 1; i < n; i++) {
                if (inp[i] == inp[i-1]) {
                    temp++;
                } else {
                    max_tol += (long long)temp * temp;
                    temp = 1;
                }
            }
            // Cộng đoạn cuối cùng
            max_tol += (long long)temp * temp;
        }
        cout << max_tol << endl;
        return 0;
    }
    
    // Trường hợp m > 0 (áp dụng Quy hoạch động)
    long long result = solve_max_square_sum(n, m, inp);
    cout << result << endl;

    return 0;
}