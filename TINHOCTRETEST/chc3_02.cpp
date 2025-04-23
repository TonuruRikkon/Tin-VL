#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int tol = 0;
    string temp = "";

    // Tính tổng các chữ số và loại bỏ số 0 đứng đầu
    for (char c : s) {
        tol += (c - '0');
        temp += c;
    }

    // Nếu tổng chia hết cho 3, in ra kết quả
    if (tol % 3 == 0) {
        // Loại bỏ các số 0 đứng đầu
        while (temp.size() > 1 && temp[0] == '0') {
            temp.erase(0, 1);
        }
        cout << (temp.empty() ? "-1" : temp) << endl;
        return 0;
    }

    // Phần dư của tổng
    int remainder = tol % 3;

    // Thử xóa một chữ số có phần dư bằng remainder
    bool removed = false;
    for (int i = 0; i < temp.size(); i++) {
        if ((temp[i] - '0') % 3 == remainder) {
            temp.erase(i, 1);
            removed = true;
            break;
        }
    }

    // Nếu không thể xóa một chữ số, thử xóa hai chữ số
    if (!removed) {
        int count = 0;
        for (int i = temp.size() - 1; i >= 0; i--) {
            if ((temp[i] - '0') % 3 != 0) {
                temp.erase(i, 1);
                count++;
                if (count == 2) break;
            }
        }
    }

    // Loại bỏ các số 0 đứng đầu
    while (temp.size() > 1 && temp[0] == '0') {
        temp.erase(0, 1);
    }

    // Nếu không còn số nào hợp lệ, in ra -1
    if (temp.empty() || (temp.size() == 1 && temp[0] == '0')) {
        cout << -1 << endl;
    } else {
        cout << temp << endl;
    }

    return 0;
}