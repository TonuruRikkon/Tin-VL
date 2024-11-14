#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool nt(int x) {
    if (x <= 1) return false;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

// Hàm đếm số chính phương thỏa mãn điều kiện
int sum(int n) {
    int count = 0;
    for (int m = 1; m * m <= n; ++m) {
        int s = 1 + m + m * m;
        if (nt(s)) { 
            count++;cout<<m<<" "<<count<<endl;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    // In kết quả
    cout << sum(n) << endl;
    
    return 0;
}