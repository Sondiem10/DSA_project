#include <stdio.h>
#include <string.h>

int min(int a, int b) {
    return (a < b) ? a : b;  // Nếu a < b, trả về a, ngược lại trả về b
}

// Hàm tính khoảng cách Levenshtein
int levenshtein_distance(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Tạo một ma trận 2D để lưu trữ các khoảng cách
    int dp[len1 + 1][len2 + 1];

    // Khởi tạo các giá trị của ma trận
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dp[i][j] = j;  // Nếu chuỗi 1 rỗng, khoảng cách là độ dài của chuỗi 2
            }
            else if (j == 0) {
                dp[i][j] = i;  // Nếu chuỗi 2 rỗng, khoảng cách là độ dài của chuỗi 1
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    // Tính toán khoảng cách Levenshtein bằng cách điền vào ma trận
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;  // Nếu ký tự khác nhau, chi phí là 1
            dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + cost);
        }
    }

    return dp[len1][len2];  // Trả về giá trị khoảng cách Levenshtein cuối cùng
}

int main() {
    char str1[100], str2[100];

    printf("Nhập chuỗi thứ nhất: ");
    scanf("%s", str1);

    printf("Nhập chuỗi thứ hai: ");
    scanf("%s", str2);

    // Tính toán khoảng cách Levenshtein giữa hai chuỗi
    int result = levenshtein_distance(str1, str2);

    printf("Khoảng cách Levenshtein giữa '%s' và '%s' là: %d\n", str1, str2, result);

    return 0;
}
