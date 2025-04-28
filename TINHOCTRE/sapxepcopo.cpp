#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> swaps; // Lưu các thao tác hoán đổi

    // Sắp xếp mảng bằng Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(a[i], a[minIndex]);
            swaps.push_back({i + 1, minIndex + 1}); // Lưu thao tác (i+1, minIndex+1)
        }
    }

    // In kết quả
    cout << swaps.size() << endl; // Số lượng thao tác
    for (auto [i, j] : swaps) {
        cout << i << " " << j << endl; // Các thao tác hoán đổi
    }

    return 0;
}