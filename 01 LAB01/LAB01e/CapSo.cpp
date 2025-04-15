#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Mở file CapSo.INP để đọc dữ liệu
    ifstream fin("CapSo.INP");
    if (!fin) {
        cerr << "Loi: Khong the mo file CapSo.INP" << endl;
        return 1;
    }
    
    int n, k;
    fin >> n >> k; // Đọc số lượng phần tử và số k

    // Cấp phát mảng động lưu n số nguyên
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> arr[i];
    }
    fin.close(); // Đóng file sau khi đọc xong

    // Đếm số cặp thoả mãn: a_i + a_j = k với i < j
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == k) {
                count++;
            }
        }
    }
    
    // Mở file CapSo.OUT để ghi kết quả
    ofstream fout("CapSo.OUT");
    if (!fout) {
        cerr << "Loi: Khong the mo file CapSo.OUT" << endl;
        delete[] arr; // Giải phóng bộ nhớ
        return 1;
    }
    
    // Nếu không tìm được cặp số nào, ghi ra số 0
    if (count == 0) {
        fout << 0;
    } else {
        // Nếu có cặp, duyệt lại mảng để ghi các cặp thoả mãn vào file
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == k) {
                    fout << arr[i] << " " << arr[j] << "\n";
                }
            }
        }
    }
    
    fout.close();   // Đóng file kết quả
    delete[] arr;   // Giải phóng bộ nhớ đã cấp phát
    return 0;
}