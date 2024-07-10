#include <stdio.h>

int main() {
    int a, b, c;

    // Nhập số nguyên a
    printf("Nhập số nguyên a: ");
    scanf("%d", &a);

    // Nhập số nguyên b
    printf("Nhập số nguyên b: ");
    scanf("%d", &b);

    // Nhập số nguyên c
    printf("Nhập số nguyên c: ");
    scanf("%d", &c);

    // Kiểm tra nếu a bằng b để tránh chia cho 0
    if (a == b) {
        printf("Phép chia không hợp lệ vì a bằng b\n");
    } else {
        float result = (float)c / (a - b);
        printf("Kết quả của %d / (%d - %d) là: %.2f\n", c, a, b, result);
    }

    return 0;
}
