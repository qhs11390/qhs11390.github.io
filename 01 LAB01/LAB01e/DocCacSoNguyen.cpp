#include <iostream>
#include <fstream>
using namespace std;

// Hàm đọc file chứa n số nguyên và xuất ra màn hình
void docCacSoNguyen(const char* tenFile) {
    ifstream inFile(tenFile); // Mở file để đọc
    if (!inFile) {
        cerr << "Lỗi: Không thể mở file " << tenFile << endl;
        return;
    }

    int n;
    inFile >> n; // Đọc số lượng phần tử từ dòng đầu tiên

    // Cấp phát mảng động chứa n số nguyên
    int* arr = new int[n];

    // Đọc n số nguyên từ file (dòng thứ 2)
    for (int i = 0; i < n; i++) {
        inFile >> arr[i];
    }
    inFile.close(); // Đóng file sau khi đọc xong

    // Xuất kết quả ra màn hình
    cout << "So luong phan tu: " << n << endl;
    cout << "Cac so nguyen doc duoc: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Giải phóng bộ nhớ đã cấp phát
    delete[] arr;
}

int main() {
    // Gọi hàm đọc file với tên file "DaySoNguyen.inp"
    docCacSoNguyen("DaySoNguyen.inp");
    return 0;
}