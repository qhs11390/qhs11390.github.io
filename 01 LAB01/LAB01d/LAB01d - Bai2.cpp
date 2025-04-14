#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Moi ban nhap chuoi s: ";
    getline(cin, s); // Đọc cả dòng để lấy chuỗi, kể cả khoảng trắng nếu có

    int k;
    cout << "Moi ban nhap vi tri can xoa: ";
    cin >> k;

    // Kiểm tra xem vị trí k có hợp lệ không (0 <= k < độ dài chuỗi)
    if (k < 0 || k >= s.size()) {
        cout << "Vi tri " << k << " khong hop le!" << endl;
        return 1;
    }

    // Xóa ký tự tại vị trí k
    s.erase(k, 1);

    cout << "Chuoi \"" << s << "\" sau khi xoa ky tu tai vi tri " << k << ": " << s << endl;
    return 0;
}