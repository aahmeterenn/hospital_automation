#include <stdio.h>
#include "hastane.h"
#include <string.h>

int main() {
    Yetkili y;
    strcpy(y.sifre, "aAbB1234");
    Hasta hastalar[10];
    int doktor_no = 0;

    yetkili_giris(&y, hastalar, &doktor_no);

    printf("Program bitti.\n");
    return 0;
}
