#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "afed_yardim_sistemi.h"
#include "afed_yardim_sistemi.c"

int main() {
  setlocale(LC_ALL, "");
  int secim;
  menu_goster();
  do {
    printf("\nSeçiminizi girin: ");
    scanf("%d", & secim);
    switch (secim) {
    case 1: {
      char Ad[MAX_ISIM_UZUNLUK];
      char Soyad[MAX_ISIM_UZUNLUK];
      char Telefon[MAX_TELEFON_UZUNLUK];
      char Adres[MAX_ADRES_UZUNLUK];
      printf("Afetzedenin ismi: ");
      scanf("%s", Ad);
      printf("Afetzedenin soyismi: ");
      scanf("%s", Soyad);
      printf("Afetzedenin telefonu: ");
      scanf("%s", Telefon);
      printf("Afetzedenin adresi: ");
      scanf("%s", Adres);
      afetzede_ekle(Ad, Soyad, Telefon, Adres);
      break;
    }
    case 2: {
      int id;
      char Ad[MAX_ISIM_UZUNLUK];
      char Soyad[MAX_ISIM_UZUNLUK];
      char Telefon[MAX_TELEFON_UZUNLUK];
      char Adres[MAX_ADRES_UZUNLUK];
      printf("Güncellenecek afetzed ID'si: ");
      scanf("%d", & id);
      printf("Afetzedenin yeni ismi: ");
      scanf("%s", Ad);
      printf("Afetzedenin yeni soyismi: ");
      scanf("%s", Soyad);
      printf("Afetzedenin yeni telefonu: ");
      scanf("%s", Telefon);
      printf("Afetzedenin yeni adresi: ");
      scanf("%s", Adres);
      afetzede_guncelle(id, Ad, Soyad, Telefon, Adres);
      break;
    }
    case 3: {
      int id;
      printf("Silinecek afetzed ID'si: ");
      scanf("%d", & id);
      afetzede_sil(id);
      break;
    }
    case 4: {
      int id;
      char Aciklama[MAX_TALEP_UZUNLUK];
      printf("Yardım talebi kaydedilecek afetzede ID'sini giriniz: ");
      scanf("%d", & id);

      printf("Yardım talebi açıklaması: ");
      getchar();
      fgets(Aciklama, MAX_TALEP_UZUNLUK, stdin);

      yardim_talebi_kaydet(id, Aciklama);
      break;
    }
    case 5: {
      afetzede_listele();
      break;
    }
    case 6: {
      int id;
      printf("Aranacak afetzed ID'si: ");
      scanf("%d", & id);
      afetzede_ara(id);
      break;

    }
    case 7: {
      yardim_talepleri_listele();
      break;
    }
    case 8:
      menu_goster();
      break;
    case 0: {
      printf("Programdan çıkıyor...\n");
      break;
    }
    default: {
      hata_mesaji();
      break;
    }
    }
  } while (secim != 0);

  return 0;
}
