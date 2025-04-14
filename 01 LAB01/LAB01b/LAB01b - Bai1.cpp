/*
LAB01b - Bai 1:
Cho hệ số a, b, c của phương trình bậc hai. Viết chương trình giải phương trình bậc hai (dùng con trỏ).
Ý tưởng:
+ Input: a, b, c
+ Output: màn hình
+ Ví dụ:
* a = 1, b = 2, c = 1
* Màn hình:
1. Mời bạn nhập hệ số a, b, c: 1 2 1
2. Phương trình có 1 nghiệm kép x = -1
+ Thuật toán:
B1. Nhập a, b, c
B2. Tính delta
B3. Xuất nghiệm phương trình tương ứng
*/

#include <iostream>
#include <cmath> // sqrt
using namespace std;

// Function prototype
void giaiPhuongTrinh(double *a, double *b, double *c);

int main() {
    double a, b, c;
    
    // Nhập hệ số a, b, c
    cout << "Moi ban nhap he so a, b, c: ";
    cin >> a >> b >> c;
    
    // Gọi hàm giải phương trình
    giaiPhuongTrinh(&a, &b, &c);
    
    return 0;
}

// Function definition
void giaiPhuongTrinh(double *a, double *b, double *c) {
    double delta, x1, x2;
    
    // Tính delta
    delta = (*b) * (*b) - 4 * (*a) * (*c);
    
    if (delta > 0) {
        // Hai nghiệm phân biệt
        x1 = (-(*b) + sqrt(delta)) / (2 * (*a));
        x2 = (-(*b) - sqrt(delta)) / (2 * (*a));
        cout << "Phuong trinh co 2 nghiem phan biet x1 = " << x1 << " va x2 = " << x2 << endl;
    } else if (delta == 0) {
        // Nghiệm kép
        x1 = -(*b) / (2 * (*a));
        cout << "Phuong trinh co 1 nghiem kep x = " << x1 << endl;
    } else {
        // Phương trình vô nghiệm
        cout << "Phuong trinh vo nghiem" << endl;
    }
}