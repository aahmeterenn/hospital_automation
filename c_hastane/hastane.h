#ifndef HASTANE_H
#define HASTANE_H

typedef struct {
    char hasta_adi[100];
    char hasta_soyadi[100];
    char hasta_tc_no[12];
    int  hasta_tc_int;
    char brans[50];
    char doktor_adi[100];
    char doktor_soyadi[100];
} Hasta;

typedef struct {
    char sifre[9];
} Yetkili;

// Fonksiyon prototipleri
void randevu_al(Hasta hastalar[], int *sira_no);
void yetkili_giris_sayfasi(Hasta hastalar[], int *doktor_no);
void yetkili_giris(Yetkili *yetkili, Hasta hastalar[], int *doktor_no);

#endif
