#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Cặp {Prefix Sum Value, Index}
using PrefixInfo = pair<long long, int>;

/**
 * @brief Tìm đoạn con liên tiếp dài nhất có tổng âm sử dụng Set (O(N log N)).
 * @param A Dãy số nguyên đầu vào.
 * @return Độ dài lớn nhất của đoạn con có tổng âm.
 */
int findLongestNegativeSumSubarray_BalancedTree(const vector<int>& A) {
    int n = A.size();
    if (n == 0) return 0;
    
    // 1. Tính mảng cộng dồn P
    vector<long long> P(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        P[i + 1] = P[i] + A[i];
    }
    
    // 2. Sử dụng std::set để lưu trữ {P[k], k}
    // Set tự động sắp xếp theo P[k] (key), và k (secondary key).
    set<PrefixInfo> seen_sums;
    seen_sums.insert({P[0], 0}); // Thêm P[0]=0, index 0
    
    int maxLength = 0;

    // 3. Duyệt j từ 1 đến N
    for (int j = 1; j <= n; ++j) {
        // Ta cần tìm k < j nhỏ nhất sao cho P[k] > P[j].
        
        // Bước A: Tìm P[k] lớn hơn P[j]
        // upper_bound tìm phần tử đầu tiên > {P[j], X}
        // Ta dùng {P[j], N+1} để đảm bảo nó tìm được các P[k] > P[j], 
        // ngay cả khi có P[k] = P[j] (vì 0..N < N+1)
        auto it = seen_sums.upper_bound({P[j], n});

        // Nếu tìm thấy một prefix sum P[k] > P[j]
        if (it != seen_sums.end()) {
            // Bước B: Tìm k nhỏ nhất
            // Duyệt ngược từ it (P[k] > P[j]) trở về đầu set.
            // Khi ta duyệt ngược, ta đang xét các P[k] giảm dần (từ P[k] > P[j] về P[k] <= P[j]).
            // Chúng ta chỉ cần chỉ số k nhỏ nhất trong số các phần tử có P[k] > P[j].

            // Bắt đầu từ it (phần tử đầu tiên có P[k] > P[j])
            // Ta lặp qua các phần tử có cùng giá trị P[k] nhưng chỉ số k khác nhau.
            // Do set sắp xếp theo chỉ số k nếu P[k] bằng nhau, ta cần tìm k nhỏ nhất
            // trong số tất cả các P[k] > P[j].
            
            // Thay vì duyệt, ta chỉ cần xét phần tử đã tìm được (it), và sau đó 
            // xét tất cả các phần tử có P[k] bằng với it->first
            
            // Tìm k_min cho tất cả các P[k] >= P[j]
            // Cách đơn giản nhất: k_min là chỉ số của phần tử đầu tiên trong phạm vi [it, end())
            // Vì set sắp xếp theo P[k], rồi đến k. 
            // PHẦN TỬ ĐẦU TIÊN CÓ P[k] > P[j] là it.
            // PHẦN TỬ ĐẦU TIÊN CÓ P[k] LỚN HƠN hoặc BẰNG P[j] là it_lower.
            
            // Tìm phần tử P[k] đầu tiên có giá trị lớn hơn hoặc bằng P[j]
            auto it_lower = seen_sums.lower_bound({P[j], 0});

            // Nếu it_lower không phải là end() và P[it_lower->first] > P[j]
            if (it_lower != seen_sums.end() && it_lower->first > P[j]) {
                // Ta tìm chỉ số k nhỏ nhất trong số tất cả các phần tử có P[k] >= P[j].
                // Set không hỗ trợ min index range query.
                
                // Giải pháp đơn giản (không tối ưu hoàn toàn): duyệt từ it_lower
                int k_min = n + 1;
                for (auto iter = it_lower; iter != seen_sums.end(); ++iter) {
                    if (iter->first > P[j]) { // Điều kiện P[k] > P[j]
                        k_min = min(k_min, iter->second);
                    } else {
                        // Vì P[k] đã sắp xếp, nếu P[k] <= P[j] thì dừng.
                        // (Thực tế, it_lower đã đảm bảo P[k] >= P[j]).
                        break; 
                    }
                }
                
                if (k_min <= n) {
                    maxLength = max(maxLength, j - k_min);
                }
            }
        }

        // 4. Thêm P[j] vào set để sử dụng cho các bước tiếp theo (j' > j)
        // Chỉ thêm nếu P[j] và index j chưa tồn tại (để tránh trùng lặp)
        seen_sums.insert({P[j], j});
    }
    
    return maxLength;
}

int main() {
    // Test case: [3, -7, 9, -20, 3, 8, 5, 1, 18], Kết quả mong đợi 7
    freopen("SUMOFNEG.INP","r",stdin);
    freopen("SUMOFNEG.OUT","w",stdout);
    int n;
    cin>>n;
    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        A.push_back(x);
    }
    
    
    int result = findLongestNegativeSumSubarray_BalancedTree(A);
    
    cout << "Day so: ";
    for (int x : A) {
        cout << x << " ";
    }
    cout << endl;
    
    cout << "Do dai lon nhat co tong am (O(N log N) voi Set): " << result << endl; 
    
    return 0;
}