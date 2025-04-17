#include <iostream>
#include <queue>

using namespace std;

// ===================== Nguyên mẫu hàm =====================
class QueueInt {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int front, rear, count;

public:
    QueueInt();
    bool IsEmpty();
    bool IsFull();
    void PushQueue(int value);
    int PopQueue(); 
    int PeekQueue();
    void Clear();
};

// ===================== Hàng đợi danh sách liên kết =====================
struct Node {
    int data;
    Node* next;
};

class LinkedQueueInt {
private:
    Node* front;
    Node* rear;

public:
    LinkedQueueInt();
    bool IsEmpty();
    void PushQueue(int value);
    int PopQueue();
    int PeekQueue();
    void Clear();
};

// ===================== Ứng dụng hàng đợi =====================
void ScheduleDanceQueue(queue<string>& queueNam, queue<string>& queueNu);
void RadixSort(int arr[], int n);

// ===================== Hàm main =====================
int main() {
    queue<string> queueNam, queueNu;
    queueNam.push("Anh"); queueNam.push("Bình"); queueNam.push("Châu");
    queueNu.push("Dương"); queueNu.push("Hà");

    ScheduleDanceQueue(queueNam, queueNu);

    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang truoc khi sap xep: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    RadixSort(arr, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}

// ===================== Định nghĩa QueueInt =====================
QueueInt::QueueInt() {
    front = 0;
    rear = -1;
    count = 0;
}

bool QueueInt::IsEmpty() {
    return count == 0;
}

bool QueueInt::IsFull() {
    return count == MAX_SIZE;
}

void QueueInt::PushQueue(int value) {
    if (IsFull()) {
        cout << "Queue day!" << endl;
        return;
    }
    rear = (rear + 1) % MAX_SIZE;
    arr[rear] = value;
    count++;
}

int QueueInt::PopQueue() {
    if (IsEmpty()) {
        cout << "Queue rong!" << endl;
        return -1;
    }
    int value = arr[front];
    front = (front + 1) % MAX_SIZE;
    count--;
    return value;
}

int QueueInt::PeekQueue() {
    if (IsEmpty()) {
        cout << "Queue rong!" << endl;
        return -1;
    }
    return arr[front];
}

void QueueInt::Clear() {
    front = 0;
    rear = -1;
    count = 0;
}

// ===================== Định nghĩa LinkedQueueInt =====================
LinkedQueueInt::LinkedQueueInt() {
    front = rear = nullptr;
}

bool LinkedQueueInt::IsEmpty() {
    return front == nullptr;
}

void LinkedQueueInt::PushQueue(int value) {
    Node* newNode = new Node{value, nullptr};
    if (IsEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int LinkedQueueInt::PopQueue() {
    if (IsEmpty()) {
        cout << "Queue rong!" << endl;
        return -1;
    }
    int value = front->data;
    Node* temp = front;
    front = front->next;
    delete temp;
    if (front == nullptr) rear = nullptr;
    return value;
}

int LinkedQueueInt::PeekQueue() {
    if (IsEmpty()) {
        cout << "Queue rong!" << endl;
        return -1;
    }
    return front->data;
}

void LinkedQueueInt::Clear() {
    while (!IsEmpty()) {
        PopQueue();
    }
}

// ===================== Ứng dụng: Xếp cặp nhảy =====================
void ScheduleDanceQueue(queue<string>& queueNam, queue<string>& queueNu) {
    const int MAX_COUPLES = 4;
    int couples = 0;

    cout << "💃🕺 Danh sach ghep cap:" << endl;
    while (!queueNam.empty() && !queueNu.empty() && couples < MAX_COUPLES) {
        cout << "- " << queueNam.front() << " nhay voi " << queueNu.front() << endl;
        queueNam.pop();
        queueNu.pop();
        couples++;
    }

    if (queueNam.empty() && queueNu.empty()) {
        cout << "✅ Tat ca da co doi!" << endl;
    } else if (!queueNam.empty()) {
        cout << "🕺 " << queueNam.front() << " dang cho!" << endl;
    } else {
        cout << "💃 " << queueNu.front() << " dang cho!" << endl;
    }
}

// ===================== Ứng dụng: Radix Sort =====================
int GetMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    return maxVal;
}

void CountingSort(int arr[], int n, int exp) {
    queue<int> buckets[10]; // Mảng 10 hàng đợi

    // Đưa số vào hàng đợi theo chữ số hàng đơn vị, chục, trăm...
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        buckets[digit].push(arr[i]);
    }

    // Ghép lại mảng sau khi gom vào bucket
    int index = 0;
    for (int i = 0; i < 10; i++) {
        while (!buckets[i].empty()) {
            arr[index++] = buckets[i].front();
            buckets[i].pop();
        }
    }
}

void RadixSort(int arr[], int n) {
    int maxVal = GetMax(arr, n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        CountingSort(arr, n, exp);
    }
}