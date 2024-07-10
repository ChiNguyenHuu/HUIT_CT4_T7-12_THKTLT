#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char hoTen[100], gioiTinh[10];
    int ngay, thang, nam;
    int namHienTai = 2021;  // Giả sử năm hiện tại là 2021

    // Nhập họ tên
    printf("Nhap ho ten: ");
    fgets(hoTen, sizeof(hoTen), stdin);
    hoTen[strlen(hoTen) - 1] = '\0';  // Xóa ký tự '\n' cuối chuỗi

    // Nhập ngày sinh
    printf("Nhap ngay sinh (ngay thang nam, vi du: 20 03 1990): ");
    scanf("%d %d %d", &ngay, &thang, &nam);

    // Nhập giới tính
    printf("Nhap gioi tinh (nam/nu): ");
    scanf("%s", gioiTinh);

    // Tính tuổi hiện tại
    int tuoi = namHienTai - nam;

    // Kiểm tra điều kiện để tính thời gian nghỉ hưu
    bool valid = true;
    int namNghiHuu;

    if ((strcmp(gioiTinh, "nam") == 0 && (tuoi < 18 || tuoi > 62)) ||
        (strcmp(gioiTinh, "nu") == 0 && (tuoi < 18 || tuoi > 60))) {
        valid = false;
        if (strcmp(gioiTinh, "nam") == 0) {
            printf("Lỗi mã 101: Tuoi nam không hop le (18->62).\n");
        }
        else if (strcmp(gioiTinh, "nu") == 0) {
            printf("Lỗi mã 101: Tuoi nu khong hop le (18->60).\n");
        }
    }
    else if (strcmp(gioiTinh, "nam") != 0 && strcmp(gioiTinh, "nu") != 0) {
        valid = false;
        printf("Loi errcode: Gioi tinh khong hop le (phai la 'nam' hoac 'nu').\n");
    }

    if (valid) {
        if (strcmp(gioiTinh, "nam") == 0) {
            namNghiHuu = nam + 62;
        }
        else if (strcmp(gioiTinh, "nu") == 0) {
            namNghiHuu = nam + 60;
        }

        printf("Thoi gian duoc nghi huu cua %s la thang %02d/%d.\n", hoTen, thang, namNghiHuu);
    }

    return 0;
}
