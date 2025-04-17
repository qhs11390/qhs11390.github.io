/*
Bài 2. Danh sách liên kết sinh viên
(a) Cài đặt CTDL SinhVien để quản lý một sinh viên gồm có:
họ tên (50 ký tự), địa chỉ (70 ký tự), lớp (10 ký tự),
khóa (số nguyên). Cài đặt 4 hàm so sánh 2 sinh viên theo từng tiêu chí.
Viết hàm nhập một sinh viên, hàm xuất một sinh viên.
(b) Cài đặt CTDL ListSV dùng để chứa các sinh viên, trong đó:
• Sử dụng danh sách liên kết
• Cài đặt các phép toán: khởi tạo, hủy, thêm phần tử, xóa phần tử,
thêm một danh sách phần tử, xuất danh sách, sắp
xếp danh sách sử dụng selection sort và con trỏ hàm so sánh.
(c) Viết thành chương trình:
• Nhập 10 sinh viên và đưa vào danh sách
• In danh sách ra màn hình
• Xóa sinh viên có tên “Nguyen Van Teo” trong danh sách
• Xóa sinh viên có địa chỉ “Nguyen Van Cu” trong danh sách
• Thêm sinh viên có tên “Tran Thi Mo”, địa chỉ “25 Hong Bang”,
lớp “TT0901”, khóa 2009 vào danh sách.
• In danh sách ra màn hình
*/

#include <iostream>
#include <cstring>
using namespace std;

// --- Định nghĩa kiểu dữ liệu SinhVien ---
struct SinhVien {
    char hoTen[51];
    char diaChi[71];
    char lop[11];
    int khoa;
};

void nhapSV(SinhVien &sv) {
    cout << "Nhap ho ten: ";
    cin.ignore(); // Xóa ký tự newline còn sót
    cin.getline(sv.hoTen, 51);
    
    cout << "Nhap dia chi: ";
    cin.getline(sv.diaChi, 71);
    
    cout << "Nhap lop: ";
    cin.getline(sv.lop, 11);
    
    cout << "Nhap khoa: ";
    cin >> sv.khoa;
}

void xuatSV(const SinhVien &sv) {
    cout << "Ho ten: " << sv.hoTen << "\n";
    cout << "Dia chi: " << sv.diaChi << "\n";
    cout << "Lop: " << sv.lop << "\n";
    cout << "Khoa: " << sv.khoa << "\n";
}

// Các hàm so sánh sinh viên theo tiêu chí
int cmpTheoHoTen(const SinhVien *sv1, const SinhVien *sv2) {
    return strcmp(sv1->hoTen, sv2->hoTen);
}

int cmpTheoDiaChi(const SinhVien *sv1, const SinhVien *sv2) {
    return strcmp(sv1->diaChi, sv2->diaChi);
}

int cmpTheoLop(const SinhVien *sv1, const SinhVien *sv2) {
    return strcmp(sv1->lop, sv2->lop);
}

int cmpTheoKhoa(const SinhVien *sv1, const SinhVien *sv2) {
    return sv1->khoa - sv2->khoa;
}

// --- Định nghĩa danh sách liên kết sinh viên ---
struct NodeSV {
    SinhVien data;
    NodeSV* next;
};

// Khởi tạo danh sách rỗng
void initList(NodeSV*& head) {
    head = NULL;
}

// Tạo một Node mới chứa SinhVien
NodeSV* createNodeSV(const SinhVien &sv) {
    NodeSV* newNode = new NodeSV;
    newNode->data = sv;
    newNode->next = NULL;
    return newNode;
}

// Thêm sinh viên vào cuối danh sách
void insertLast(NodeSV*& head, const SinhVien &sv) {
    NodeSV* newNode = createNodeSV(sv);
    if (head == NULL) {
        head = newNode;
    } else {
        NodeSV* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
    }
}

// Xuất danh sách sinh viên
void printListSV(NodeSV* head) {
    if (head == NULL) {
        cout << "Danh sach rong." << endl;
        return;
    }
    NodeSV* p = head;
    while (p != NULL) {
        xuatSV(p->data);
        cout << "--------------------------" << endl;
        p = p->next;
    }
}

// Xóa sinh viên có tên trùng với "ten"
void deleteSVByName(NodeSV*& head, const char* ten) {
    // Xóa các nút đầu tiên nếu trùng
    while (head != NULL && strcmp(head->data.hoTen, ten) == 0) {
        NodeSV* temp = head;
        head = head->next;
        delete temp;
    }
    if (head == NULL) return;
    NodeSV* p = head;
    while (p->next != NULL) {
        if (strcmp(p->next->data.hoTen, ten) == 0) {
            NodeSV* temp = p->next;
            p->next = temp->next;
            delete temp;
        } else {
            p = p->next;
        }
    }
}

// Xóa sinh viên có địa chỉ trùng với "diaChi"
void deleteSVByAddress(NodeSV*& head, const char* diaChi) {
    while (head != NULL && strcmp(head->data.diaChi, diaChi) == 0) {
        NodeSV* temp = head;
        head = head->next;
        delete temp;
    }
    if (head == NULL) return;
    NodeSV* p = head;
    while (p->next != NULL) {
        if (strcmp(p->next->data.diaChi, diaChi) == 0) {
            NodeSV* temp = p->next;
            p->next = temp->next;
            delete temp;
        } else {
            p = p->next;
        }
    }
}

// Nối danh sách thứ 2 vào danh sách thứ 1
void appendListSV(NodeSV*& list1, NodeSV* list2) {
    if (list1 == NULL) {
        list1 = list2;
    } else {
        NodeSV* p = list1;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = list2;
    }
}

// Sắp xếp danh sách sinh viên theo tiêu chí sử dụng Selection Sort
// cmp là hàm so sánh nhận 2 con trỏ SinhVien
void selectionSortSV(NodeSV* head, int (*cmp)(const SinhVien*, const SinhVien*)) {
    for (NodeSV* p = head; p != NULL; p = p->next) {
        NodeSV* minNode = p;
        for (NodeSV* q = p->next; q != NULL; q = q->next) {
            if (cmp(&q->data, &minNode->data) < 0) {
                minNode = q;
            }
        }
        if (minNode != p) {
            SinhVien temp = p->data;
            p->data = minNode->data;
            minNode->data = temp;
        }
    }
}

// Hủy danh sách sinh viên
void clearListSV(NodeSV*& head) {
    NodeSV* p;
    while (head != NULL) {
        p = head;
        head = head->next;
        delete p;
    }
}

// --- Chương trình chính ---
int main() {
    NodeSV* listSV;
    initList(listSV);
    
    SinhVien sv;
    cout << "Nhap thong tin 10 sinh vien:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Sinh vien thu " << i+1 << ":" << endl;
        nhapSV(sv);
        insertLast(listSV, sv);
    }
    
    cout << "\nDanh sach sinh vien vua nhap:" << endl;
    printListSV(listSV);
    
    // Xóa sinh viên có tên "Nguyen Van Teo"
    deleteSVByName(listSV, "Nguyen Van Teo");
    // Xóa sinh viên có địa chỉ "Nguyen Van Cu"
    deleteSVByAddress(listSV, "Nguyen Van Cu");
    
    // Thêm sinh viên có thông tin cố định vào danh sách
    SinhVien svMoi;
    strcpy(svMoi.hoTen, "Tran Thi Mo");
    strcpy(svMoi.diaChi, "25 Hong Bang");
    strcpy(svMoi.lop, "TT0901");
    svMoi.khoa = 2009;
    insertLast(listSV, svMoi);
    
    // Có thể sắp xếp lại danh sách theo một tiêu chí nếu cần,
    // Ví dụ sắp xếp theo họ tên:
    selectionSortSV(listSV, cmpTheoHoTen);
    
    cout << "\nDanh sach sinh vien sau cac thao tac:" << endl;
    printListSV(listSV);
    
    clearListSV(listSV);
    return 0;
}