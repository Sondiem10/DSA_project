#include <stdio.h>
#include <string.h>

// Hàm tính toán Levenshtein Distance
int EditDistance(char* A, char* B, int n, int m) {
    int D[n+1][m+1]; // Ma trận lưu trữ các giá trị khoảng cách

    // Khởi tạo các giá trị ban đầu
    for (int i = 0; i <= n; i++) {
        D[i][0] = i; // Đặt D(i, 0) = i (Xóa tất cả các ký tự từ A)
    }

    for (int j = 0; j <= m; j++) {
        D[0][j] = j; // Đặt D(0, j) = j (Thêm tất cả các ký tự từ B)
    }

    // Tính toán các giá trị trong ma trận D
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int insertion = D[i][j-1] + 1; // Thêm ký tự
            int deletion = D[i-1][j] + 1;  // Xóa ký tự
            int match = D[i-1][j-1];       // Trường hợp khớp (A[i-1] = B[j-1])
            int mismatch = D[i-1][j-1] + 1; // Trường hợp không khớp (A[i-1] != B[j-1])

            if (A[i-1] == B[j-1]) {
                D[i][j] = (insertion < deletion) ? (insertion < match ? insertion : match)
                                                   : (deletion < match ? deletion : match);
            } else {
                D[i][j] = (insertion < deletion) ? (insertion < mismatch ? insertion : mismatch)
                                                   : (deletion < mismatch ? deletion : mismatch);
            }
        }
    }

    // Trả về giá trị D(n, m) là Levenshtein Distance
    return D[n][m];
}

int main() {
    char A[] = "kitten"; // Chuỗi A
    char B[] = "sitting"; // Chuỗi B

    int n = strlen(A);
    int m = strlen(B);

    // Tính toán Levenshtein Distance giữa A và B
    int distance = EditDistance(A, B, n, m);

    // In kết quả
    printf("Levenshtein Distance between '%s' and '%s' is: %d\n", A, B, distance);

    return 0;
}
