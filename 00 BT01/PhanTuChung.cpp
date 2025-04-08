#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int nx, ny, nz;
    
    // Nhập số lượng phần tử của dãy x
    cin >> nx;

    // Nhập các phần tử của dãy x và đánh dấu trong map m1
    vector<int> x(nx);                    // Dãy x có nx phần tử
    unordered_map<int, int> m1;           // Map để đếm số lần xuất hiện trong dãy x
    for (int i = 0; i < nx; i++) {
        cin >> x[i];                      // Nhập phần tử vào dãy x
        m1[x[i]]++;                       // Đánh dấu phần tử trong map
    }

    // Nhập số lượng phần tử của dãy y
    cin >> ny;

    // Nhập các phần tử của dãy y và đánh dấu trong map m2
    vector<int> y(ny);                    // Dãy y có ny phần tử
    unordered_map<int, int> m2;           // Map để đếm số lần xuất hiện trong dãy y
    for (int i = 0; i < ny; i++) {
        cin >> y[i];                      // Nhập phần tử vào dãy y
        m2[y[i]]++;                       // Đánh dấu phần tử trong map
    }

    // Nhập số lượng phần tử của dãy z
    cin >> nz;

    // Nhập các phần tử của dãy z và đánh dấu trong map m3
    vector<int> z(nz);                    // Dãy z có nz phần tử
    unordered_map<int, int> m3;           // Map để đếm số lần xuất hiện trong dãy z
    for (int i = 0; i < nz; i++) {
        cin >> z[i];                      // Nhập phần tử vào dãy z
        m3[z[i]]++;                       // Đánh dấu phần tử trong map
    }

    // Tìm các phần tử chung xuất hiện trong cả 3 dãy
    vector<int> result;                   // Lưu trữ các phần tử chung
    for (int i = 0; i <= 10000; i++) {    // Duyệt qua tất cả các giá trị từ 0 đến 10,000
        if (m1[i] > 0 && m2[i] > 0 && m3[i] > 0) {  // Kiểm tra phần tử có trong cả 3 dãy
            result.push_back(i);          // Thêm phần tử vào danh sách kết quả
        }
    }

    // In ra kết quả
    cout << result.size() << endl;        // In số lượng phần tử chung
    for (int i : result) {                // In từng phần tử chung (thứ tự tăng dần)
        cout << i << " ";
    }

    return 0;
}