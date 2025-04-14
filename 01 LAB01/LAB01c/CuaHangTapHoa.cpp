#include <iostream>
#include <cstring>
using namespace std;

// Khai báo cấu trúc MatHang
struct MatHang {
    char msmh[20];    // Mã số mặt hàng
    char tenmh[50];   // Tên mặt hàng
    int soLuong;      // Số lượng mặt hàng
    double donGia;    // Đơn giá
};

// a) Hàm nhập thông tin 1 mặt hàng
void NhapMatHang(MatHang &mh) {
    cout << "Nhap MSMH (ma so mat hang): ";
    cin.getline(mh.msmh, 20);
    
    cout << "Nhap Ten mat hang: ";
    cin.getline(mh.tenmh, 50);
    
    cout << "Nhap So luong: ";
    cin >> mh.soLuong;
    
    cout << "Nhap Don gia: ";
    cin >> mh.donGia;
    cin.ignore(); // Xóa ký tự newline sau khi nhập số
}

// a) Hàm nhập danh sách các mặt hàng (n <= 100)
void NhapDanhSach(MatHang ds[], int &n) {
    cout << "Nhap so luong mat hang (n <= 100): ";
    cin >> n;
    while(n < 0 || n > 100) {
        cout << "So luong khong hop le. Nhap lai (n <= 100): ";
        cin >> n;
    }
    cin.ignore(); // xóa newline
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin mat hang thu " << i + 1 << ":\n";
        NhapMatHang(ds[i]);
    }
}

// Hàm xuất thông tin của 1 mặt hàng
void XuatMatHang(const MatHang &mh) {
    cout << "MSMH: " << mh.msmh << "\n";
    cout << "Ten mat hang: " << mh.tenmh << "\n";
    cout << "So luong: " << mh.soLuong << "\n";
    cout << "Don gia: " << mh.donGia << "\n";
}

// b) Hàm tìm mặt hàng theo tên (so sánh chuỗi TenMH)
// Trả về vị trí trong mảng nếu tìm thấy, nếu không trả về -1.
int TimMatHang(MatHang ds[], int n, const char *ten) {
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].tenmh, ten) == 0) {
            return i;
        }
    }
    return -1;
}

// c) Hàm tính tổng số lượng của các mặt hàng trong danh sách
int TinhTongSoLuong(MatHang ds[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].soLuong;
    }
    return tong;
}

int main() {
    MatHang ds[100];
    int n;
    
    // a) Nhập danh sách mặt hàng
    NhapDanhSach(ds, n);
    
    // b) Cho tên mặt hàng, tìm và in ra thông tin
    char tenTim[50];
    cout << "\nNhap ten mat hang can tim: ";
    cin.getline(tenTim, 50);
    
    int pos = TimMatHang(ds, n, tenTim);
    if (pos == -1) {
        cout << "Khong co mat hang dang tim\n";
    } else {
        cout << "\nThong tin cua mat hang:\n";
        XuatMatHang(ds[pos]);
    }
    
    // c) Tính tổng số lượng các mặt hàng và in ra
    int tongSoLuong = TinhTongSoLuong(ds, n);
    cout << "\nTong so luong cac mat hang: " << tongSoLuong << "\n";
    
    return 0;
}