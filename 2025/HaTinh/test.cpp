#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Nhập số sản phẩm
    int n;
    cin >> n;
    vector<pair<int, int>> inp(n); // Lưu giá bán và số khách hàng đã mua
    for (int i = 0; i < n; i++) {
        cin >> inp[i].first >> inp[i].second; // Giá bán và số khách hàng
    }

    // Sắp xếp các sản phẩm theo giá bán
    sort(inp.begin(), inp.end());

    // Nhập số lượng truy vấn
    int q;
    cin >> q;

    // Xử lý từng truy vấn
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        // Tìm khoảng giá [x, y] bằng lower_bound
        auto start = lower_bound(inp.begin(), inp.end(), make_pair(x, INT_MIN));
        auto ends = upper_bound(inp.begin(), inp.end(), make_pair(y, INT_MAX));

        // Nếu không có sản phẩm nào trong khoảng giá
        if (start == ends) {
            cout << 0 << '\n';
        } else {
            // Tìm sản phẩm có số khách hàng mua nhiều nhất trong khoảng [start, ends)
            auto max_it = max_element(start, ends, [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second; // So sánh dựa trên số khách hàng
            });
            cout << max_it->second << '\n'; // In ra số khách hàng mua nhiều nhất
        }
    }

    return 0;
}