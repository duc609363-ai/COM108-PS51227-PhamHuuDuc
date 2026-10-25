#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

void bai1_DemNguyenAmPhuAm();
void bai2_DangNhapHeThong();
void bai3_SapXepChuoi();
void bai4_ChuyenThapPhanSangHexa();

int main() {
    int chon;

    do {
        printf("\n+---------------------------------------+\n");
        printf("|        MENU CHUONG TRINH LAB 7        |\n");
        printf("+---------------------------------------+\n");
        printf("| 1. Dem nguyen am va phu am cua chuoi |\n");
        printf("| 2. Dang nhap bang Username va Password |\n");
        printf("| 3. Sap xep chuoi theo thu tu chu cai  |\n");
        printf("| 4. Doi so thap phan sang thap luc phan|\n");
        printf("| 5. Thoat chuong trinh                 |\n");
        printf("+---------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &chon);
        getchar();

        switch(chon) {
            case 1:
                printf("\n--- BAN DA CHON CHUC NANG 1 ---\n");
                bai1_DemNguyenAmPhuAm();
                break;
            case 2:
                printf("\n--- BAN DA CHON CHUC NANG 2 ---\n");
                bai2_DangNhapHeThong();
                break;
            case 3:
                printf("\n--- BAN DA CHON CHUC NANG 3 ---\n");
                bai3_SapXepChuoi();
                break;
            case 4:
                printf("\n--- BAN DA CHON CHUC NANG 4 ---\n");
                bai4_ChuyenThapPhanSangHexa();
                break;
            case 5:
                printf("\nCam on ban da su dung chuong trinh. Tam biet!\n");
                break;
            default:
                printf("\nChuc nang khong hop le! Vui long chon lai tu 1 den 5.\n");
        }
    } while(chon != 5);

    return 0;
}

void bai1_DemNguyenAmPhuAm() {
    char chuoi[100];
    int nguyenAm = 0, phuAm = 0;

    printf("Nhap vao mot chuoi: ");
    fgets(chuoi, sizeof(chuoi), stdin);
 
    chuoi[strcspn(chuoi, "\n")] = '\0';


    for (int i = 0; chuoi[i] != '\0'; i++) {
        char ch = tolower(chuoi[i]);

        if (isalpha(ch)) {

if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                nguyenAm++;
            } else {
                phuAm++;
            }
        }
    }

    printf("Chuoi '%s' co chua: %d nguyen am va %d phu am.\n", chuoi, nguyenAm, phuAm);
}

void bai2_DangNhapHeThong() {
    char user_sys[] = "admin";
    char pass_sys[] = "12345";

    char username[50];
    char password[50];
    int i = 0;
    char ch;

    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Password: ");

    while (1) {
        ch = getch();

        if (ch == '\r' || ch == '\n') {
            password[i] = '\0';
            break;
        } else if (ch == '\b') {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            if (i < sizeof(password) - 1) {
                password[i] = ch;
                i++;
                printf("*");
            }
        }
    }
    printf("\n");

    if (strcmp(username, user_sys) == 0 && strcmp(password, pass_sys) == 0) {
        printf("Dang nhap thanh cong!\n");
    } else {
        printf("Dang nhap that bai!\n");
    }
}

void bai3_SapXepChuoi() {
    char s[5][20];
    char temp[20];

    printf("Nhap vao 5 chuoi bat ky:\n");
    for (int i = 0; i < 5; i++) {
        printf("Chuoi %d: ", i + 1);
        fgets(s[i], sizeof(s[i]), stdin);
        s[i][strcspn(s[i], "\n")] = '\0';
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {

            if (strcmp(s[i], s[j]) > 0) {

                strcpy(temp, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], temp);
            }
        }
    }

printf("\nCac chuoi sau khi sap xep:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", s[i]);
    }
}

void bai4_ChuyenThapPhanSangHexa() {
    long long n;
    printf("Nhap vao mot so nguyen khong am o he thap phan: ");
    scanf("%lld", &n);
    getchar();

    if (n < 0) {
        printf("So nhap vao khong hop le!\n");
        return;
    }

    if (n == 0) {
        printf("So thap luc phan cua 0 la: 0\n");
        return;
    }

    char hexa_digits[] = "0123456789ABCDEF";
    char chuoi_dao[50];
    char chuoi_hexa[50];
    int idx = 0;
    long long goc_n = n;

    while (n > 0) {
        int du = n % 16;
        chuoi_dao[idx] = hexa_digits[du];
        idx++;
        n = n / 16;
    }
    chuoi_dao[idx] = '\0';

    int do_dai = strlen(chuoi_dao);
    int k = 0;
    for (int i = do_dai - 1; i >= 0; i--) {
        chuoi_hexa[k] = chuoi_dao[i];
        k++;
    }
    chuoi_hexa[k] = '\0';

    printf("So thap luc phan cua %lld la: %s\n", goc_n, chuoi_hexa);
}