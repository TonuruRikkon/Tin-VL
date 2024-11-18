#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[1000000], t[1000000];
    int k, i, x, y, n, d = 0, ans = 0;
    string s;
    cin >> k >> s;

    s = '@' + s; // Thêm ký tự '@' vào đầu chuỗi
    n = s.size() - 1;
    memset(a, 0, sizeof(a));

    // Tính toán giá trị a[i]
    for (i = 1; i < s.size(); i++) {
        a[i] = a[i - 1] + s[i] - '0';
    }

    // Xử lý đoạn mã chính
    for (i = 0; i < n; i++) {
        x = lower_bound(a + i, a + 1 + n, a[i] + k) - a;
        y = lower_bound(a + i, a + 1 + n, a[i] + k) - a;
        cout << "x = " << x << " y = " << y << endl;

        if (x == a[i] + k) {
            ans++;
            for (int j = y; j <= n; j++) {
                if (a[j] == a[j + 1]) {
                    ans++;
                } else break;
            }
        }
    }
    cout << ans;
    return 0;
}