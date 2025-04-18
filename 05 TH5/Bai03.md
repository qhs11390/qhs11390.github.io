# Bài 3

## Đề bài

Cho cây nhị phân tìm kiếm như hình vẽ. Hãy cho biết thứ tự các nút thêm vào cây sao cho để có được cấu trúc này? (Giả sử lúc đầu cây rỗng).

```
     10
    /  \
   /    \
  5     15
 / \   /  \
3   9 12  18
   /        \
  7         20
```

Nếu kết quả của phép duyệt cây trên là: 3, 7, 9, 5, 12, 20, 18, 15, 10. Hãy cho biết người ta đã áp dụng phép duyệt nào?

## Bài giải

Thứ tự các nút thêm vào cây để có được cây cấu trúc như trên là:
- Cách 1: 10,  5, 15,  3,  9, 12, 18,  7, 20
- Cách 2: 10,  5,  3,  9,  7, 15, 12, 18, 20
- Cách 3: 10, 15, 18, 20, 12,  5,  9,  7,  3

Phép duyệt cây theo phương pháp LRN cho kết quả: 3, 7, 9, 5, 12, 20, 18, 15, 10