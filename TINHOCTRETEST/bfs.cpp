#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 1005;

int a[MAXN][MAXN];
long long prefix[MAXN][MAXN];
long long dp[3][MAXN][MAXN]; // dp[k][i][j]: Tổng điểm lớn nhất tại (i, j) với k lần sử dụng công tắc

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    // Nhập ma trận điểm
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> a[i][j];
        }
    }

    // Tính mảng prefix
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            prefix[i][j] = a[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    // Khởi tạo dp
    for (int k = 0; k <= K; k++) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                dp[k][i][j] = -INF;
            }
        }
    }
    dp[0][1][1] = a[1][1]; // Bắt đầu tại (1, 1) không sử dụng công tắc

    // Quy hoạch động
    for (int k = 0; k <= K; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (i == 1 && j == 1) continue; // Bỏ qua ô bắt đầu

                // Không sử dụng công tắc
                dp[k][i][j] = max(dp[k][i-1][j], dp[k][i][j-1]) + a[i][j];

                // Sử dụng công tắc (nếu còn lượt)
                if (k > 0) {
                    for (int x = 1; x < i; x++) {
                        for (int y = 1; y < j; y++) {
                            long long score = prefix[i][j] - prefix[x][j] - prefix[i][y] + prefix[x][y];
                            dp[k][i][j] = max(dp[k][i][j], dp[k-1][x][y] + score);
                        }
                    }
                }
            }
        }
    }

    // Kết quả
    cout << dp[K][N][M] << endl;

    return 0;
}