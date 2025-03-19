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
    cout<<num<<" "<<den;
}

int main()
{
    vector<pair<int,int>> a;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        long long x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }
    sumA(a);
}