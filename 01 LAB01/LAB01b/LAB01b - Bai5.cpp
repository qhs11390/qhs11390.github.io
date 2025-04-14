/*
LAB01b - Bai 5:
Cho dãy số nguyên a có n phần tử (n ≤ 100). Hãy tách dãy a thành:
+ Dãy b chứa các số chẵn.
+ Dãy c chứa các số lẻ.

Ý tưởng:
+ Input: dãy số nguyên a, số lượng phần tử n.
+ Output: dãy số b (số chẵn), dãy số c (số lẻ).
+ Ví dụ:
  * Dãy a:
    Moi ban nhap so luong phan tu: 3
    Phan tu 0: 2
    Phan tu 1: 5
    Phan tu 2: 8
  * Output:
    + Day so b chua so chan:
    Day so co 2 phan tu: 2 8
    + Day so c chua so le:
    Day so co 1 phan tu: 5

Thuật toán:
B1. Nhập số lượng phần tử của dãy a.
B2. Phân loại từng phần tử vào dãy b (chẵn) hoặc dãy c (lẻ).
B3. Xuất kết quả.
*/

#include <iostream>
using namespace std;

// function prototype
void separateEvenOdd(int* a, int n, int* b, int& sizeB, int* c, int& sizeC);

int main() {
    int n;

    // Nhập dãy số a
    cout << "+ Day so a\nMoi ban nhap so luong phan tu: ";
    cin >> n;

    int* a = new int[n];  // Cấp phát động mảng a
    for (int i = 0; i < n; ++i) {
        cout << "Phan tu " << i << ": ";
        cin >> *(a + i);
    }

    // Cấp phát động mảng b và c với kích thước tối đa n
    int* b = new int[n];  
    int* c = new int[n];  
    int sizeB, sizeC;

    // Phân tách dãy số a
    separateEvenOdd(a, n, b, sizeB, c, sizeC);

    // Xuất dãy số chẵn
    cout << "+ Day so b chua so chan\n";
    cout << "Day so co " << sizeB << " phan tu: ";
    for (int i = 0; i < sizeB; ++i) {
        cout << *(b + i) << " ";
    }
    cout << endl;

    // Xuất dãy số lẻ
    cout << "+ Day so c chua so le\n";
    cout << "Day so co " << sizeC << " phan tu: ";
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

//function definition
void separateEvenOdd(int* a, int n, int* b, int& sizeB, int* c, int& sizeC) {
    sizeB = 0;
    sizeC = 0;
    
    for (int i = 0; i < n; ++i) {
        if (*(a + i) % 2 == 0) {  // Số chẵn
            *(b + sizeB) = *(a + i);
            sizeB++;
        } else {  // Số lẻ
            *(c + sizeC) = *(a + i);
            sizeC++;
        }
    }
}