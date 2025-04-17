#include <iostream>
#include <queue>
#include <stack>
using namespace std;

const int MAX = 105; // Giới hạn tối đa của số dòng và cột

// Cấu trúc lưu tọa độ của một ô trong mê cung
struct Cell {
    int r, c;
};

// --- Hàm BFS: tìm đường đi ngắn nhất bằng hàng đợi ---
// parent lưu ô cha để truy vết đường đi
bool bfsMaze(int N, int M, int startX, int startY, int endX, int endY,
             int maze[][MAX], Cell parent[][MAX]) {
    bool visited[MAX][MAX] = {false};
    queue<Cell> q;
    int dr[4] = {-1, 1, 0, 0}; // Di chuyển: lên, xuống, trái, phải
    int dc[4] = {0, 0, -1, 1};
    
    q.push({startX, startY});
    visited[startX][startY] = true;
    parent[startX][startY] = {-1, -1}; // Điểm gốc không có cha
    
    while (!q.empty()) {
        Cell cur = q.front();
        q.pop();
        if (cur.r == endX && cur.c == endY)
            return true;
        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i], nc = cur.c + dc[i];
            // Kiểm tra biên, chướng ngại và ô đã thăm
            if (nr >= 1 && nr <= N && nc >= 1 && nc <= M &&
                maze[nr][nc] == 0 && !visited[nr][nc]) {
                visited[nr][nc] = true;
                parent[nr][nc] = cur;
                q.push({nr, nc});
            }
        }
    }
    return false;
}

// --- Hàm DFS: tìm đường đi (không đảm bảo ngắn nhất) dùng ngăn xếp ---
bool dfsMaze(int N, int M, int startX, int startY, int endX, int endY,
             int maze[][MAX], Cell parent[][MAX]) {
    bool visited[MAX][MAX] = {false};
    stack<Cell> st;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    
    st.push({startX, startY});
    visited[startX][startY] = true;
    parent[startX][startY] = {-1, -1};
    
    while (!st.empty()) {
        Cell cur = st.top();
        st.pop();
        if (cur.r == endX && cur.c == endY)
            return true;
        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i], nc = cur.c + dc[i];
            if (nr >= 1 && nr <= N && nc >= 1 && nc <= M &&
                maze[nr][nc] == 0 && !visited[nr][nc]) {
                visited[nr][nc] = true;
                parent[nr][nc] = cur;
                st.push({nr, nc});
            }
        }
    }
    return false;
}

int main() {
    int N, M, startX, startY, endX, endY;
    // Đọc dữ liệu: N dòng, M cột, tọa độ xuất phát và đích
    cin >> N >> M >> startX >> startY >> endX >> endY;
    int maze[MAX][MAX];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> maze[i][j];
        }
    }
    
    // Chọn thuật toán: true -> BFS, false -> DFS
    bool useBFS = true;
    Cell parent[MAX][MAX];
    bool found = false;
    if (useBFS)
        found = bfsMaze(N, M, startX, startY, endX, endY, maze, parent);
    else
        found = dfsMaze(N, M, startX, startY, endX, endY, maze, parent);
    
    if (!found) {
        cout << "0" << endl; // Không tìm thấy lộ trình
    } else {
        // Truy vết đường đi từ đích về gốc
        Cell path[MAX * MAX];
        int count = 0;
        int r = endX, c = endY;
        while (!(r == -1 && c == -1)) {
            path[count++] = {r, c};
            Cell par = parent[r][c];
            r = par.r; c = par.c;
        }
        // In kết quả theo thứ tự từ điểm xuất phát đến đích
        cout << count << endl;
        for (int i = count - 1; i >= 0; i--) {
            cout << path[i].r << " " << path[i].c << endl;
        }
    }
    return 0;
}