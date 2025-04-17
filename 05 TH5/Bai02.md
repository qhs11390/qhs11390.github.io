# Bài 2

## Đề bài

Cho cây như hình 1, cho trước nút p.

Hình 1:
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
Hình 2:

```
     10
    /  \
   /    \
  15     5
 /  \   / \
18  12 3   9
 \        /
 20      7
```

Hãy viết các câu lệnh cần thiết để chuyển cây sang dạng biểu diễn của hình 2.

## Bài giải

```
NODE *temp = p->pLeft;
p->pLeft = p->pRight;
p->pRight = temp;
temp = p->pLeft->pLeft;
p->pLeft->pLeft = p->pLeft->pRight;
p->pLeft->pRight = temp;
```