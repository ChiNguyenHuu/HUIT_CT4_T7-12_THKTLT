#include <stdio.h>
#include <stdlib.h>

// Cấu trúc phân số
typedef struct {
    int tuso;
    int mauso;
} PhanSo;

// Khai báo các hàm
void nhapPhanSo(PhanSo* ps);
void xuatPhanSo(PhanSo ps);
void xuatPhanSoMauLonHonTuso(PhanSo* ps, int n);
int demPhanSoChan(PhanSo* ps, int n);
void rutGonPhanSo(PhanSo* ps);
PhanSo tinhTichMangPhanSo(PhanSo* ps, int n);
PhanSo timPhanSoLonNhat(PhanSo* ps, int n);
void hienThiMenu();

int main() {
    int n;
    printf("Nhap so luong phan so: ");
    scanf("%d", &n);

    PhanSo* mangPhanSo = (PhanSo*)malloc(n * sizeof(PhanSo));
    if (mangPhanSo == NULL) {
        printf("Loi cap phat bo nho!\n");
        return 1;
    }

    int choice;
    do {
        hienThiMenu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            for (int i = 0; i < n; i++) {
                printf("Nhap phan so thu %d:\n", i + 1);
                nhapPhanSo(&mangPhanSo[i]);
            }
            break;
        case 2:
            for (int i = 0; i < n; i++) {
                printf("Phan so thu %d: ", i + 1);
                xuatPhanSo(mangPhanSo[i]);
            }
            break;
        case 3:
            xuatPhanSoMauLonHonTuso(mangPhanSo, n);
            break;
        case 4:
            printf("So luong phan so co ca tu so va mau so chan: %d\n", demPhanSoChan(mangPhanSo, n));
            break;
        case 5:
            for (int i = 0; i < n; i++) {
                rutGonPhanSo(&mangPhanSo[i]);
            }
            printf("Da rut gon cac phan so trong mang.\n");
            break;
        case 6:
        {
            PhanSo tich = tinhTichMangPhanSo(mangPhanSo, n);
            printf("Tich cac phan so trong mang la: ");
            xuatPhanSo(tich);
        }
        break;
        case 7:
        {
            PhanSo maxPhanSo = timPhanSoLonNhat(mangPhanSo, n);
            printf("Phan so lon nhat trong mang la: ");
            xuatPhanSo(maxPhanSo);
        }
        break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai!\n");
            break;
        }
    } while (choice != 0);

    free(mangPhanSo);
    return 0;
}

// Hàm nhập phân số
void nhapPhanSo(PhanSo* ps) {
    do {
        printf("Nhap tu so: ");
        scanf("%d", &ps->tuso);
        printf("Nhap mau so (khac 0): ");
        scanf("%d", &ps->mauso);
        if (ps->mauso == 0) {
            printf("Mau so phai khac 0. Vui long nhap lai.\n");
        }
    } while (ps->mauso == 0);
}

// Hàm xuất phân số
void xuatPhanSo(PhanSo ps) {
    printf("%d/%d\n", ps.tuso, ps.mauso);
}

// Hàm xuất các phân số có mẫu số lớn hơn tử số
void xuatPhanSoMauLonHonTuso(PhanSo* ps, int n) {
    printf("Cac phan so co mau lon hon tu so:\n");
    for (int i = 0; i < n; i++) {
        if (ps[i].mauso > ps[i].tuso) {
            xuatPhanSo(ps[i]);
        }
    }
}

// Hàm đếm số phân số có cả tử và mẫu chẵn
int demPhanSoChan(PhanSo* ps, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ps[i].tuso % 2 == 0 && ps[i].mauso % 2 == 0) {
            count++;
        }
    }
    return count;
}

// Hàm tìm ước chung lớn nhất của 2 số
int ucln(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Hàm rút gọn phân số
void rutGonPhanSo(PhanSo* ps) {
    int u = ucln(ps->tuso, ps->mauso);
    ps->tuso /= u;
    ps->mauso /= u;
}

// Hàm tính tích các phân số trong mảng
PhanSo tinhTichMangPhanSo(PhanSo* ps, int n) {
    PhanSo tich = { 1, 1 };
    for (int i = 0; i < n; i++) {
        tich.tuso *= ps[i].tuso;
        tich.mauso *= ps[i].mauso;
        rutGonPhanSo(&tich);
    }
    return tich;
}

// Hàm tìm phân số lớn nhất trong mảng
PhanSo timPhanSoLonNhat(PhanSo* ps, int n) {
    PhanSo maxPhanSo = ps[0];
    for (int i = 1; i < n; i++) {
        if ((float)ps[i].tuso / ps[i].mauso > (float) maxPhanSo.tuso / maxPhanSo.mauso) {
            maxPhanSo = ps[i];
        }
    }
    return maxPhanSo;
}

// Hàm hiển thị menu chức năng
void hienThiMenu() {
    printf("\n=========== MENU ===========\n");
    printf("1. Nhap mang phan so\n");
    printf("2. Xuat mang phan so\n");
    printf("3. Xuat cac phan so co mau lon hon tu so\n");
    printf("4. Dem so phan so co tu so va mau so chan\n");
    printf("5. Rut gon cac phan so trong mang\n");
    printf("6. Tinh tich cac phan so trong mang\n");
    printf("7. Tim phan so lon nhat trong mang\n");
    printf("0. Thoat chuong trinh\n");
    printf("Lua chon cua ban: ");
}
