#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} SinhVien;

void hienThiDanhSach(SinhVien sinhVien[], int length) {
    for (int i = 0; i < length; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
               sinhVien[i].id, sinhVien[i].name, sinhVien[i].age, sinhVien[i].phoneNumber);
    }
}

void sapXepSinhVienTheoTen(SinhVien sinhVien[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (strcmp(sinhVien[i].name, sinhVien[j].name) > 0) {
                SinhVien temp = sinhVien[i];
                sinhVien[i] = sinhVien[j];
                sinhVien[j] = temp;
            }
        }
    }
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

    sapXepSinhVienTheoTen(sinhVien, length);

    printf("Danh sach sau khi sap xep:\n");
    hienThiDanhSach(sinhVien, length);

    return 0;
}

