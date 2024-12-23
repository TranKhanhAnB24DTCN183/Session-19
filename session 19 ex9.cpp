#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} SinhVien;

// Khai báo nguyên m?u hàm
void hienThiDanhSach(SinhVien sinhVien[], int length);
void themSinhVien(SinhVien sinhVien[], int *length);
void suaThongTinSinhVien(SinhVien sinhVien[], int length);
void xoaSinhVien(SinhVien sinhVien[], int *length);
void timKiemSinhVien(SinhVien sinhVien[], int length);
void sapXepSinhVienTheoTen(SinhVien sinhVien[], int length);

int main() {
    SinhVien sinhVien[100];
    int length = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                hienThiDanhSach(sinhVien, length);
                break;
            case 2:
                themSinhVien(sinhVien, &length);
                break;
            case 3:
                suaThongTinSinhVien(sinhVien, length);
                break;
            case 4:
                xoaSinhVien(sinhVien, &length);
                break;
            case 5:
                timKiemSinhVien(sinhVien, length);
                break;
            case 6:
                sapXepSinhVienTheoTen(sinhVien, length);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 7);

    return 0;
}

// Ð?nh nghia các hàm
void hienThiDanhSach(SinhVien sinhVien[], int length) {
    if (length == 0) {
        printf("Danh sach sinh vien trong.\n");
        return;
    }
    for (int i = 0; i < length; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
               sinhVien[i].id, sinhVien[i].name, sinhVien[i].age, sinhVien[i].phoneNumber);
    }
}

void themSinhVien(SinhVien sinhVien[], int *length) {
    if (*length >= 100) {
        printf("Danh sach sinh vien da day.\n");
        return;
    }
    SinhVien sv;
    printf("Nhap ID: ");
    scanf("%d", &sv.id);
    printf("Nhap ten: ");
    scanf(" %[^\n]", sv.name);
    printf("Nhap tuoi: ");
    scanf("%d", &sv.age);
    printf("Nhap so dien thoai: ");
    scanf(" %[^\n]", sv.phoneNumber);

    sinhVien[*length] = sv;
    (*length)++;
    printf("Them sinh vien thanh cong.\n");
}

void suaThongTinSinhVien(SinhVien sinhVien[], int length) {
    int id, found = 0;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &id);
    for (int i = 0; i < length; i++) {
        if (sinhVien[i].id == id) {
            found = 1;
            printf("Nhap ten moi: ");
            scanf(" %[^\n]", sinhVien[i].name);
            printf("Nhap tuoi moi: ");
            scanf("%d", &sinhVien[i].age);
            printf("Nhap so dien thoai moi: ");
            scanf(" %[^\n]", sinhVien[i].phoneNumber);
            printf("Sua thong tin thanh cong.\n");
            break;
        }
    }
    if (!found) printf("Khong tim thay sinh vien voi ID: %d\n", id);
}

void xoaSinhVien(SinhVien sinhVien[], int *length) {
    int id, index = -1;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);
    for (int i = 0; i < *length; i++) {
        if (sinhVien[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Khong tim thay sinh vien voi ID: %d\n", id);
        return;
    }
    for (int i = index; i < *length - 1; i++) {
        sinhVien[i] = sinhVien[i + 1];
    }
    (*length)--;
    printf("Xoa sinh vien thanh cong.\n");
}

void timKiemSinhVien(SinhVien sinhVien[], int length) {
    int id, found = 0;
    printf("Nhap ID sinh vien can tim: ");
    scanf("%d", &id);
    for (int i = 0; i < length; i++) {
        if (sinhVien[i].id == id) {
            found = 1;
            printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
                   sinhVien[i].id, sinhVien[i].name, sinhVien[i].age, sinhVien[i].phoneNumber);
            break;
        }
    }
    if (!found) printf("Khong tim thay sinh vien voi ID: %d\n", id);
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
    printf("Sap xep danh sach thanh cong.\n");
}

