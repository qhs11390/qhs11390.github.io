#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n <= 1)
        return false; // Số nhỏ hơn hoặc bằng 1 không phải số nguyên tố
    if (n == 2)
        return true;  // 2 là số nguyên tố duy nhất chẵn
    if (n % 2 == 0)
        return false;
    int limit = static_cast<int>(sqrt(n));
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    // Mở file NT.INP để đọc dữ liệu
    ifstream fin("NT.INP");
    if (!fin) {
        cerr << "Loi: Khong the mo file NT.INP" << endl;
        return 1;
    }
    
    int n;
    fin >> n; // Đọc số lượng phần tử
    vector<int> primeNumbers; // Vector lưu các số nguyên tố

    // Đọc n số và kiểm tra số nguyên tố
    for (int i = 0; i < n; i++) {
        int a;
        fin >> a;
        if (isPrime(a))
            primeNumbers.push_back(a);
    }
    fin.close(); // Đóng file sau khi đọc xong

    // Sắp xếp các số nguyên tố theo thứ tự tăng dần
    sort(primeNumbers.begin(), primeNumbers.end());

    // Mở file NT.OUT để ghi kết quả
    ofstream fout("NT.OUT");
    if (!fout) {
        cerr << "Loi: Khong the mo file NT.OUT" << endl;
        return 1;
    }
    
    // Ghi số lượng số nguyên tố tìm được
    fout << primeNumbers.size() << endl;
    
    // Ghi các số nguyên tố, cách nhau bằng một khoảng trắng
    for (size_t i = 0; i < primeNumbers.size(); i++) {
        fout << primeNumbers[i];
        if (i != primeNumbers.size() - 1)
            fout << " ";
    }
    fout << endl;
    fout.close(); // Đóng file NT.OUT

    return 0;
}