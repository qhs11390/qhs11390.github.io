// Cho một cây nhị phân có nút gốc là Root, trong đó mỗi nút chứa một số nguyên. Hãy: 
// a) Viết chương trình tính trung bình cộng các nút trong cây.
// b) Viết chương trình tính trung bình cộng các số dương trong cây.
// c) Viết chương trình tính trung bình cộng các số âm trong cây.
// d) Viết chương trình tính tỉ số R = a/b, với a là tổng các nút có giá trị dương và b là tổng các nút có giá trị âm.

#include <iostream>
#include <cmath>
using namespace std;

// Định nghĩa cấu trúc Node
struct Node {
    int info;
    Node* left;
    Node* right;
};
using TREE = Node*;

// Hàm khởi tạo node
Node* CreateNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

// Hàm thêm node vào cây nhị phân tìm kiếm
bool InsertNode(TREE& t, int x) {
    if (t == NULL) {
        t = CreateNode(x);
        return true;
    }
    if (x == t->info) return false; // tránh trùng
    if (x < t->info) return InsertNode(t->left, x);
    else return InsertNode(t->right, x);
}

// a) Trung bình cộng tất cả các nút
int DemNode(TREE root) {
    if (root == NULL) return 0;
    return 1 + DemNode(root->left) + DemNode(root->right);
}

int TongNode(TREE root) {
    if (root == NULL) return 0;
    return root->info + TongNode(root->left) + TongNode(root->right);
}

float TrungBinhCong(TREE root) {
    int dem = DemNode(root);
    if (dem == 0) return 0;  // giá trị này sẽ không dùng trực tiếp
    int tong = TongNode(root);
    return static_cast<float>(tong) / dem;
}

// b) Trung bình cộng số dương
int DemDuong(TREE root) {
    if (root == NULL) return 0;
    int dem = DemDuong(root->left) + DemDuong(root->right);
    if (root->info > 0) dem++;
    return dem;
}

int TongDuong(TREE root) {
    if (root == NULL) return 0;
    int tong = TongDuong(root->left) + TongDuong(root->right);
    if (root->info > 0) tong += root->info;
    return tong;
}

float TrungBinhDuong(TREE root) {
    int dem = DemDuong(root);
    if (dem == 0) return 0;
    int tong = TongDuong(root);
    return static_cast<float>(tong) / dem;
}

// c) Trung bình cộng số âm
int DemAm(TREE root) {
    if (root == NULL) return 0;
    int dem = DemAm(root->left) + DemAm(root->right);
    if (root->info < 0) dem++;
    return dem;
}

int TongAm(TREE root) {
    if (root == NULL) return 0;
    int tong = TongAm(root->left) + TongAm(root->right);
    if (root->info < 0) tong += root->info;
    return tong;
}

float TrungBinhAm(TREE root) {
    int dem = DemAm(root);
    if (dem == 0) return 0;
    int tong = TongAm(root);
    return static_cast<float>(tong) / dem;
}

// Hàm duyệt NLR (in cây)
void NLR(TREE t) {
    if (t == NULL) return;
    cout << t->info << " ";
    NLR(t->left);
    NLR(t->right);
}

int main() {
    TREE root = NULL;

    // Dữ liệu mẫu
    int a[] = {5, -3, 7, -1, 0, 4, -6, 8, 2};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; ++i)
        InsertNode(root, a[i]);

    cout << "Cay NLR: ";
    NLR(root);
    cout << "\n\n";

    // a) avg all
    int nAll = DemNode(root);
    cout << "a) avg all: ";
    if (nAll == 0) cout << "undefined\n";
    else          cout << TrungBinhCong(root) << "\n";

    // b) avg (+)
    int nPos = DemDuong(root);
    cout << "b) avg (+): ";
    if (nPos == 0) cout << "undefined\n";
    else           cout << TrungBinhDuong(root) << "\n";

    // c) avg (-)
    int nNeg = DemAm(root);
    cout << "c) avg (-): ";
    if (nNeg == 0) cout << "undefined\n";
    else           cout << TrungBinhAm(root) << "\n";

    // d) R = sum(+)/sum(-)
    int sumPos = TongDuong(root);
    int sumNeg = TongAm(root);
    cout << "d) R = sum(+)/sum(-): ";
    if (sumNeg == 0) cout << "undefined\n";
    else {
        float R = static_cast<float>(sumPos) / sumNeg;
        if (R == 0.0f) R = 0.0f; // tránh -0.0
        cout << R << "\n";
    }

    return 0;
}