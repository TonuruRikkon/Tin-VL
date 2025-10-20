#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> inp(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> inp[i][j];

    vector<vector<int>> road(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (inp[i][j] == 2) {
                q.push({i, j});
                road[i][j] = 0;
            }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (inp[nx][ny] == 0 && road[nx][ny] == -1) {
                    road[nx][ny] = road[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    for (auto &row : road) {
        for (int y : row) cout << y << ' ';
        cout << '\n';
    }
}