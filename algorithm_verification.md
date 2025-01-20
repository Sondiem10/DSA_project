# Xác minh Giải thuật: Levenshtein Distance (Edit Distance)

## Đề bài

Cho hai chuỗi:

- `A = "distance"`
- `B = "editing"`

Mục tiêu của chúng ta là tính toán **Levenshtein distance** (khoảng cách chỉnh sửa) giữa hai chuỗi này. Levenshtein distance là số phép toán ít nhất (thêm, xóa hoặc thay thế ký tự) cần thực hiện để chuyển đổi chuỗi này thành chuỗi kia.

## Giải thuật

Giải thuật sử dụng **Lập trình động**, nơi chúng ta xây dựng một ma trận `D` có kích thước `(n+1) x (m+1)` để lưu trữ khoảng cách chỉnh sửa giữa các tiền tố của hai chuỗi. Các bước thực hiện như sau:

1. **Khởi tạo**:
   - Gọi `n` là độ dài của chuỗi `A` và `m` là độ dài của chuỗi `B`.
   - Tạo ma trận `D` có kích thước `(n+1) x (m+1)` để lưu trữ khoảng cách chỉnh sửa.
   - Khởi tạo hàng đầu tiên và cột đầu tiên của ma trận:
     - `D[i][0] = i` với `0 ≤ i ≤ n` (đây là chi phí xóa tất cả các ký tự của `A`).
     - `D[0][j] = j` với `0 ≤ j ≤ m` (đây là chi phí thêm tất cả các ký tự của `B`).

2. **Điền ma trận**:
   - Với mỗi ô `D[i][j]` (với `1 ≤ i ≤ n` và `1 ≤ j ≤ m`):
     - Nếu `A[i-1] == B[j-1]`, đặt `D[i][j] = D[i-1][j-1]` (không cần thay đổi ký tự).
     - Ngược lại, đặt `D[i][j]` bằng giá trị nhỏ nhất trong ba phép toán:
       - `D[i-1][j] + 1` (xóa ký tự),
       - `D[i][j-1] + 1` (thêm ký tự),
       - `D[i-1][j-1] + 1` (thay thế ký tự).

3. **Kết quả**:
   - Giá trị `D[n][m]` sẽ là Levenshtein distance giữa hai chuỗi `A` và `B`.

## Tính toán chi tiết cho `A = "distance"` và `B = "editing"`

Bây giờ chúng ta sẽ tính toán khoảng cách Levenshtein giữa hai chuỗi này một cách chi tiết.

### Bước 1: Khởi tạo ma trận

Cho `A = "distance"` và `B = "editing"`. Độ dài của `A` và `B` là:

- `n = 8` (độ dài của "distance")
- `m = 7` (độ dài của "editing")

Ma trận `D` có kích thước `(n+1) x (m+1)` = `9 x 8`.

Khởi tạo ma trận với các giá trị sau:

![Screenshot 2025-01-20 103022](https://github.com/user-attachments/assets/66af8185-99a1-403b-952c-0194981e8e8c)

### Bước 2: Điền ma trận

- Với mỗi ô `D[i][j]`, tính toán giá trị của ô này dựa trên các quy tắc ở trên.
- Nếu ký tự `A[i-1]` và `B[j-1]` giống nhau, thì giá trị của ô này được lấy từ `D[i-1][j-1]`. Nếu không giống nhau, tính giá trị bằng cách lấy giá trị nhỏ nhất trong ba phép toán: thêm ký tự, xóa ký tự, thay thế ký tự.
![Screenshot 2025-01-20 103035](https://github.com/user-attachments/assets/6fe11d38-2544-4283-8216-366238b5a227)
![Screenshot 2025-01-20 103203](https://github.com/user-attachments/assets/2ccecd18-1af3-4caf-8a3d-c559ab427d3a)


### Bước 3: Kết quả

Sau khi điền xong ma trận, khoảng cách Levenshtein giữa `A = "distance"` và `B = "editing"` được tìm thấy ở ô `D[n][m] = D[8][7]`, có giá trị là `5`.

![Screenshot 2025-01-20 103043](https://github.com/user-attachments/assets/1b890218-ac49-4ca9-83e3-32d95762c7e1)

## Kết luận

Khoảng cách Levenshtein giữa hai chuỗi `"distance"` và `"editing"` là **5**. Điều này có nghĩa là cần thực hiện 5 phép toán (thêm, xóa hoặc thay thế ký tự) để chuyển đổi `"distance"` thành `"editing"`.

## Độ phức tạp

- **Độ phức tạp thời gian**: O(n * m), trong đó `n` là độ dài của chuỗi `A` và `m` là độ dài của chuỗi `B`. Điều này bởi vì chúng ta cần điền vào một ma trận có kích thước `(n+1) x (m+1)`.
- **Độ phức tạp không gian**: O(n * m) do việc lưu trữ ma trận `D`.


