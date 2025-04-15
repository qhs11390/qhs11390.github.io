#include <iostream>
#include <fstream>
using namespace std;

// Hàm đọc file chứa mảng 2 chiều các số nguyên
void docMang2CSoNguyen(const char* tenFile) {
    ifstream inFile(tenFile); // Mở file để đọc
    if (!inFile) {
        cerr << "Loi: Khong the mo file " << tenFile << endl;
        return;
    }

    int n, m;
    inFile >> n >> m; // Đọc số dòng và số cột từ dòng đầu tiên của file

    // Cấp phát mảng 2 chiều động với n dòng và m cột
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    // Đọc dữ liệu từ file cho từng phần tử của mảng
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            inFile >> arr[i][j];
        }
    }
    inFile.close(); // Đóng file sau khi đọc xong

    // Xuất mảng ra màn hình
    cout << "Ma tran " << n << " x " << m << " doc duoc tu file:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    // Giải phóng bộ nhớ đã cấp phát cho mảng 2 chiều
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    // Gọi hàm với tên file "MangSo.inp"
    docMang2CSoNguyen("MangSo.inp");
    return 0;
}