# Bài 2 · Debounce

| Ngưỡng | 5 ms | **50 ms** | 500 ms |
|---|---:|---:|---:|
| Số lần đếm (73 sườn thô) | 70 | **66** | 34 |

**Ngưỡng chọn: `DEBOUNCE_MS = 50`**

Lý do: nút nảy tối đa ~47 ms, hai lần nhấn nhanh nhất cách nhau ~73 ms → 50 ms lọc hết nảy mà không mất lần nhấn nào (5 ms còn lọt nảy, 500 ms mất gần nửa số lần nhấn).

![So sánh 3 ngưỡng](minh_chung/debounce_so_sanh_nguong.png)
