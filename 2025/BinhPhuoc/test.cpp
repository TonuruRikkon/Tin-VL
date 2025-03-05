#include <bits/stdc++.h>
using namespace std;

// Hàm tính tổng các phân số và chuyển thành hỗn số
void sumA(const vector<pair<int, int>>& a) {
    int num = 0, den = 1;

    // Tính tổng các phân số
    for (auto frac : a) {	
        int a = frac.first, b = frac.second;
        num = num * b + a * den;
        den *= b;

        // Rút gọn phân số sau mỗi bước cộng
        int g = __gcd(abs(num), abs(den));
        num /= g;
        den /= g;
    }
}

int main()
{
    
}