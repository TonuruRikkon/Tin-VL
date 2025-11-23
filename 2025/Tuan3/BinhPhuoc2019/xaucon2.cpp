#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Hàm đếm số dãy con có tổng bằng k
long long countSubarraysWithSumK(int k, const string& str) {
    // Chuyển chuỗi ký tự '0'/'1'/'2'... thành vector các số nguyên
    vector<int> nums;
    for (char c : str) {
        nums.push_back(c - '0');
    }

    // 1. Khởi tạo
    long long prefix_sum = 0; // Tổng tiền tố hiện tại
    long long count = 0;      // Kết quả cuối cùng
    
    // map<tổng_tiền_tố, số_lần_xuất_hiện>
    // Bắt đầu với {0: 1} để xử lý các dãy con bắt đầu từ chỉ mục 0
    map<long long, int> prefix_sum_freq;
    prefix_sum_freq[0] = 1; 

    // 2. Duyệt qua mảng
    for (int num : nums) {
        // Cập nhật tổng tiền tố
        prefix_sum += num;

        // 3. Tính toán kết quả
        // Ta cần tìm một prefix_sum_trước_đó sao cho:
        // prefix_sum - prefix_sum_trước_đó = k
        // Tức là: prefix_sum_trước_đó = prefix_sum - k
        long long target_sum = prefix_sum - k;

        // Nếu tổng mục tiêu này đã từng xuất hiện, cộng số lần xuất hiện đó vào kết quả
        if (prefix_sum_freq.count(target_sum)) {
            count += prefix_sum_freq[target_sum];
        }

        // 4. Cập nhật tần suất cho tổng tiền tố hiện tại
        prefix_sum_freq[prefix_sum]++;
    }

    return count;
}

int main() {
    // Đọc đầu vào
    int k;
    cout << "Nhap gia tri K (tong muc tieu): ";
    cin >> k;
    string str;
    cout << "Nhap chuoi so: ";
    cin >> str;

    // Tính và in kết quả
    long long result = countSubarraysWithSumK(k, str);
    cout << "\n====================================\n";
    cout << "So luong day con co tong bang " << k << " la: " << result << endl;
    cout << "====================================\n";

    // Ví dụ về lỗi của code cũ: k=2, str="1101" -> code cũ ra 2, code này ra 3
    /*
    cout << "Test case k=2, str=\"1101\": " 
         << countSubarraysWithSumK(2, "1101") << endl;
    */
    
    return 0;
}