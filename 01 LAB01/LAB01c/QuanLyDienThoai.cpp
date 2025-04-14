#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100; // Số lượng điện thoại tối đa

// Khai báo cấu trúc DienThoai
struct DienThoai {
    char ma[11];        // Mã điện thoại (tối đa 10 ký tự)
    char nhanHieu[21];   // Nhãn hiệu (tối đa 20 ký tự)
    int gia;             // Giá (số nguyên)
};

// Hàm tìm kiếm điện thoại theo mã
// Trả về vị trí trong mảng nếu tìm thấy, nếu không trả về -1.
int TimDienThoai(DienThoai ds[], int n, const char *ma) {
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].ma, ma) == 0)
            return i;
    }
    return -1;
}

// a) Hàm thêm 1 điện thoại vào danh sách
void ThemDienThoai(DienThoai ds[], int &n) {
    if (n >= MAX) {
        cout << "Danh sach da day, khong the them dien thoai moi!\n";
        return;
    }
    
    DienThoai dt;
    cout << "Nhap ma dien thoai (toi da 10 ky tu): ";
    cin >> dt.ma;
    
    // Kiểm tra xem mã điện thoại đã tồn tại hay chưa
    if (TimDienThoai(ds, n, dt.ma) != -1) {
        cout << "Dien thoai voi ma " << dt.ma << " da ton tai trong danh sach!\n";
        return;
    }
    
    cout << "Nhap nhan hieu (toi da 20 ky tu): ";
    cin.ignore(); // Xóa ký tự newline trong bộ đệm
    cin.getline(dt.nhanHieu, 21);
    
    cout << "Nhap gia: ";
    cin >> dt.gia;
    
    ds[n] = dt;
    n++;
    cout << "Them dien thoai thanh cong!\n";
}

// b) Hàm cho mã điện thoại, in nhãn hiệu và giá của điện thoại đó
void TimVaInThongTin(DienThoai ds[], int n) {
    char ma[11];
    cout << "Nhap ma dien thoai can tim: ";
    cin >> ma;
    int pos = TimDienThoai(ds, n, ma);
    if (pos == -1) {
        cout << "Khong tim thay dien thoai voi ma " << ma << "!\n";
    } else {
        cout << "\nThong tin dien thoai:\n";
        cout << "Ma: " << ds[pos].ma << "\n";
        cout << "Nhan hieu: " << ds[pos].nhanHieu << "\n";
        cout << "Gia: " << ds[pos].gia << "\n";
    }
}

// c) Hàm cập nhật lại giá của điện thoại theo mã
void CapNhatGia(DienThoai ds[], int n) {
    char ma[11];
    cout << "Nhap ma dien thoai can cap nhat gia: ";
    cin >> ma;
    int pos = TimDienThoai(ds, n, ma);
    if (pos == -1) {
        cout << "Khong tim thay dien thoai voi ma " << ma << "!\n";
    } else {
        cout << "Gia hien tai cua dien thoai: " << ds[pos].gia << "\n";
        cout << "Nhap gia moi: ";
        int giaMoi;
        cin >> giaMoi;
        ds[pos].gia = giaMoi;
        cout << "Cap nhat gia thanh cong!\n";
    }
}

// d) Hàm xóa điện thoại theo mã
void XoaDienThoai(DienThoai ds[], int &n) {
    char ma[11];
    cout << "Nhap ma dien thoai can xoa: ";
    cin >> ma;
    int pos = TimDienThoai(ds, n, ma);
    if (pos == -1) {
        cout << "Khong tim thay dien thoai voi ma " << ma << "!\n";
    } else {
        // Dịch chuyển các phần tử sau vị trí pos sang bên trái
        for (int i = pos; i < n - 1; i++) {
            ds[i] = ds[i + 1];
        }
        n--;
        cout << "Xoa dien thoai thanh cong!\n";
    }
}

// e) Hàm xuất tất cả điện thoại trong danh sách
void XuatDanhSach(DienThoai ds[], int n) {
    if (n == 0) {
        cout << "Danh sach rong!\n";
        return;
    }
    
    cout << "\nDanh sach dien thoai:\n";
    cout << "Ma\tNhan hieu\tGia\n";
    for (int i = 0; i < n; i++) {
        cout << ds[i].ma << "\t" << ds[i].nhanHieu << "\t\t" << ds[i].gia << "\n";
    }
}

// f) Hàm hiển thị menu
void Menu() {
    cout << "\n======== MENU QUAN LY DIEN THOAI ========\n";
    cout << "1. Them 1 dien thoai\n";
    cout << "2. Tim va in thong tin dien thoai theo ma\n";
    cout << "3. Cap nhat gia dien thoai\n";
    cout << "4. Xoa dien thoai\n";
    cout << "5. Xuat danh sach dien thoai\n";
    cout << "6. Thoat chuong trinh\n";
    cout << "=========================================\n";
    cout << "Chon chuc nang: ";
}

int main() {
    DienThoai ds[MAX];
    int n = 0;      // Số lượng điện thoại hiện có trong danh sách
    int choice;     // Lựa chọn của người dùng
    
    do {
        Menu();
        cin >> choice;
        switch (choice) {
            case 1:
                ThemDienThoai(ds, n);
                break;
            case 2:
                TimVaInThongTin(ds, n);
                break;
            case 3:
                CapNhatGia(ds, n);
                break;
            case 4:
                XoaDienThoai(ds, n);
                break;
            case 5:
                XuatDanhSach(ds, n);
                break;
            case 6:
                cout << "Thoat chuong trinh. Tam biet!\n";
                break;
            default:
                cout << "Chuc nang khong hop le. Vui long chon lai!\n";
        }
    } while (choice != 6);
    
    return 0;
}