#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> vis;
vector<vector<int>> inp;
int Ox[4] = {0, 0, 1, -1};
int Oy[4] = {1, -1, 0, 0};
int n, m;

void dfs(int y, int x) {
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int posX = x + Ox[i];
        int posY = y + Oy[i];
        if (posX >= 0 && posX < m && posY >= 0 && posY < n && !vis[posY][posX] && inp[posY][posX] == 1) {
            dfs(posY, posX);
        }
    }
}

int main() {
    freopen("CHIENHAM.INP", "r", stdin);
    freopen("CHIENHAM.OUT", "w", stdout);
    cin >> n >> m;
    vis.resize(n, vector<bool>(m, false));
    inp.resize(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> inp[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j] && inp[i][j] == 1) {
                dfs(i, j);
                ++ans;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
