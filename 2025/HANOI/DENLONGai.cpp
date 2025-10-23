#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * Hàm tìm tổng tần suất của k giá trị phổ biến nhất (lớn nhất) trong cửa sổ.
 *
 * @param count_map Map lưu trữ tần suất của các giá trị (1-9).
 * @param k Số lượng giá trị khác nhau tối đa được phép.
 * @return Tổng tần suất của k giá trị lớn nhất.
 */
int get_sum_of_top_k(const map<int, int>& count_map, int k) {
    if (k <= 0) {
        return 0;
    }

    // Lấy tất cả các tần suất ra một vector
    vector<int> frequencies;
    for (const auto& pair : count_map) {
        if (pair.second > 0) {
            frequencies.push_back(pair.second);
        }
    }

    // Sắp xếp giảm dần để lấy các tần suất lớn nhất
    sort(frequencies.rbegin(), frequencies.rend());

    // Tính tổng k tần suất lớn nhất
    int sum = 0;
    int count = 0;
    for (int freq : frequencies) {
        if (count < k) {
            sum += freq;
            count++;
        } else {
            break;
        }
    }
    return sum;
}

/**
 * Hàm chính giải quyết bài toán.
 *
 * @param arr Dãy giá trị nguyên (1-9).
 * @param x Số lần thay đổi tối đa.
 * @param k Số lượng giá trị khác nhau tối đa sau khi thay đổi.
 * @return Chiều dài của dãy con dài nhất hợp lệ.
 */
int find_longest_subarray(const vector<int>& arr, int x, int k) {
    int n = arr.size();
    if (n == 0) return 0;

    // L: chỉ số bên trái của cửa sổ, R: chỉ số bên phải
    int L = 0;
    int max_length = 0;

    // Map để theo dõi tần suất của các giá trị (1 đến 9) trong cửa sổ [L, R]
    map<int, int> count;

    for (int R = 0; R < n; ++R) {
        // --- 1. Mở rộng cửa sổ (Tăng R) ---
        count[arr[R]]++;

        // --- 2. Thu hẹp cửa sổ (Tăng L) nếu cần ---
        // Điều kiện không hợp lệ: Số lần thay đổi cần thiết > x
        // Thay đổi cần thiết = Window_Length - Sum_of_Top_k
        while (true) {
            int window_length = R - L + 1;
            
            // Tìm tổng tần suất của k giá trị phổ biến nhất
            // Chi phí O(V log V) với V=9, rất nhanh
            int sum_of_top_k = get_sum_of_top_k(count, k); 
            
            int changes_needed = window_length - sum_of_top_k;

            if (changes_needed <= x) {
                // Cửa sổ hợp lệ, dừng thu hẹp
                break;
            }

            // Cửa sổ không hợp lệ, thu hẹp từ bên trái (Tăng L)
            count[arr[L]]--;
            
            // Nếu tần suất trở về 0, ta có thể xóa khỏi map (hoặc giữ lại, vì get_sum_of_top_k đã xử lý)
            if (count[arr[L]] == 0) {
                count.erase(arr[L]);
            }
            
            L++;
        }

        // --- 3. Cập nhật kết quả ---
        // Tại đây, cửa sổ [L, R] luôn hợp lệ
        max_length = max(max_length, R - L + 1);
    }

    return max_length;
}

// --- Ví dụ Sử dụng ---
int main() {

    int n;
    cin>>n;
    // Dãy giá trị: Giả sử chỉ có giá trị từ 1 đến 9
    vector<int> arr;
    int x_changes; // Được phép thay đổi tối đa 2 giá trị
    int k_distinct; //  Cần tối đa 2 giá trị khác nhau
    cin>>k_distinct>>x_changes;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    
    // Phân tích: 
    // Dãy con {3, 3, 3, 4, 4, 4, 4} (dài 7)
    // - Tần suất: 3:3, 4:4. k=2, Top-2 Sum = 3+4=7. Changes = 7 - 7 = 0. (0 <= 2). Hợp lệ.
    // Dãy con {3, 3, 3, 4, 4, 4, 4, 5, 5} (dài 9)
    // - Tần suất: 3:3, 4:4, 5:2. k=2, Top-2 Sum = 4+3=7. Changes = 9 - 7 = 2. (2 <= 2). Hợp lệ.
    
    // Thử dãy con {1, 2, 2, 3, 3, 3, 4, 4, 4, 4} (dài 10)
    // - Tần suất: 1:1, 2:2, 3:3, 4:4. k=2, Top-2 Sum = 4+3=7. Changes = 10 - 7 = 3. (3 > 2). KHÔNG HỢP LỆ.

    int result = find_longest_subarray(arr, x_changes, k_distinct);

    cout << "Dãy ban đầu: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
    cout << "Số lần thay đổi tối đa (x): " << x_changes << endl;
    cout << "Số giá trị khác nhau tối đa (k): " << k_distinct << endl;
    cout << "Chiều dài dãy con dài nhất: " << result << endl; // Kết quả phải là 9

    return 0;
}