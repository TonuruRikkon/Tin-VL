#include <bits/stdc++.h>
using namespace std;

struct Product {
    int price;
    int customers;
};

bool compare(Product a, Product b) {
    return a.price < b.price;
}

int main() {
    // Mở tệp input và output
    ifstream infile("BSHOP.INP");
    ofstream outfile("BSHOP.OUT");

    int n, q;
    infile >> n;

    vector<Product> products(n);

    // Nhập thông tin sản phẩm
    for (int i = 0; i < n; i++) {
        infile >> products[i].price >> products[i].customers;
    }

    // Sắp xếp sản phẩm theo giá bán (v)
    sort(products.begin(), products.end(), compare);

    infile >> q; // Số truy vấn

    // Xử lý truy vấn
    for (int i = 0; i < q; i++) {
        int x, y;
        infile >> x >> y;

        // Tìm sản phẩm có giá trong khoảng [x, y]
        int left = lower_bound(products.begin(), products.end(), Product{x, 0}, compare) - products.begin();
        int right = upper_bound(products.begin(), products.end(), Product{y, INT_MAX}, compare) - products.begin();

        int maxCustomers = 0;
        // Duyệt qua các sản phẩm trong khoảng giá [x, y]
        for (int j = left; j < right; j++) {
            maxCustomers = max(maxCustomers, products[j].customers);
        }

        // Nếu không có sản phẩm trong khoảng giá, in ra 0
        if (maxCustomers == 0) {
            outfile << 0 << endl;
        } else {
            outfile << maxCustomers << endl;
        }
    }

    // Đóng tệp input và output
    infile.close();
    outfile.close();

    return 0;
}