// hasta kayıt, doktor kayıt, randevu alma,randevu iptal et, branslar

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  char hasta_adi[100];
  char hasta_soyadi[100];
  char hasta_tc_no[12];
  int  hasta_tc_int;
  char brans[50];
  char doktor_adi[100];
  char doktor_soyadi[100];
}Hasta;

typedef struct {
  char sifre[9];
}Yetkili;

void randevu_al(Hasta hastalar[],int *sira_no){
int i = *sira_no;

printf("Adinizi giriniz: ");
  fgets(hastalar[i].hasta_adi,sizeof(hastalar[i].hasta_adi),stdin);
  hastalar[i].hasta_adi[strcspn(hastalar[i].hasta_adi, "\n")] = '\0';  // \n sil

printf("Soy adinizi giriniz: ");
fgets(hastalar[i].hasta_soyadi,sizeof(hastalar[i].hasta_soyadi),stdin);
  hastalar[i].hasta_soyadi[strcspn(hastalar[i].hasta_soyadi, "\n")] = '\0';  // \n sil

printf("T.C. kimlik numaranizi giriniz: ");
  fgets(hastalar[i].hasta_tc_no,sizeof(hastalar[i].hasta_tc_no),stdin);
  hastalar[i].hasta_tc_no[strcspn(hastalar[i].hasta_tc_no,"\n")] = '\0';
  hastalar[i].hasta_tc_int = atoi(hastalar[i].hasta_tc_no);

printf("Randevu almak istediginiz bolumun adini giriniz: ");
fgets(hastalar[i].brans,sizeof(hastalar[i].brans),stdin);
  hastalar[i].brans[strcspn(hastalar[i].brans,"\n")] = '\0';

printf("Randevu almak istediginiz doktorun adini giriniz: ");
fgets(hastalar[i].doktor_adi,sizeof(hastalar[i].doktor_adi),stdin);
  hastalar[i].doktor_adi[strcspn(hastalar[i].doktor_adi,"\n")] = '\0';

  printf("Randevu almak istediginiz doktorun soy adini giriniz: ");
fgets(hastalar[i].doktor_soyadi,sizeof(hastalar[i].doktor_soyadi),stdin);
  hastalar[i].doktor_soyadi[strcspn(hastalar[i].doktor_soyadi,"\n")] = '\0';

printf("Kaydiniz olusturuldu\n");
printf("Sira numaraniz: %d\n",i);
  (*sira_no)++;
}

void yetkili_giris_sayfasi(Hasta *hastalar,int *doktor_no) {
  int islem=-1;
  int i=0;
  while (islem!=0) {
    printf("Yetkili giris sayfasina hos geldiniz\n");

    printf("Doktor ekleme islemi icin 1'e basiniz\nDoktor silme islemi icin 2'ye basiniz\nDoktor listesini gormek icin 3'e basiniz\nCikmak icin 0 tusuna basiniz: \n");
    scanf("%d",&islem);
    getchar();
    if (islem ==0) {
      printf("Cikis yapildi");
      break;
    }
    else if (islem == 1) {
      printf("Eklemek istediginiz doktorun adini giriniz: \n");
      fgets(hastalar[*doktor_no].doktor_adi,sizeof(hastalar[*doktor_no].doktor_adi),stdin);
      hastalar[*doktor_no].doktor_adi[strcspn(hastalar[*doktor_no].doktor_adi, "\n")] = 0;

      printf("Eklemek istediginiz doktorun soy adini giriniz: ");
      fgets(hastalar[*doktor_no].doktor_soyadi,sizeof(hastalar[*doktor_no].doktor_soyadi),stdin);
      hastalar[*doktor_no].doktor_soyadi[strcspn(hastalar[*doktor_no].doktor_soyadi,"\n")]=0;
      printf("Kayit olusturuldu\n");
      (*doktor_no)++;
      break;
    }
    else if (islem == 2) {
      printf("Silmek istediginiz doktorun adini giriniz: ");
      fgets(hastalar[*doktor_no].doktor_adi,sizeof(hastalar[*doktor_no].doktor_soyadi),stdin);
      hastalar[*doktor_no].doktor_adi[strcspn(hastalar[*doktor_no].doktor_adi,"\n")] = 0;

      printf("Silmek istediginiz doktorun soy adini giriniz: ");
      fgets(hastalar[*doktor_no].doktor_soyadi,sizeof(hastalar[*doktor_no].doktor_soyadi),stdin);
      hastalar[*doktor_no].doktor_soyadi[strcspn(hastalar[*doktor_no].doktor_soyadi,"\n")] = 0;
      printf("Doktor kaydi basariyla silindi\n");
      (*doktor_no)--;
      break;
    }
    else if (islem == 3) {
      for (int i=0;i<*doktor_no;i++) {
        printf("Doktor listesi: %d.: %s %s\n",i+1,hastalar[i].doktor_adi,hastalar[i].doktor_soyadi);
      }
      break;
    }
    else {
      printf("Yanlis sifre girdiniz");
    }
  }
}

  void yetkili_giris(Yetkili *yetkili,Hasta hastalar[],int *doktor_no) {

    char sifre1[9];
    while (1) {
      printf("Yetkili girisi yapmak icin sifrenizi giriniz(Cikmak icin 0 tusuna basiniz): \n");

      fgets(sifre1,sizeof(sifre1),stdin);
      sifre1[strcspn(sifre1, "\n")] = 0;
      if (strcmp(sifre1,"0") == 0) {
        break;
      }
      else if (strcmp(sifre1,yetkili->sifre) == 0) {
        yetkili_giris_sayfasi(hastalar,doktor_no);
        break;
      }
      else{
        printf("Yanlis sifre girdiniz!\n");
      }
    }
  }

int main(){
  Hasta hastalar[100];
  Yetkili yetkili;
  int islem=0;
  char girdi[10];
  int sira_no=1;
  int doktor_no=1;

  printf("----------Hastane Uygulamasi-----\n");
  while(islem!=3) {
    printf("Yapmak istediginiz islemi seciniz: \n");
    printf("1-Randevu al\n2-Yetkili girisi yap\n3-Cikis Yap\n");
    printf("Islem: ");
    fgets(girdi,sizeof(girdi),stdin);
    islem = atoi(girdi);

    switch (islem){
      case 1:
        randevu_al(hastalar,&sira_no);
      break;

      case 2: {
        strcpy(yetkili.sifre,"aAbB1234");
        yetkili_giris(&yetkili,hastalar,&doktor_no);
      }
      break;

      case 3:
        printf("Cikis yaptiniz\n");
      break;

      default:
        printf("Yanlis tercih yaptiniz\n");
      break;
    }
  }
  return 0;
}
