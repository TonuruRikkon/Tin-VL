#include <bits/stdc++.h>
using namespace std;

// Hàm tính trọng số nhỏ nhất của xâu nén tốt nhất
int minCompressedLength(const string &s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    // Khởi tạo dp cho các xâu con độ dài 1
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    // Xét các xâu con có độ dài từ 2 đến n
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            string sub = s.substr(i, len);

            // Giả sử không nén, trọng số là độ dài xâu
            dp[i][j] = len;

            // Kiểm tra các cách chia xâu con thành 2 phần
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }

            // Kiểm tra xem xâu con có thể nén được không
            for (int k = 1; k <= len / 2; ++k) {
                if (len % k == 0) {
                    string pattern = sub.substr(0, k);
                    bool valid = true;
                    for (int l = 0; l < len; l += k) {
                        if (sub.substr(l, k) != pattern) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        dp[i][j] = min(dp[i][j], int(dp[i][i + k - 1] + 2 + to_string(len / k).size()));
                    }
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    string s;
    while (cin >> s && s != "*") {
        cout << minCompressedLength(s) << endl;
    }
    return 0;
}