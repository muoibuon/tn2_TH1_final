# Trần Ngô Tiến Đạt - 25112231 - Thực hành 1 - Thí nghiệm 2 
** Minh chứng và code ở trong các folders tương ứng của mỗi bài **
Wokwi:
+ bài 1 vd1 — https://wokwi.com/projects/479600065451741185
+ bài 1 vd2 — https://wokwi.com/projects/479599736893990913
+ bài 1 vd3 — https://wokwi.com/projects/479599641644466177
+ bài 2 — https://wokwi.com/projects/479599906504350721
+ bài 3 — https://wokwi.com/projects/479600785136802817
# Bài 2 · Debounce

| Ngưỡng | 5 ms | **50 ms** | 500 ms |
|---|---:|---:|---:|
| Số lần đếm (73 sườn thô) | 70 | **66** | 34 |

**Ngưỡng chọn: `DEBOUNCE_MS = 50`**

Lý do: nút nảy tối đa ~47 ms, hai lần nhấn nhanh nhất cách nhau ~73 ms → 50 ms lọc hết nảy mà không mất lần nhấn nào (5 ms còn lọt nảy, 500 ms mất gần nửa số lần nhấn).

<img width="2250" height="930" alt="image" src="https://github.com/user-attachments/assets/175cbc8a-9f06-487c-aee9-bd12aa9b4666" />

# Bài 3 · ADC – số liệu THÔ vs ĐÃ LỌC

Biến trở → GPIO 34 (ADC1), LED → GPIO 18 (LEDC). Lọc trung bình trượt N = 8.

| | THÔ | ĐÃ LỌC |
|---|---:|---:|
| Dao động đỉnh–đỉnh khi để yên | 33 | 18 |
| Nhảy trung bình mỗi mẫu | 2,6 | 0,6 |
| Số lần đổi chiều cả phép đo | 212 | 48 |

**Nhận xét:** số thô nhảy loạn dù không chạm biến trở; sau khi lọc số liệu mượt hẳn (nhảy giảm ~4 lần), quay min→max số đo và độ sáng LED đổi đơn điệu, không giật ngược (đổi lại trễ ~160 ms).

<img width="2250" height="900" alt="image" src="https://github.com/user-attachments/assets/697c9bf5-131f-489f-abbd-6cb6ecb5006b" />


