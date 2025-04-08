#include <iostream>
#include <iomanip> // Để định dạng số với 2 chữ số thập phân
#include <cmath>   // Để sử dụng hàm sqrt
#include <vector>
#include <algorithm>
using namespace std;

void GiaiPTTrungPhuong(double a, double b, double c) {
    cout << fixed << setprecision(2); // Định dạng xuất số với 2 chữ số thập phân
    vector<double> nghiem;

    if (a == 0) {
        // Phương trình bậc hai bx^2 + c = 0
        if (b == 0) {
            if (c == 0) {
                cout << "Phuong trinh co vo so nghiem" << endl;
            } else {
                cout << "Phuong trinh vo nghiem" << endl;
            }
        } else {
            double y = -c / b;
            if (y < 0) {
                cout << "Phuong trinh vo nghiem" << endl;
            } else {
                nghiem.push_back(sqrt(y));
                nghiem.push_back(-sqrt(y));
                cout << "Phuong trinh co 2 nghiem" << endl;
                sort(nghiem.begin(), nghiem.end());
                for (double x : nghiem) cout << x << " ";
                cout << endl;
            }
        }
    } else {
        // Phương trình bậc bốn dạng ax^4 + bx^2 + c = 0
        double delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "Phuong trinh vo nghiem" << endl;
        } else if (delta == 0) {
            double y = -b / (2 * a);
            if (y < 0) {
                cout << "Phuong trinh vo nghiem" << endl;
            } else {
                nghiem.push_back(sqrt(y));
                nghiem.push_back(-sqrt(y));
                if (y == 0) nghiem.pop_back(); // Nghiệm 0 chỉ tính 1 lần
                cout << "Phuong trinh co " << nghiem.size() << " nghiem" << endl;
                sort(nghiem.begin(), nghiem.end());
                for (double x : nghiem) cout << x << " ";
                cout << endl;
            }
        } else {
            double y1 = (-b - sqrt(delta)) / (2 * a);
            double y2 = (-b + sqrt(delta)) / (2 * a);

            if (y1 >= 0) {
                nghiem.push_back(sqrt(y1));
                nghiem.push_back(-sqrt(y1));
            }
            if (y2 >= 0) {
                nghiem.push_back(sqrt(y2));
                nghiem.push_back(-sqrt(y2));
            }

            if (nghiem.empty()) {
                cout << "Phuong trinh vo nghiem" << endl;
            } else {
                cout << "Phuong trinh co " << nghiem.size() << " nghiem" << endl;
                sort(nghiem.begin(), nghiem.end());
                for (double x : nghiem) cout << x << " ";
                cout << endl;
            }
        }
    }
}

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    GiaiPTTrungPhuong(a, b, c);
    return 0;
}