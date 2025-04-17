#include <iostream>
#include <stack>
#include <string>

using namespace std;

// ===================== Nguyên mẫu hàm =====================
class StackInt {
private:
    static const int MAX_SIZE = 100; // Kích thước tối đa
    int arr[MAX_SIZE];               // Mảng lưu dữ liệu
    int top;                         // Vị trí phần tử đầu

public:
    StackInt();                      // Khởi tạo stack
    bool IsEmpty();                   // Kiểm tra rỗng
    bool IsFull();                    // Kiểm tra đầy
    void PushStack(int value);        // Thêm phần tử
    int PopStack();                   // Lấy phần tử ra
    int PeekStack();                  // Xem phần tử đầu
    void Clear();                     // Xóa toàn bộ stack
};

// ===================== Ngăn xếp danh sách liên kết =====================
struct Node {
    int data;
    Node* next;
};

class LinkedStackInt {
private:
    Node* top; // Con trỏ đầu danh sách

public:
    LinkedStackInt();       // Khởi tạo
    bool IsEmpty();         // Kiểm tra rỗng
    void PushStack(int val); // Thêm phần tử
    int PopStack();         // Lấy phần tử ra
    int PeekStack();        // Xem phần tử đầu
    void Clear();           // Xóa toàn bộ stack
};

// ===================== Ứng dụng ngăn xếp =====================
int ReverseNumber(int num);      // Đảo số nguyên
bool IsPalindrome(string str);   // Kiểm tra xâu đối xứng
string DecimalToBinary(int num); // Chuyển thập phân → nhị phân
string InfixToPostfix(string expr); // Chuyển trung tố → hậu tố
int EvaluatePostfix(string expr);   // Tính giá trị hậu tố

// ===================== Hàm main =====================
int main() {
    int num = 12345;
    cout << "So dao nguoc: " << ReverseNumber(num) << endl;

    string str = "madam";
    cout << "Xau \"" << str << "\" doi xung? " << (IsPalindrome(str) ? "Co" : "Khong") << endl;

    int decimal = 42;
    cout << "So nhi phan cua " << decimal << " la: " << DecimalToBinary(decimal) << endl;

    string infix = "3+5*2";
    string postfix = InfixToPostfix(infix);
    cout << "Bieu thuc hau to: " << postfix << endl;
    cout << "Gia tri bieu thuc: " << EvaluatePostfix(postfix) << endl;

    return 0;
}

// ===================== Định nghĩa hàm StackInt =====================
StackInt::StackInt() {
    top = -1; // Khởi tạo rỗng
}

bool StackInt::IsEmpty() {
    return top == -1;
}

bool StackInt::IsFull() {
    return top == MAX_SIZE - 1;
}

void StackInt::PushStack(int value) {
    if (IsFull()) {
        cout << "Stack day!" << endl;
        return;
    }
    arr[++top] = value;
}

int StackInt::PopStack() {
    if (IsEmpty()) {
        cout << "Stack rong!" << endl;
        return -1;
    }
    return arr[top--];
}

int StackInt::PeekStack() {
    if (IsEmpty()) {
        cout << "Stack rong!" << endl;
        return -1;
    }
    return arr[top];
}

void StackInt::Clear() {
    top = -1; // Đặt lại trạng thái rỗng
}

// ===================== Định nghĩa LinkedStackInt =====================
LinkedStackInt::LinkedStackInt() {
    top = nullptr;
}

bool LinkedStackInt::IsEmpty() {
    return top == nullptr;
}

void LinkedStackInt::PushStack(int val) {
    Node* newNode = new Node{val, top};
    top = newNode;
}

int LinkedStackInt::PopStack() {
    if (IsEmpty()) {
        cout << "Stack rong!" << endl;
        return -1;
    }
    int value = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return value;
}

int LinkedStackInt::PeekStack() {
    if (IsEmpty()) {
        cout << "Stack rong!" << endl;
        return -1;
    }
    return top->data;
}

void LinkedStackInt::Clear() {
    while (!IsEmpty()) {
        PopStack();
    }
}

// ===================== Định nghĩa ứng dụng =====================
int ReverseNumber(int num) {
    StackInt stack;
    while (num > 0) {
        stack.PushStack(num % 10);
        num /= 10;
    }

    int reversed = 0;
    while (!stack.IsEmpty()) {
        reversed = reversed * 10 + stack.PopStack();
    }
    return reversed;
}

bool IsPalindrome(string str) {
    stack<char> stack;
    for (char ch : str) {
        stack.push(ch);
    }

    for (char ch : str) {
        if (stack.top() != ch) return false;
        stack.pop();
    }
    return true;
}

string DecimalToBinary(int num) {
    stack<int> stack;
    while (num > 0) {
        stack.push(num % 2);
        num /= 2;
    }

    string binary = "";
    while (!stack.empty()) {
        binary += to_string(stack.top());
        stack.pop();
    }
    return binary;
}

int GetPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string InfixToPostfix(string expr) {
    stack<char> stack;
    string postfix = "";

    for (char ch : expr) {
        if (isdigit(ch)) {
            postfix += ch;
        } else {
            while (!stack.empty() && GetPriority(stack.top()) >= GetPriority(ch)) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}

int EvaluatePostfix(string expr) {
    stack<int> stack;

    for (char ch : expr) {
        if (isdigit(ch)) {
            stack.push(ch - '0');
        } else {
            int val2 = stack.top(); stack.pop();
            int val1 = stack.top(); stack.pop();
            switch (ch) {
                case '+': stack.push(val1 + val2); break;
                case '-': stack.push(val1 - val2); break;
                case '*': stack.push(val1 * val2); break;
                case '/': stack.push(val1 / val2); break;
            }
        }
    }
    return stack.top();
}