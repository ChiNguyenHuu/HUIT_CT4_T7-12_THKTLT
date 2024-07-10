#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

// Khai báo các hàm
void nhapM1C_SoNguyen(int** a, int* n);
void xuatM1C_SoNguyen(int* a, int n);
void timPhanTuLonNhat(int* a, int n, int** maxElementAddress);
void timPhanTuChanLe(int* a, int n, int** maxEvenAddress, int** minOddAddress);
void xoaPhanTuBangKhong(int* a, int* n);
void themPhanTuSauDauTien(int* a, int* n, int x);
bool laSoChinhPhuong(int x);
int tongSoChinhPhuong(int* a, int n);
bool laSoCucDai(int* a, int n, int i);
void xuatSoCucDai(int* a, int n);
void hienThiMenu();

int main()
{
    int* a = NULL, n = 0;
    bool exitMenu = false;
    int choice;

    while (!exitMenu)
    {
        hienThiMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            if (a != NULL)
            {
                free(a); // Giải phóng bộ nhớ cũ trước khi nhập mảng mới
                a = NULL;
            }
            nhapM1C_SoNguyen(&a, &n);
            int* maxElementAddress;
            timPhanTuLonNhat(a, n, &maxElementAddress);
            if (maxElementAddress != NULL)
            {
                printf("Phan tu lon nhat trong mang la %d, tai dia chi: %p\n", *maxElementAddress, (void*)maxElementAddress);
            }
            else
            {
                printf("Mang rong.\n");
            }
            break;
        }
        case 2:
        {
            int* maxEvenAddress, * minOddAddress;
            timPhanTuChanLe(a, n, &maxEvenAddress, &minOddAddress);
            if (maxEvenAddress != NULL)
            {
                printf("Dia chi phan tu chan lon nhat: %p\n", (void*)maxEvenAddress);
            }
            else
            {
                printf("Khong co phan tu chan trong mang.\n");
            }
            if (minOddAddress != NULL)
            {
                printf("Dia chi phan tu le nho nhat: %p\n", (void*)minOddAddress);
            }
            else
            {
                printf("Khong co phan tu le trong mang.\n");
            }
            break;
        }
        case 3:
        {
            xoaPhanTuBangKhong(a, &n);
            printf("Mang sau khi xoa phan tu bang 0:\n");
            xuatM1C_SoNguyen(a, n);
            break;
        }
        case 4:
        {
            int x;
            printf("Nhap gia tri phan tu can them: ");
            scanf("%d", &x);
            themPhanTuSauDauTien(a, &n, x);
            printf("Mang sau khi them phan tu:\n");
            xuatM1C_SoNguyen(a, n);
            break;
        }
        case 5:
        {
            int sum = tongSoChinhPhuong(a, n);
            printf("Tong cac so chinh phuong trong mang la: %d\n", sum);
            break;
        }
        case 6:
        {
            xuatSoCucDai(a, n);
            break;
        }
        case 0:
            exitMenu = true;
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai!\n");
            break;
        }
    }

    if (a != NULL)
    {
        free(a);
        a = NULL;
    }

    return 0;
}

// Hàm nhập mảng một chiều số nguyên
void nhapM1C_SoNguyen(int** a, int* n)
{
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", n);

    *a = (int*)malloc(*n * sizeof(int));  // Cấp phát bộ nhớ cho mảng

    if (*a == NULL)
    {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < *n; i++)
    {
        printf("Phan tu thu %d: ", i);
        scanf("%d", *a + i);
    }
}

// Hàm xuất mảng một chiều số nguyên
void xuatM1C_SoNguyen(int* a, int n)
{
    printf("Cac phan tu cua mang la:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Phan tu thu %d co gia tri %d\n", i, *(a + i));
    }
}

// Hàm tìm phần tử lớn nhất của mảng và địa chỉ của nó thông qua con trỏ mảng
void timPhanTuLonNhat(int* a, int n, int** maxElementAddress)
{
    if (n <= 0)
    {
        *maxElementAddress = NULL;
        return;
    }

    *maxElementAddress = a;
    for (int i = 1; i < n; i++)
    {
        if (*(a + i) > **maxElementAddress)
        {
            *maxElementAddress = a + i;
        }
    }
}

// Hàm tìm phần tử chẵn lớn nhất và phần tử lẻ nhỏ nhất, xuất địa chỉ của chúng
void timPhanTuChanLe(int* a, int n, int** maxEvenAddress, int** minOddAddress)
{
    *maxEvenAddress = NULL;
    *minOddAddress = NULL;
    int maxEven = -1; // Giả sử không có phần tử chẵn âm
    int minOdd = INT_MAX; // Giả sử không có phần tử lẻ dương

    for (int i = 0; i < n; i++)
    {
        if (*(a + i) % 2 == 0) // Phần tử chẵn
        {
            if (*maxEvenAddress == NULL || *(a + i) > **maxEvenAddress)
            {
                *maxEvenAddress = a + i;
            }
        }
        else // Phần tử lẻ
        {
            if (*minOddAddress == NULL || *(a + i) < **minOddAddress)
            {
                *minOddAddress = a + i;
            }
        }
    }
}

// Hàm xóa phần tử có giá trị 0 khỏi mảng
void xoaPhanTuBangKhong(int* a, int* n)
{
    int j = 0;
    for (int i = 0; i < *n; i++)
    {
        if (*(a + i) != 0)
        {
            *(a + j) = *(a + i);
            j++;
        }
    }
    *n = j; // Cập nhật lại kích thước của mảng
}

// Hàm thêm phần tử x vào sau phần tử đầu tiên của mảng
void themPhanTuSauDauTien(int* a, int* n, int x)
{
    // Dời các phần tử sang phải để để chứa phần tử mới
    for (int i = *n - 1; i >= 0; i--)
    {
        *(a + i + 1) = *(a + i);
    }
    *(a + 1) = x; // Thêm phần tử x vào sau phần tử đầu tiên
    (*n)++; // Tăng kích thước của mảng
}

// Hàm kiểm tra số chính phương
bool laSoChinhPhuong(int x)
{
    int sqrtX = sqrt(x);
    return (sqrtX * sqrtX == x);
}

// Hàm tính tổng các phần tử là số chính phương
int tongSoChinhPhuong(int* a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (laSoChinhPhuong(*(a + i)))
        {
            sum += *(a + i);
        }
    }
    return sum;
}

// Hàm kiểm tra số cực đại
bool laSoCucDai(int* a, int n, int i)
{
    if (i > 0 && i < n - 1)
    {
        return (*(a + i) > *(a + i - 1) && *(a + i) > *(a + i + 1));
    }
    else if (i == 0)
    {
        return (*(a + i) > *(a + i + 1));
    }
    else if (i == n - 1)
    {
        return (*(a + i) > *(a + i - 1));
    }
    return false;
}

// Hàm xuất các số cực đại trong mảng
void xuatSoCucDai(int* a, int n)
{
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (laSoCucDai(a, n, i))
        {
            found = true;
            printf("So cuc dai tai vi tri %d: %d\n", i, *(a + i));
        }
    }
    if (!found)
    {
        printf("Khong co so cuc dai trong mang.\n");
    }
}

// Hàm hiển thị menu chức năng
void hienThiMenu()
{
    printf("\n=========== MENU ===========\n");
    printf("1. Tim phan tu lon nhat trong mang va xuat dia chi cua no\n");
    printf("2. Xuat dia chi cua phan tu chan lon nhat va phan tu le nho nhat\n");
    printf("3. Xoa phan tu co gia tri bang 0\n");
    printf("4. Them phan tu sau phan tu dau tien\n");
    printf("5. Tinh tong cac so chinh phuong trong mang\n");
    printf("6. Xuat cac so cuc dai trong mang\n");
    printf("0. Thoat chuong trinh\n");
    printf("Lua chon cua ban: ");
}
