#include <bits/stdc++.h>
using namespace std;

// Function to calculate the sum of digital roots up to n
long long sum_up_to(int n) {
    if (n <= 0) return 0;
    long long num_cycles = n / 9;
    long long remaining_count = n % 9;
    long long sum = num_cycles * 45;
    sum += (remaining_count * (remaining_count + 1)) / 2;
    return sum;
}

// Function to calculate the sum of digital roots in a range [l, r]
long long tolsum(int l, int r) {
    return sum_up_to(r) - sum_up_to(l - 1);
}


int main() {
    int n; // Renamed n_tests to n to match existing code
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cout << tolsum(x, y) << endl;
    }
    return 0;
}
