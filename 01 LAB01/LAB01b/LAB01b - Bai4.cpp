/*
LAB01b - Bai 4:
Cho dãy số thực a có n phần tử và b có m phần tử (n, m ≤ 100) tăng dần. 
Hãy tạo dãy c từ hai dãy a, b sao cho tăng dần (không dùng sắp xếp).

Ý tưởng:
+ Input: dãy số thực a có n phần tử, dãy số thực b có m phần tử.
+ Output: dãy số thực c chứa tất cả phần tử từ a và b, vẫn tăng dần.
+ Ví dụ:
  * Dãy a:
    Moi ban nhap so luong phan tu: 3
    Phan tu 0: 1.1
    Phan tu 1: 3.2
    Phan tu 2: 5.3
  * Dãy b:
    Moi ban nhap so luong phan tu: 4
    Phan tu 0: 2.1
    Phan tu 1: 3.2
    Phan tu 2: 5.4
    Phan tu 3: 8.4
  * Output:
    + Day so c:
    Day so co 7 phan tu: 1.1 2.1 3.2 3.2 5.3 5.4 8.4

Thuật toán:
B1. Nhập số lượng phần tử của dãy a và b.
B2. Nhập dãy a và b theo thứ tự tăng dần.
B3. Duyệt cả hai dãy bằng con trỏ để tạo dãy c mà vẫn giữ nguyên thứ tự.
B4. Xuất dãy c ra màn hình.
*/

#include <iostream>
using namespace std;

// funtion prototype
void mergeSortedArrays(double* a, int n, double* b, int m, double* c, int& sizeC);

int main() {
    int n, m;
    
    // Nhập dãy số a
    cout << "+ Day so a\nMoi ban nhap so luong phan tu: ";
    cin >> n;
    double* a = new double[n];  // Cấp phát động mảng a
    for (int i = 0; i < n; ++i) {
        cout << "Phan tu " << i << ": ";
        cin >> *(a + i);
    }

    // Nhập dãy số b
    cout << "+ Day so b\nMoi ban nhap so luong phan tu: ";
    cin >> m;
    double* b = new double[m];  // Cấp phát động mảng b
    for (int i = 0; i < m; ++i) {
        cout << "Phan tu " << i << ": ";
        cin >> *(b + i);
    }

    // Cấp phát động mảng c với kích thước tối đa n + m
    double* c = new double[n + m];  
    int sizeC;  // Số phần tử thực tế của dãy c

    // Gộp hai dãy số đã sắp xếp
    mergeSortedArrays(a, n, b, m, c, sizeC);

    // Xuất kết quả
    cout << "+ Day so c\nDay so co " << sizeC << " phan tu: ";
    for (int i = 0; i < sizeC; ++i) {
        cout << *(c + i) << " ";
    }
    cout << endl;

    // Giải phóng bộ nhớ đã cấp phát động
    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}

// function definition
void mergeSortedArrays(double* a, int n, double* b, int m, double* c, int& sizeC) {
    int i = 0, j = 0, k = 0;
    
    // Trộn hai dãy a và b vào dãy c theo thứ tự tăng dần
    while (i < n && j < m) {
        if (*(a + i) <= *(b + j)) {
            *(c + k) = *(a + i);
            i++;
        } else {
            *(c + k) = *(b + j);
            j++;
        }
        k++;
    }

    // Nếu còn phần tử trong dãy a
    while (i < n) {
        *(c + k) = *(a + i);
        i++;
        k++;
    }

    // Nếu còn phần tử trong dãy b
    while (j < m) {
        *(c + k) = *(b + j);
        j++;
        k++;
    }

    sizeC = k;  // Số phần tử thực tế của dãy c
}