#include <iostream>
#include <stack>
using namespace std;

// --- Khung gọi hàm cho Fibonacci ---
struct FibFrame {
    int n;      // Số cần tính fib(n)
    int state;  // 0: cần tính fib(n-1), 1: đã tính fib(n-1), 2: sẵn sàng gộp kết quả
    int ret;    // Lưu fib(n-1)
};

int FibNonRecursive(int n);

// --- Hàm đảo ngược số bằng stack ---
int ReverseNumberStack(int num);

// --- Khung gọi hàm cho Tháp Hà Nội ---
struct HanoiFrame {
    int n;      // Số đĩa cần di chuyển
    char from;  // Cột xuất phát
    char to;    // Cột đích
    char aux;   // Cột trung gian
    int state;  // 0: chưa giải n-1 từ from->aux; 1: đã di chuyển đĩa lớn; 2: chưa giải n-1 từ aux->to
};

void HanoiNonRecursive(int n, char from, char to, char aux);

int main() {
    // Tính Fibonacci không đệ qui
    int nFib = 10;
    cout << "Fibonacci(" << nFib << ") = " << FibNonRecursive(nFib) << endl;
    
    // Đảo ngược số
    int num = 12345;
    cout << "So ban dau: " << num << "\nSo dao nguoc: " << ReverseNumberStack(num) << endl;
    
    // Tháp Hà Nội không đệ qui
    int nHanoi = 3;
    cout << "\nCac buoc di chuyen Thap Ha Noi (voi " << nHanoi << " dia):" << endl;
    HanoiNonRecursive(nHanoi, 'A', 'C', 'B');
    
    return 0;
}

// --- Fibonacci không đệ qui (mô phỏng đệ qui bằng stack) ---
int FibNonRecursive(int n) {
    stack<FibFrame> s;
    s.push({n, 0, 0});
    int result = 0;
    while (!s.empty()) {
        FibFrame top = s.top(); s.pop();
        if (top.n == 0) result = 0;
        else if (top.n == 1) result = 1;
        else if (top.state == 0) {  // Tính fib(n-1)
            top.state = 1; s.push(top);
            s.push({top.n - 1, 0, 0});
            continue;
        } else if (top.state == 1) {  // Đã có fib(n-1), tính fib(n-2)
            top.ret = result;
            top.state = 2; s.push(top);
            s.push({top.n - 2, 0, 0});
            continue;
        } else { // state == 2, kết hợp fib(n-1) và fib(n-2)
            result = top.ret + result;
        }
    }
    return result;
}

// --- Đảo ngược số bằng stack ---
int ReverseNumberStack(int num) {
    stack<int> s;
    while (num > 0) {
        s.push(num % 10);
        num /= 10;
    }
    int rev = 0;
    while (!s.empty()) {
        rev = rev * 10 + s.top();
        s.pop();
    }
    return rev;
}

// --- Tháp Hà Nội không đệ qui (mô phỏng đệ qui bằng stack) ---
void HanoiNonRecursive(int n, char from, char to, char aux) {
    stack<HanoiFrame> s;
    s.push({n, from, to, aux, 0});
    while (!s.empty()) {
        HanoiFrame frame = s.top(); s.pop();
        if (frame.n == 1) {
            cout << "Di chuyen dia 1 tu " << frame.from << " den " << frame.to << endl;
            continue;
        }
        if (frame.state == 0) {  // Chưa giải bài toán con đầu tiên
            frame.state = 1; s.push(frame);
            s.push({frame.n - 1, frame.from, frame.aux, frame.to, 0});
        } else if (frame.state == 1) { // Đã giải xong n-1 từ from->aux
            cout << "Di chuyen dia " << frame.n << " tu " << frame.from << " den " << frame.to << endl;
            frame.state = 2; s.push(frame);
            s.push({frame.n - 1, frame.aux, frame.to, frame.from, 0});
        }
    }
}