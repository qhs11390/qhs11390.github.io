#include <iostream>
using namespace std;

// Khai báo cấu trúc NhanVien
struct NhanVien {
    char MaSo[11];     // Mã số tối đa 10 ký tự + ký tự kết thúc '\0'
    char Ho[11];       // Họ lót tối đa 10 ký tự
    char Ten[51];      // Tên tối đa 50 ký tự
    int Phai;          // 0: Nữ, 1: Nam
    int ThamNien;      // Số năm làm việc (>=0)
};

// Khai báo cấu trúc PhongBan
struct PhongBan {
    NhanVien aNhanVien[100];  // Mảng chứa tối đa 100 nhân viên
    int SoLuong;              // Số lượng nhân viên hiện có
};

// Hàm nhập thông tin 1 nhân viên
void NhapNhanVien(NhanVien &nv) {
    cout << "Nhap ma so: ";
    cin >> nv.MaSo;
    
    cout << "Nhap ho: ";
    cin >> nv.Ho;
    
    cout << "Nhap ten: ";
    cin >> nv.Ten;
    
    cout << "Nhap phai (0: Nu, 1: Nam): ";
    cin >> nv.Phai;
    while(nv.Phai != 0 && nv.Phai != 1) {
        cout << "Gia tri phai khong hop le. Nhap lai (0: Nu, 1: Nam): ";
        cin >> nv.Phai;
    }
    
    cout << "Nhap so nam lam viec (Tham Nien): ";
    cin >> nv.ThamNien;
    while(nv.ThamNien < 0) {
        cout << "So nam lam viec phai lon hon hoac bang 0. Nhap lai: ";
        cin >> nv.ThamNien;
    }
}

// b) Hàm nhập danh sách các nhân viên cho phòng ban
void NhapPhongBan(PhongBan &pb) {
    cout << "Nhap so luong nhan vien (0 - 100): ";
    cin >> pb.SoLuong;
    while(pb.SoLuong < 0 || pb.SoLuong > 100) {
        cout << "So luong nhan vien phai tu 0 den 100. Nhap lai: ";
        cin >> pb.SoLuong;
    }
    
    for(int i = 0; i < pb.SoLuong; i++) {
        cout << "\nNhap thong tin nhan vien thu " << i+1 << ":\n";
        NhapNhanVien(pb.aNhanVien[i]);
    }
}

// Hàm xuất thông tin của 1 nhân viên
void XuatNhanVien(NhanVien nv) {
    cout << nv.MaSo << "\t" 
         << nv.Ho << "\t" 
         << nv.Ten << "\t" 
         << (nv.Phai == 1 ? "Nam" : "Nu") << "\t" 
         << nv.ThamNien << endl;
}

// c) Hàm xuất thông tin phòng ban ra màn hình
void XuatPhongBan(PhongBan pb) {
    cout << "\nDanh sach nhan vien trong phong ban:\n";
    cout << "MaSo\tHo\tTen\tPhai\tThamNien\n";
    for(int i = 0; i < pb.SoLuong; i++) {
        XuatNhanVien(pb.aNhanVien[i]);
    }
}

// d) Hàm đếm sĩ số nhân viên trong phòng ban
void DemSiSo(PhongBan ds, int &sonam, int &sonu) {
    sonam = 0;
    sonu = 0;
    for(int i = 0; i < ds.SoLuong; i++) {
        if(ds.aNhanVien[i].Phai == 1)
            sonam++;
        else
            sonu++;
    }
}

// e) Hàm sắp xếp danh sách nhân viên tăng dần theo thâm niên
void SapXepTangTheoThamNien(PhongBan &pb) {
    // Sử dụng thuật toán sắp xếp nổi bọt (bubble sort)
    for(int i = 0; i < pb.SoLuong - 1; i++) {
        for(int j = i + 1; j < pb.SoLuong; j++) {
            if(pb.aNhanVien[i].ThamNien > pb.aNhanVien[j].ThamNien) {
                // Hoán đổi nhân viên
                NhanVien temp = pb.aNhanVien[i];
                pb.aNhanVien[i] = pb.aNhanVien[j];
                pb.aNhanVien[j] = temp;
            }
        }
    }
}

// f) Hàm main sử dụng các hàm trên xử lý các yêu cầu đề bài
int main() {
    PhongBan pb;
    
    // Nhập thông tin phòng ban (danh sách nhân viên)
    NhapPhongBan(pb);
    
    // Đếm sĩ số: số lượng nam và nữ
    int soNam, soNu;
    DemSiSo(pb, soNam, soNu);
    cout << "\nSi so nhan vien: Nam = " << soNam << ", Nu = " << soNu << endl;
    
    // Sắp xếp danh sách nhân viên tăng dần theo thâm niên
    SapXepTangTheoThamNien(pb);
    
    // Xuất danh sách nhân viên sau khi sắp xếp
    cout << "\nDanh sach nhan vien sau khi sap xep tang theo tham nien:\n";
    XuatPhongBan(pb);
    
    return 0;
}