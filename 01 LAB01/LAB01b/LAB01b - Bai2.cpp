/*
LAB01b - Bai 2:
Cho dãy số nguyên a có n phần tử (n ≤ 100). Hãy kiểm tra các tính chất sau của dãy a:
+ Tính chẵn lẻ (các phần tử xen kẽ nhau chẵn lẻ).
+ Tính toàn chẵn (dãy số chứa toàn số chẵn).
Ý tưởng:
+ Input: dãy số nguyên a, số lượng phần tử n
+ Output: các kết quả kiểm tra tính chất chẵn lẻ và toàn chẵn.
+ Ví dụ:
* n = 5
* Màn hình:
1. Mời bạn nhập số lượng phần tử: 5
2. Phần tử 0: 2
3. Phần tử 1: 5
4. Phần tử 2: 6
5. Phần tử 3: 5
6. Phần tử 4: 2
+ Kết quả:
   + Dãy có tính chất chẵn lẻ
   + Dãy không có tính chất toàn chẵn
+ Thuật toán:
B1. Nhập số lượng phần tử n và dãy số a.
B2. Kiểm tra tính chất chẵn lẻ.
B3. Kiểm tra tính chất toàn chẵn.
B4. Xuất kết quả.
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> n;
    
    // Sử dụng con trỏ để cấp phát động mảng
    int* a = new int[n]; // Mảng được cấp phát động bằng con trỏ
    
    // Nhập các phần tử cho mảng
    for (int i = 0; i < n; ++i) {
        cout << "Phan tu " << i << ": ";
        cin >> *(a + i); // Dùng con trỏ để truy cập phần tử mảng
    }

    // Kiểm tra tính chẵn lẻ
    bool chanLe = true;
    for (int i = 0; i < n - 1; ++i) {
        if ((*(a + i) % 2 == 0 && *(a + i + 1) % 2 == 0) || (*(a + i) % 2 != 0 && *(a + i + 1) % 2 != 0)) {
            chanLe = false;
            break;
        }
    }

    // Kiểm tra tính toàn chẵn
    bool toanChan = true;
    for (int i = 0; i < n; ++i) {
        if (*(a + i) % 2 != 0) {
            toanChan = false;
            break;
        }
    }

    // In kết quả
    if (chanLe) {
        cout << "+ Day co tinh chat chan le" << endl;
    } else {
        cout << "+ Day khong co tinh chat chan le" << endl;
    }

    if (toanChan) {
        cout << "+ Day co tinh chat toan chan" << endl;
    } else {
        cout << "+ Day khong co tinh chat toan chan" << endl;
    }

    // Giải phóng bộ nhớ đã cấp phát động
    delete[] a; 

    return 0;
}