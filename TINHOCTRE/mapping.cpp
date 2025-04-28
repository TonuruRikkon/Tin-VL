#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;

    vector<char> inp(26);
    iota(inp.begin(), inp.end(), 'a'); 

    for (int i = 0; i < q; i++) {
        char x, y;
        cin >> x >> y;

        for (int j = 0; j < 26; j++) {
            if (inp[j] == x) {
                inp[j] = y;
            }
        }
    }

    for (char& c : s) {
        c = inp[c - 'a'];
    }

    cout << s << endl;

    return 0;
}