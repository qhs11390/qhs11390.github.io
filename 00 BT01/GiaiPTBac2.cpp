#include <iostream>
#include <iomanip> // Để định dạng số với 2 chữ số thập phân
#include <cmath>   // Để sử dụng hàm sqrt
using namespace std;

void GiaiPTBac2(double a, double b, double c) {
    cout << fixed << setprecision(2); // Định dạng xuất số với 2 chữ số thập phân

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Phuong trinh co vo so nghiem" << endl;
            } else {
                cout << "Phuong trinh vo nghiem" << endl;
            }
        } else {
            double x = -c / b;
            cout << "Phuong trinh co 1 nghiem" << endl;
            cout << x << endl;
        }
    } else {
        double delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "Phuong trinh vo nghiem" << endl;
        } else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "Phuong trinh co 1 nghiem" << endl;
            cout << x << endl;
        } else {
            double x1 = (-b - sqrt(delta)) / (2 * a);
            double x2 = (-b + sqrt(delta)) / (2 * a);
            if (x1 > x2) swap(x1, x2); // Sắp xếp theo thứ tự tăng dần
            cout << "Phuong trinh co 2 nghiem" << endl;
            cout << x1 << " " << x2 << endl;
        }
    }
}

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    GiaiPTBac2(a, b, c);
    return 0;
}