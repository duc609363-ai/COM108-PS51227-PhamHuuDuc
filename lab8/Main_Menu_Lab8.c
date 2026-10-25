#include <stdio.h>
#include <string.h>

struct SinhVien {
    char mssv[50];
    char tenSV[50];
    char nganhHoc[50];
    float diemTB;
};

void xoaXuongDong(char x[]);
void nhapXuatDanhSach(struct SinhVien ds[], int *n);
void sapXepDiemTangDan(struct SinhVien ds[], int n);
void timKiemTheoMSSV(struct SinhVien ds[], int n);
void xuatHocBongTheoNganh(struct SinhVien ds[], int n);
void hienThiSinhVien(struct SinhVien sv, int index);

int main() {
    struct SinhVien ds[50];
    int n = 0;
    int chon;

    do {
        printf("\n+-----------------------------------------------+\n");
        printf("|             MENU CHUONG TRINH LAB 8           |\n");
        printf("+-----------------------------------------------+\n");
        printf("| 1. Nhap va xuat danh sach sinh vien           |\n");
        printf("| 2. Sap xep sinh vien theo diem tang dan       |\n");
        printf("| 3. Tim kiem sinh vien theo MSSV               |\n");
        printf("| 4. Xuat sinh vien nhan hoc bong theo nganh    |\n");
        printf("| 5. Thoat chuong trinh                         |\n");
        printf("+-----------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &chon);
        getchar();

        if ((chon == 2 || chon == 3 || chon == 4) && n == 0) {
            printf("\nThong bao: Danh sach chua co sinh vien nao! Vui long chon chuc nang 1 de nhap lieu truoc.\n");
            continue;
        }

        switch (chon) {
            case 1:
                nhapXuatDanhSach(ds, &n);
                break;
            case 2:
                sapXepDiemTangDan(ds, n);
                break;
            case 3:
                timKiemTheoMSSV(ds, n);
                break;
            case 4:
                xuatHocBongTheoNganh(ds, n);
                break;
            case 5:
                printf("\nCam on ban da su dung chuong trinh. Tam biet!\n");
                break;
            default:
                printf("\nChuc nang khong hop le! Vui long chon lai tu 1 den 5.\n");
        }
    } while (chon != 5);

    return 0;
}

void xoaXuongDong(char x[]) {
    size_t len = strlen(x);
    if (len > 0 && x[len - 1] == '\n') {
        x[len - 1] = '\0';
    }
}

void hienThiSinhVien(struct SinhVien sv, int index) {
    printf("\nSinh vien thu [%d]:\n", index);
    printf("MSSV: %s\n", sv.mssv);
    printf("Ten SV: %s\n", sv.tenSV);
    printf("Nganh hoc: %s\n", sv.nganhHoc);
    printf("Diem TB: %.2f\n", sv.diemTB);
}

void nhapXuatDanhSach(struct SinhVien ds[], int *n) {
    int input_n;
    do {
        printf("Nhap so luong sinh vien (1 - 50): ");
        scanf("%d", &input_n);
        getchar();
        if (input_n <= 0 || input_n > 50) {
            printf("So luong khong hop le! Vui long nhap lai.\n");
        }
    } while (input_n <= 0 || input_n > 50);

    *n = input_n;

    for (int i = 0; i < *n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        
        printf("Nhap MSSV: ");
        fgets(ds[i].mssv, sizeof(ds[i].mssv), stdin);
        xoaXuongDong(ds[i].mssv);

        printf("Nhap Ten SV: ");
        fgets(ds[i].tenSV, sizeof(ds[i].tenSV), stdin);
        xoaXuongDong(ds[i].tenSV);

        printf("Nhap Nganh hoc: ");
        fgets(ds[i].nganhHoc, sizeof(ds[i].nganhHoc), stdin);
        xoaXuongDong(ds[i].nganhHoc);

        do {
            printf("Nhap Diem TB (0.0 - 10.0): ");
            scanf("%f", &ds[i].diemTB);
            getchar();
            if (ds[i].diemTB < 0.0 || ds[i].diemTB > 10.0) {
                printf("Diem khong hop le! Vui long nhap lai.\n");
            }
        } while (ds[i].diemTB < 0.0 || ds[i].diemTB > 10.0);
    }

    printf("\n--- DANH SACH SINH VIEN DA NHAP ---");
    for (int i = 0; i < *n; i++) {
        hienThiSinhVien(ds[i], i);
    }
}

void sapXepDiemTangDan(struct SinhVien ds[], int n) {
    struct SinhVien svTemp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diemTB > ds[j].diemTB) {
                svTemp = ds[i];
                ds[i] = ds[j];
                ds[j] = svTemp;
            }
        }
    }

    printf("\n--- DANH SACH SINH VIEN TANG DAN THEO DIEM ---");
    for (int i = 0; i < n; i++) {
        hienThiSinhVien(ds[i], i);
    }
}

void timKiemTheoMSSV(struct SinhVien ds[], int n) {
    char mssvTim[50];
    printf("\nNhap MSSV can tim: ");
    fgets(mssvTim, sizeof(mssvTim), stdin);
    xoaXuongDong(mssvTim);

    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].mssv, mssvTim) == 0) {
            printf("\nTim thay sinh vien:");
            printf("\nMSSV: %s", ds[i].mssv);
            printf("\nTen SV: %s", ds[i].tenSV);
            printf("\nNganh hoc: %s", ds[i].nganhHoc);
            printf("\nDiem TB: %.2f\n", ds[i].diemTB);
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("\nKhong tim thay sinh vien co MSSV: %s\n", mssvTim);
    }
}

void xuatHocBongTheoNganh(struct SinhVien ds[], int n) {
    int coHocBong = 0;

    for (int i = 0; i < n; i++) {
        if (ds[i].diemTB >= 8.0) {
            coHocBong = 1;
            break;
        }
    }

    if (!coHocBong) {
        printf("\nKhong co sinh vien nao dat hoc bong.\n");
        return;
    }

    printf("\n--- DANH SACH SINH VIEN NHAN HOC BONG THEO NGANH ---");
    
    for (int i = 0; i < n; i++) {
        if (ds[i].diemTB >= 8.0) {
            int nganhDaIn = 0;
            
            for (int j = 0; j < i; j++) {
                if (ds[j].diemTB >= 8.0 && strcmp(ds[i].nganhHoc, ds[j].nganhHoc) == 0) {
                    nganhDaIn = 1;
                    break;
                }
            }

            if (!nganhDaIn) {
                printf("\nNganh: %s", ds[i].nganhHoc);
                
                for (int k = 0; k < n; k++) {
                    if (ds[k].diemTB >= 8.0 && strcmp(ds[k].nganhHoc, ds[i].nganhHoc) == 0) {
                        printf("\n - %s - %s - Diem TB: %.2f", ds[k].mssv, ds[k].tenSV, ds[k].diemTB);
                    }
                }
                printf("\n");
            }
        }
    }
}
