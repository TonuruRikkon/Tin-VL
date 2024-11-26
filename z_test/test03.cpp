#include <bits/stdc++.h>
using namespace std;

struct node {
   unordered_map <char, node*> um;
   bool end = 0;
};

int main() {
   string s, t, sn;
   int n, m, ans = 0;
   getline(cin, s);
   cin >> n;
   cin.ignore();
   m = s.size();
   node *root = new node, *r;
   while (n--) {
       r = root;
       getline(cin, t);
       for (char ch : t) {
           if (!(r -> um[ch])) r -> um[ch] = new node;
           r = r -> um[ch];
       }
       r -> end = 1;
   }

   for (int i = 1; i <= m; i++) {
       int j = i - 1;
       r = root;
       while (++j <= m) {
           if (r -> um[s[j - 1]]) r = r -> um[s[j - 1]];
           else break;
           if (r -> end) ans++;
       }
   }
   cout << ans;
   return 0;
}