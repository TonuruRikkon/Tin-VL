#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    cin >> n;
    set<pair<double,string>> s;
    s.insert({0.0, "0/1"});
    s.insert({1.0, "1/1"});
    for(int j = 1; j <= n; j++){
        for(int i = 0; i <= j; i++){
            if(__gcd(i,j) == 1){
                s.insert({(double)i/j, to_string(i)+"/"+to_string(j)});
            }
        }
    }

    for(auto x : s)cout<< x.second <<endl;
}