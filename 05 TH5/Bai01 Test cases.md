Quy ước khi mẫu số = 0 thì kết quả trả về `undefined` (hoặc báo lỗi chia 0):

| #   | Mô tả                                  | Cây (level‑order)               | a) avg all      | b) avg (+)      | c) avg (−)      | d) R = sum(+)/sum(−)                    |
|-----|----------------------------------------|---------------------------------|-----------------|-----------------|-----------------|-----------------------------------------|
| 1   | **Cây rỗng**                           | `[]`                            | undefined       | undefined       | undefined       | undefined                               |
| 2   | **Một nút = 0**                        | `0`                             | 0.0             | undefined       | undefined       | undefined                               |
| 3   | **Một nút dương**                      | `5`                             | 5.0             | 5.0             | undefined       | undefined                               |
| 4   | **Một nút âm**                         | `-5`                            | –5.0            | undefined       | –5.0            | 0.0  (0/–5)                             |
| 5   | **Toàn số 0**                          | `0, 0, 0, 0`                    | 0.0             | undefined       | undefined       | undefined                               |
| 6   | **Toàn số dương (balanced)**           | `2, 4, 6, 8, 10, 12, 14`        | 8.0             | 8.0             | undefined       | undefined                               |
| 7   | **Toàn số dương (right‑skewed)**       | `3, null, 6, null, 9, null, 12` | 7.5             | 7.5             | undefined       | undefined                               |
| 8   | **Toàn số âm**                         | `-1, -2, -3, -4, -5`            | –3.0            | undefined       | –3.0            | 0.0  (0/–15)                            |
| 9   | **Hỗn hợp pos/neg (cân bằng)**         | `5, -3, 8, -10, 7, -1, 9`       | ≈ 2.14          | 7.25            | ≈ –4.67         | ≈ –2.07                               |
| 10  | **Hỗn hợp pos/neg/0 (có zero)**        | `0, 2, -3, 0, 5, -1`            | ≈ 0.17          | 3.5             | –2.0            | –1.75                                  |
| 11  | **Trùng giá trị**                      | `2, 2, 2, 2, 2, 2, 2`           | 2.0             | 2.0             | undefined       | undefined                               |
| 12  | **Giá trị lớn (kiểm tra tràn/precision)** | `1e9, -1e9, 1e9, -1e9`        | 0.0             | 1e9             | –1e9            | –1.0                                   |
