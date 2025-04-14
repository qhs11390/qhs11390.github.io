#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Moi ban nhap chuoi s: ";
    getline(cin, s);  // Nhập cả dòng, bao gồm khoảng trắng nếu có

    int k;
    cout << "Moi ban nhap vi tri can chen: ";
    cin >> k;

    // Kiểm tra tính hợp lệ của vị trí k (0 <= k <= |s|-1)
    if (k < 0 || k >= s.size()) {
        cout << "Vi tri chen khong hop le!" << endl;
        return 1;
    }

    char c;
    cout << "Moi ban nhap ky tu chen: ";
    cin >> c;

    // Chèn ký tự c vào vị trí k trong chuỗi s
    s.insert(s.begin() + k, c);

    cout << "Chuoi \"" << s << "\" sau khi them ky tu \"" << c 
         << "\" vao vi tri " << k << ": " << s << endl;

    return 0;
}