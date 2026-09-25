#include <stdio.h>
int main(){
    float toan, ly, hoa;
    float diemTrungBinh;

    printf("Nhap diem mon toan: ");
    scanf("%f", &toan);

    printf("Nhap diem mon ly: ");
    scanf("%f", &ly);

    printf("Nhap diem mon hoa: ");
    scanf("%f", &hoa);
     
    diemTrungBinh = (float)(toan * 3 + ly * 2 + hoa * 1) / 6;
     
    printf("Diem trung binh: %2.f\n", diemTrungBinh);
    return 0;
}