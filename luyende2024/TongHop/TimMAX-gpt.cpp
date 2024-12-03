#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
using namespace std;

// Hàm phân tích thừa số nguyên tố của m
map<int, int> factorize(int m) {
    map<int, int> factors;
    for (int i = 2; i <= sqrt(m); ++i) {
        while (m % i == 0) {
            factors[i]++;
            m /= i;
        }
    }
    if (m > 1) {
        factors[m] = 1; // m là số nguyên tố
    }
    return factors;
}

// Hàm tính số mũ của p trong n!
int countPowerInFactorial(int n, int p) {
    int count = 0;
    while (n >= p) {
        count += n / p;
        n /= p;
    }
    return count;
}

// Hàm tìm K lớn nhất
int findMaxK(int n, int m) {
    map<int, int> factors = factorize(m);
    int k = INT_MAX; // Khởi tạo K lớn nhất
    for (auto factor : factors) {
        int p = factor.first;  // Thừa số nguyên tố
        int e = factor.second; // Số mũ của thừa số
        cout<<p<<":"<<e<<"="<<countPowerInFactorial(n, p)<<" ";
        k = min(k, countPowerInFactorial(n, p) / e);
    }
    return k;
}

int main() {
    // Đọc dữ liệu từ file BAI5.INP
    int n,m;
    cin>>n>>m;

    // Tìm K lớn nhất
    int k = findMaxK(n, m);

    // Ghi kết quả ra file BAI5.OUT
    cout<<k;

    return 0;
}