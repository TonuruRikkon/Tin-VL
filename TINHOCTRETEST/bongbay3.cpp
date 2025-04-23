#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
const int MAXS = 10;

vector<int> fenwick(MAXS + 1, 0);

// Hàm cập nhật Fenwick Tree
void update(int i, int val) {
    while (i <= MAXS) {
        fenwick[i] += val;
        i += i & -i;
    }
}

// Hàm truy vấn Fenwick Tree
int query(int i) {
    int sum = 0;
    while (i > 0) {
        sum += fenwick[i];
        i -= i & -i;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);
    vector<int> results(q);

    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    // Tính số lượng phần tử nhỏ hơn ở bên phải
    vector<int> right_count(n + 1, 0);
    fill(fenwick.begin(), fenwick.end(), 0);
    for (int i = n; i >= 1; i--) {
        right_count[i] = query(s[i] - 1);
        update(s[i], 1);
    }

    // Tính số lượng phần tử lớn hơn ở bên trái
    vector<int> left_count(n + 1, 0);
    fill(fenwick.begin(), fenwick.end(), 0);
    for (int i = 1; i <= n; i++) {
        left_count[i] = query(MAXS) - query(s[i]);
        update(s[i], 1);
    }

    // Trả lời từng truy vấn
    for (int t = 0; t < q; t++) {
        int L = queries[t].first;
        int R = queries[t].second;

        // Tính số cặp sặc sỡ trong đoạn [L, R]
        long long result = 0;
        for (int i = L; i <= R; i++) {
            if (i < R) result += right_count[i];
            if (i > L) result += left_count[i];
        }
        results[t] = result;
    }

    // In kết quả
    for (int i = 0; i < q; i++) {
        cout << results[i] << "\n";
    }

    return 0;
}