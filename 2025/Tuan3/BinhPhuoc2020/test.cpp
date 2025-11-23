#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

const int MAX_N = 1000000; 

// tau[n]: Số lượng ước dương của n (tau(n))
std::vector<long long> tau(MAX_N + 1); 
// exp_p[n]: Số lượng ước của luỹ thừa nguyên tố nhỏ nhất của n (a+1)
std::vector<int> exp_p(MAX_N + 1); 
// primes: Danh sách các số nguyên tố tìm được
std::vector<int> primes; 

// Hàm Sàng Ước Tối Ưu (Không thay đổi)
void optimized_sieve_for_divisors() {
    tau[1] = 1;      
    exp_p[1] = 1;    
    
    for (int n = 2; n <= MAX_N; ++n) {
        if (exp_p[n] == 0) { // n là số nguyên tố
            primes.push_back(n);
            tau[n] = 2;      
            exp_p[n] = 2;    
        }
        
        for (int p : primes) {
            if ((long long)n * p > MAX_N) break;
            
            int m = n * p;
            
            if (n % p == 0) { // Trường hợp 2: n chia hết cho p
                exp_p[m] = exp_p[n] + 1; 
                tau[m] = tau[n] / exp_p[n] * exp_p[m];
                break; 
            } else { // Trường hợp 3: n không chia hết cho p
                exp_p[m] = 2;
                tau[m] = 2 * tau[n]; 
            }
        }
    }
}

// Hàm đếm số lượng ước nguyên dương cho một số
long long count_positive_divisors(int n) {
    if (n == 0) return 0; // Số 0 không có ước dương (hoặc vô hạn, tuỳ định nghĩa, thường là 0)
    int abs_n = std::abs(n);
    if (abs_n > MAX_N) {
        // Cần dùng phương pháp phân tích thừa số nguyên tố thông thường 
        // cho các số lớn hơn MAX_N
        return -1; // Báo hiệu ngoài phạm vi sàng
    }
    
    // TRẢ VỀ TRỰC TIẾP tau[abs_n]
    return tau[abs_n]; 
}

// -----------------------------------------------------------------------------

int main() {
    // Chạy sàng 1 lần duy nhất
    optimized_sieve_for_divisors(); 
    
    // Dãy số ví dụ:
    std::vector<int> numbers = {9, 12, 100, -18, 999999};

    std::cout << "Ket qua dem SO LUONG UOC NGUYEN DUONG (Sieve Tối ưu):\n";
    std::cout << "--------------------------------------------------------\n";

    long long total_positive_divisors = 0;

    for (int num : numbers) {
        long long count = count_positive_divisors(num);

        if (count >= 0) {
            std::cout << "So " << num << " co " << count << " uoc nguyen duong.\n";
            total_positive_divisors += count;
        } else if (count == -1) { 
            std::cout << "So " << num << " vuot qua gioi han Sàng (" << MAX_N << ").\n";
        }
    }
    
    std::cout << "--------------------------------------------------------\n";
    std::cout << "TONG so luong uoc nguyen duong cua cac so trong gioi han: " 
              << total_positive_divisors << "\n";

    // Kiem tra so 9:
    std::cout << "Kiem tra so 9:\n";
    std::cout << "So uoc nguyen duong cua 9: " << count_positive_divisors(6) << " (3 la dung)\n";

    return 0;
}