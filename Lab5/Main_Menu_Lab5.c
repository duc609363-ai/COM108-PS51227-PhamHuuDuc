#include <stdio.h>
#include <math.h>

int findMax(int a, int b, int c) {
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

void chucnang1(void) {
    int num1, num2, num3;
    printf("Nhap so thu nhat: ");
    scanf("%d", &num1);
    printf("Nhap so thu hai: ");
    scanf("%d", &num2);
    printf("Nhap so thu ba: ");
    scanf("%d", &num3);

    int max_val = findMax(num1, num2, num3);
    
    printf("Gia tri lon nhat trong 3 so la: %d\n", max_val);
}

int checkYear(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        return 1;
    }
    return 0;
}

void chucnang2(void) {
    int year;
    printf("Nhap nam: ");
    scanf("%d", &year);

    if (checkYear(year) == 1) {
        printf("Nam %d la nam nhuan.\n", year);
    } else {
        printf("Nam %d khong phai la nam nhuan.\n", year);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void chucnang3(void) {
    int x, y;
    printf("Nhap gia tri a: ");
    scanf("%d", &x);
    printf("Nhap gia tri b: ");
    scanf("%d", &y);

    printf("Truoc khi hoan vi: a = %d, b = %d\n", x, y);

    swap(&x, &y);

    printf("Sau khi hoan vi: a = %d, b = %d\n", x, y);
}

void checkTriangle(float a, float b, float c) {
    if (a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a)) {
        
        int isVuong = (fabs(a*a + b*b - c*c) < 0.01) || 
                      (fabs(a*a + c*c - b*b) < 0.01) || 
                      (fabs(b*b + c*c - a*a) < 0.01);
                      
        int isCan = (a == b) || (a == c) || (b == c);
        int isDeu = (a == b && b == c);

        if (isDeu) {
            printf("Day la tam giac deu.\n");
        } else if (isVuong && isCan) {
            printf("Day la tam giac vuong can.\n");
        } else if (isVuong) {
            printf("Day la tam giac vuong.\n");
        } else if (isCan) {
            printf("Day la tam giac can.\n");
        } else {
            printf("Day la tam giac thuong.\n");
        }
    } else {
        printf("Day khong phai la 3 canh cua mot tam giac.\n");
    }
}

void chucnang4(void) {
    float canh1, canh2, canh3;
    printf("Nhap do dai canh a: ");
    scanf("%f", &canh1);
    printf("Nhap do dai canh b: ");
    scanf("%f", &canh2);
    printf("Nhap do dai canh c: ");
    scanf("%f", &canh3);

    checkTriangle(canh1, canh2, canh3);
}


int main(void) {
    int chon;
    do {
        printf("+-------------------------------------------------+\n");
        printf("|               CHUONG TRINH LAB 5                |\n");
        printf("+-------------------------------------------------+\n");
        printf("|1. Tim gia tri lon nhat trong 3 so               |\n");
        printf("|2. Kiem tra nam nhuan                            |\n");
        printf("|3. Hoan vi 2 so (Su dung con tro)                |\n");
        printf("|4. Kiem tra va phan loai tam giac                |\n");
        printf("|5. Thoat                                         |\n");
        printf("+-------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                chucnang1();
                break;
            case 2:
                chucnang2();
                break;
            case 3:
                chucnang3();
                break;
            case 4:
                chucnang4();
                break;
            case 5:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai (1-5)\n");
                break;
        }
        printf("\n");
    } while (chon != 5);

    return 0;
}