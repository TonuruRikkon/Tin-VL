#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>

using namespace std;

int count_pairs(const string& filename) {
    freopen(filename.c_str(), "r", stdin);
    int n;
    cin >> n;
    vector<tuple<int, int, int>> students(n);
    for (int i = 0; i < n; ++i) {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        students[i] = make_tuple(ai, bi, ci);
    }

    unordered_map<int, unordered_map<int, vector<int>>> natural_science;
    unordered_map<int, unordered_map<int, vector<int>>> social_science;

    for (const auto& student : students) {
        int ai, bi, ci;
        tie(ai, bi, ci) = student;
        natural_science[ci][ai].push_back(bi);
        social_science[ci][bi].push_back(ai);
    }

    int count = 0;

    for (const auto& [ci, ns_map] : natural_science) {
        for (const auto& [ai, bi_list] : ns_map) {
            for (int bi : bi_list) {
                if (social_science[ci].count(bi)) {
                    count += social_science[ci][bi].size() - 1;
                }
            }
        }
    }

    return count;
}

int main() {
    string filename = "BAI3.INP";
    int result = count_pairs(filename);
    freopen("BAI3.OUT", "w", stdout);
    cout << result << endl;
    return 0;
}
