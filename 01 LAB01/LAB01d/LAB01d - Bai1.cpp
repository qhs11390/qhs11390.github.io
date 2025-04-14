#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Moi ban nhap chuoi s: ";
    getline(cin, s);  // Nhập cả dòng (để bao gồm cả khoảng trắng nếu có)
    
    // Sắp xếp các ký tự trong chuỗi theo thứ tự tăng dần
    sort(s.begin(), s.end());
    
    cout << "Chuoi \"" << s << "\" sau khi sap xep: " << s << endl;
    return 0;
}