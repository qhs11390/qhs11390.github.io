/*
Bài 1. Danh sách liên kết số nguyên
(a) Cài đặt CTDL ListInt dùng để chứa các số nguyên, trong đó:
• Sử dụng danh sách liên kết
• Cài đặt các phép toán: khởi tạo, hủy, thêm phần tử, xóa phần tử,
thêm một danh sách phần tử, xuất danh sách
(b) Viết thành chương trình:
• Nhập 10 số nguyên và đưa vào danh sách
• In danh sách ra màn hình
• Nhập một số k và xóa số k trong danh sách
• In danh sách sau khi xóa phần tử
• Nhập 5 số nguyên vào một danh sách thứ hai
• Thêm danh sách thứ hai vào danh sách thứ nhất
• In danh sách thứ nhất ra màn hình
*/

#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một Node trong danh sách liên kết đơn
struct Node {
    int info;      // Dữ liệu của nút (số nguyên)
    Node* next;    // Con trỏ đến nút kế tiếp
};

// Khởi tạo danh sách rỗng
void init(Node*& head) {
    head = NULL;
}

// Tạo một Node mới với giá trị x
Node* createNode(int x) {
    Node* newNode = new Node;  // Cấp phát bộ nhớ cho nút mới
    newNode->info = x;         // Gán giá trị cho info
    newNode->next = NULL;   // Khởi tạo next bằng NULL
    return newNode;
}

// Thêm phần tử vào cuối danh sách
void insertLast(Node*& head, int x) {
    Node* newNode = createNode(x);
    if (head == NULL) {        // Nếu danh sách rỗng
        head = newNode;
    } else {
        Node* p = head;
        // Duyệt đến nút cuối (nút có next là NULL)
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;        // Nối nút mới vào cuối danh sách
    }
}

// Xuất danh sách ra màn hình
void printList(Node* head) {
    if (head == NULL) {
        cout << "Danh sach rong." << endl;
        return;
    }
    Node* p = head;
    while (p != NULL) {
        cout << p->info << " ";   // In giá trị của nút
        p = p->next;              // Di chuyển sang nút kế tiếp
    }
    cout << endl;
}

// Xóa phần tử có giá trị k trong danh sách (xóa lần xuất hiện đầu tiên)
void deleteValue(Node*& head, int k) {
    if (head == NULL) return;  // Nếu danh sách rỗng, không làm gì
    
    // Nếu nút cần xóa nằm ở đầu danh sách
    if (head->info == k) {
        Node* temp = head;
        head = head->next;        // Cập nhật head cho nút kế tiếp
        delete temp;              // Giải phóng bộ nhớ của nút cũ
        return;
    }
    
    // Duyệt danh sách để tìm nút cần xóa
    Node* p = head;
    while (p->next != NULL && p->next->info != k) {
        p = p->next;
    }
    
    // Nếu tìm thấy nút có giá trị k
    if (p->next != NULL) {
        Node* temp = p->next;
        p->next = temp->next;     // Bỏ qua nút cần xóa
        delete temp;              // Giải phóng bộ nhớ
    }
}

// Thêm một danh sách vào cuối danh sách hiện có (nối danh sách)
void appendList(Node*& list1, Node* list2) {
    if (list1 == NULL) {
        list1 = list2;  // Nếu danh sách đầu tiên rỗng, kết quả là danh sách thứ hai
    } else {
        Node* p = list1;
        while (p->next != NULL) {
            p = p->next;  // Duyệt đến cuối danh sách thứ nhất
        }
        p->next = list2;  // Nối danh sách thứ hai vào cuối danh sách thứ nhất
    }
}

// Hủy danh sách: giải phóng bộ nhớ các Node
void clearList(Node*& head) {
    Node* p;
    while (head != NULL) {
        p = head;
        head = head->next;  // Di chuyển head sang nút tiếp theo
        delete p;           // Giải phóng bộ nhớ của nút đã duyệt
    }
}

int main() {
    Node* list1;  // Danh sách số nguyên thứ nhất
    Node* list2;  // Danh sách số nguyên thứ hai
    init(list1);
    init(list2);
    
    int x, k;
    cout << "Nhap 10 so nguyen:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> x;
        insertLast(list1, x);  // Thêm từng số vào danh sách đầu tiên
    }
    
    cout << "Danh sach 10 so vua nhap: ";
    printList(list1);  // In danh sách số nguyên thứ nhất
    
    cout << "Nhap so k can xoa: ";
    cin >> k;
    deleteValue(list1, k);  // Xóa giá trị k nếu có
    cout << "Danh sach sau khi xoa " << k << ": ";
    printList(list1);       // In danh sách sau khi xóa
    
    cout << "Nhap 5 so nguyen cho danh sach thu 2:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> x;
        insertLast(list2, x);  // Thêm các số vào danh sách thứ hai
    }
    
    // Nối danh sách thứ 2 vào danh sách thứ nhất
    appendList(list1, list2);
    cout << "Danh sach thu nhat sau khi noi danh sach thu hai: ";
    printList(list1);  // In danh sách cuối cùng
    
    // Hủy danh sách để giải phóng bộ nhớ
    clearList(list1);
    
    return 0;
}