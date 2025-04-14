#include <iostream>
#include <cstring>
using namespace std;

// a) Khai báo cấu trúc LoaiHoa và DanhSachLoaiHoa
struct LoaiHoa {
    char Ten[50];      // Tên loại hoa
    int SoLuong;       // Số lượng hiện có
    char DVT[20];      // Đơn vị tính
    double DonGia;     // Đơn giá
};

struct DanhSachLoaiHoa {
    LoaiHoa aLoaiHoa[20]; // Mảng chứa tối đa 20 loại hoa
    int SoLuong;         // Số lượng loại hoa hiện có
};

// b) Hàm nhập danh sách các loại hoa
void NhapDanhSach(DanhSachLoaiHoa &ds) {
    cout << "Nhap so luong loai hoa (toi da 20): ";
    cin >> ds.SoLuong;
    while(ds.SoLuong < 0 || ds.SoLuong > 20) {
        cout << "So luong loai hoa khong hop le. Nhap lai: ";
        cin >> ds.SoLuong;
    }
    cin.ignore(); // Xóa bộ đệm sau khi nhập số lượng

    for (int i = 0; i < ds.SoLuong; i++) {
        cout << "\nNhap thong tin loai hoa thu " << i + 1 << ":\n";
        cout << "Nhap ten loai hoa: ";
        cin.getline(ds.aLoaiHoa[i].Ten, 50);

        cout << "Nhap so luong: ";
        cin >> ds.aLoaiHoa[i].SoLuong;
        cin.ignore(); // Xóa bộ đệm sau khi nhập số

        cout << "Nhap don vi tinh: ";
        cin.getline(ds.aLoaiHoa[i].DVT, 20);

        cout << "Nhap don gia: ";
        cin >> ds.aLoaiHoa[i].DonGia;
        cin.ignore(); // Xóa bộ đệm sau khi nhập số
    }
}

// c) Hàm xuất danh sách ra màn hình
void XuatDanhSach(DanhSachLoaiHoa ds) {
    cout << "\nDanh sach cac loai hoa:\n";
    cout << "Ten loai hoa\tSo luong\tDon vi tinh\tDon gia\n";
    for (int i = 0; i < ds.SoLuong; i++) {
        cout << ds.aLoaiHoa[i].Ten << "\t\t"
             << ds.aLoaiHoa[i].SoLuong << "\t\t"
             << ds.aLoaiHoa[i].DVT << "\t\t"
             << ds.aLoaiHoa[i].DonGia << "\n";
    }
}

// d) Hàm tìm loại hoa theo tên loại
// Chuyển đổi chuỗi về chữ thường
void ChuyenChuThuong(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}
// Trả về vị trí trong danh sách nếu tìm thấy, nếu không trả về -1
int TimLoaiHoa(DanhSachLoaiHoa ds, char *tenloai) {
    char tenTimKiem[50];
    strcpy(tenTimKiem, tenloai);
    ChuyenChuThuong(tenTimKiem);  // Chuyển tên cần tìm về chữ thường

    for (int i = 0; i < ds.SoLuong; i++) {
        char tenTrongDS[50];
        strcpy(tenTrongDS, ds.aLoaiHoa[i].Ten);
        ChuyenChuThuong(tenTrongDS); // Chuyển tên trong danh sách về chữ thường

        if (strcmp(tenTimKiem, tenTrongDS) == 0)
            return i;
    }
    return -1;
}

// e) Hàm xử lý bán hoa cho khách hàng theo tên loại và số lượng yêu cầu
void XuLyBanHoa(DanhSachLoaiHoa &ds, char *tenloai, int soluong) {
    int pos = TimLoaiHoa(ds, tenloai);
    if (pos == -1) {
        cout << "\nLoai hoa '" << tenloai << "' khong ton tai trong danh sach.\n";
        return;
    }
    
    // Kiểm tra số lượng hiện có
    if (ds.aLoaiHoa[pos].SoLuong < soluong) {
        cout << "\nSo luong hoa hien co khong du de ban.\n";
        return;
    }
    
    // Nếu đủ số lượng, tính tổng tiền
    double tongTien = soluong * ds.aLoaiHoa[pos].DonGia;
    cout << "\nTong tien can thanh toan: " << tongTien << "\n";
    
    // (Tùy chọn) Cập nhật lại số lượng hoa sau khi bán
    ds.aLoaiHoa[pos].SoLuong -= soluong;
}

// f) Hàm main sử dụng các hàm trên để xử lý yêu cầu
int main() {
    DanhSachLoaiHoa ds;
    
    // Nhập danh sách các loại hoa
    NhapDanhSach(ds);
    
    // Xuất danh sách các loại hoa
    XuatDanhSach(ds);
    
    // Nhập thông tin yêu cầu bán hoa của khách hàng
    char tenLoaiCanMua[50];
    int soLuongMua;
    
    cout << "\nNhap ten loai hoa can mua: ";
    cin.getline(tenLoaiCanMua, 50);
    cout << "Nhap so luong can mua: ";
    cin >> soLuongMua;
    
    // Xử lý bán hoa
    XuLyBanHoa(ds, tenLoaiCanMua, soLuongMua);
    
    return 0;
}