/*
LAB01b - Bai 3:
Cho dãy ký tự a có n phần tử (n ≤ 100). Hãy tạo dãy b chứa các ký tự nguyên âm của a và xuất b ra màn hình.
Ý tưởng:
+ Input: dãy ký tự a, số lượng phần tử n
+ Output: dãy ký tự b chứa các ký tự nguyên âm.
+ Ví dụ:
* n = 5
* Màn hình:
1. Mời bạn nhập số lượng phần tử: 5
2. Phần tử 0: a
3. Phần tử 1: b
4. Phần tử 2: c
5. Phần tử 3: d
6. Phần tử 4: e
+ Kết quả:
   + Dãy b chứa các ký tự nguyên âm: a e
+ Thuật toán:
B1. Nhập số lượng phần tử n và dãy ký tự a.
B2. Duyệt qua dãy a và tìm các ký tự nguyên âm.
B3. Tạo dãy b chứa các ký tự nguyên âm.
B4. Xuất dãy b ra màn hình.
*/

#include <iostream>
using namespace std;

bool isVowel(char c) {
    // Kiểm tra nếu ký tự là nguyên âm (a, e, i, o, u)
    c = tolower(c); // Chuyển ký tự về dạng thường để so sánh dễ dàng
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    int n;
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> n;

    // Sử dụng con trỏ để cấp phát động mảng ký tự
    char* a = new char[n];  // Mảng ký tự a
    char* b = new char[n];  // Mảng ký tự b chứa các nguyên âm

    // Nhập các ký tự vào dãy a
    for (int i = 0; i < n; ++i) {
        cout << "Phan tu " << i << ": ";
        cin >> *(a + i); // Sử dụng con trỏ để truy cập phần tử mảng
    }

    // Duyệt qua dãy a và tìm các ký tự nguyên âm
    int j = 0;  // Chỉ số cho dãy b
    for (int i = 0; i < n; ++i) {
        if (isVowel(*(a + i))) {  // Kiểm tra nếu ký tự a[i] là nguyên âm
            *(b + j) = *(a + i);  // Lưu ký tự nguyên âm vào dãy b
            ++j;  // Chuyển đến vị trí tiếp theo trong dãy b
        }
    }

    // In dãy b ra màn hình
    cout << "Day cac ky tu nguyen am: ";
    for (int i = 0; i < j; ++i) {
        cout << *(b + i) << " ";  // In ra dãy ký tự nguyên âm
    }
    cout << endl;

    // Giải phóng bộ nhớ đã cấp phát động
    delete[] a;
    delete[] b;

    return 0;
}