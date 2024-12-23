#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} SinhVien;

void hienThiDanhSach(SinhVien sinhVien[], int length) {
    for (int i = 0; i < currentLength; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
            sinhVien[i].id, sinhVien[i].name, sinhVien[i].age, sinhVien[i].phoneNumber);
    }
}

void xoaSinhVien(SinhVien sinhVien[], int *length, int id) {
    int index = -1;
    for (int i = 0; i < *length; i++) {
        if (sinhVien[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Khong tim thay sinh vien co ID: %d\n", id);
        return;
    }
    for (int i = index; i < *length - 1; i++) {
        sinhVien[i] = sinhVien[i + 1];
    }
    (*length)--;
}

int main() {
    SinhVien sinhVien[5] = {
        {1, "Tran Khanh An", 18, "0123456789"},
        {2, "Vi Trung Qui", 21, "0987654321"},
        {3, "Trinh Cao Nhat Nam", 18, "0123456788"},
        {4, "Pham Ngoc Linh", 18, "0987654320"},
        {5, "Tran Huu Khang", 18, "0123456787"}
    };
    int length = 5;

    printf("Danh sach ban dau:\n");
    hienThiDanhSach(sinhVien, length);

    int xoa;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &xoa);
    xoaSinhVien(sinhVien, &length, xoa);

    printf("Danh sach sau khi xoa:\n");
    hienThiDanhSach(sinhVien, length);

    return 0;
}

