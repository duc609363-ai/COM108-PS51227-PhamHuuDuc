#include <stdio.h>

int main(){
  float dtb;
  int hanhKiem;
  int dieuKienDiem, dieuKienHanhKiem, ketQuaXetTN;

  printf("Nhap diem trung binh: ");
  scanf("%f", &dtb);

  printf("Nhap hanh kiem: ");
  scanf("%d", &hanhKiem);

  if (dtb >= 8) {
    dieuKienDiem = 1;
  } else {
    dieuKienDiem = 0;
  }

  if (hanhKiem == 1) {
    dieuKienHanhKiem = 1;
  } else {
    dieuKienHanhKiem = 0;
  }

  if (dieuKienDiem == 1 && dieuKienHanhKiem == 1) {
    ketQuaXetTN = 1;
  } else {
    ketQuaXetTN = 0;  
  }
  printf("Dieu kien diem trung binh >= 8: %d\n", dieuKienDiem);
  printf("Dieu kien hanh kiem tot: %d\n", dieuKienHanhKiem);
  printf("Ket qua xe hoc bong (1: Dat, 0: Khong dat): %d\n", ketQuaXetTN);
  
  return 0;
}