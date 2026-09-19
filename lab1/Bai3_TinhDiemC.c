#include <stdio.h>

int main(){
    char mssv[]="PS51227";
    char hoten[]="Pham Huu Duc";
    float toan = 7.5;
    float ly = 8.5;
    float hoa = 9.0;

    float diemTrungBinh = (toan *2 + ly + hoa) /4;
    
    printf("Ma so sinh vien: %s\n", mssv);
    printf("Ho va ten: %s\n", hoten);
    printf("Diem trung binh: %.2f\n", diemTrungBinh);
    
     return 0;   
}