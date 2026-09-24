#include <stdio.h>
#define PI 3.14159

int main(){
    float cd, cr, r;

    printf("Nhap chieu dai va chieu rong: ");
    scanf("%f %f", &cd, &cr);

    printf("Nhap ban kinh: ");
    scanf("%f", &r);

    printf("Chu vi hinh chu nhat: %2.f\n", (cd + cr) *2);
    printf("Dien tich hinh chu nhat: %2.f\n", cd * cr);
    printf("Chu vi hinh tron: %2.f\n", 2 * PI * r);
    printf("Dien tich hinh tron: %2.f\n", PI * r * r);
     return 0;

}