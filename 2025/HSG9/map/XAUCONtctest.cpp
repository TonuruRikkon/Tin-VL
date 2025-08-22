#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> val(26);
    for (int i = 0; i < 26; ++i) cin >> val[i];
    string s;
    cin >> s;
    int n = s.size();
    vector<long long> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + val[s[i - 1] - 'a'];

    // map<char, map<sum, count>>
    vector<unordered_map<long long, int>> cnt(26);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int c = s[i - 1] - 'a';
        // Đếm số lần xuất hiện sum[i-1] ở ký tự c trước đó
        ans += cnt[c][sum[i - 1]];
        // Lưu lại sum[i] ở ký tự c
        cnt[c][sum[i]]++;
    }
    cout << ans << '\n';
    return 0;
}