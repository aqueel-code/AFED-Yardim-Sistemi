#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "afed_yardim_sistemi.h"

void afetzede_ekle(char * ad, char * soyad, char * telefon, char * adres) {
  if (afetzede_sayisi >= MAX_AFETZEDE_SAYISI) {
    printf("Hata: Maksimum afetzede sayısına ulaşıldı.\n");
    return;
  }
  strcpy(afetzede_isimleri[afetzede_sayisi], ad);
  strcpy(afetzede_soyisimleri[afetzede_sayisi], soyad);
  strcpy(afetzede_telefonlar[afetzede_sayisi], telefon);
  strcpy(afetzede_adresleri[afetzede_sayisi], adres);
  printf("Afetzedeye ID %d verildi.\n", afetzede_sayisi);
  afetzede_sayisi++;
}

void afetzede_guncelle(int id, char * ad, char * soyad, char * telefon, char * adres) {
  if (id < 0 || id >= afetzede_sayisi) {
    printf("Hata: Geçersiz afetzed ID'si.\n");
    return;
  }
  strcpy(afetzede_isimleri[id], ad);
  strcpy(afetzede_soyisimleri[id], soyad);
  strcpy(afetzede_telefonlar[id], telefon);
  strcpy(afetzede_adresleri[id], adres);
  printf("Afetzedeki bilgiler güncellendi.\n");
}

void afetzede_sil(int id) {
  if (id < 0 || id >= afetzede_sayisi) {
    printf("Hata: Gecersiz afetzede ID'si!\n");
    return;
  }
  int i;
  for (i = id; i < afetzede_sayisi - 1; i++) {
    strcpy(afetzede_isimleri[i], afetzede_isimleri[i + 1]);
    strcpy(afetzede_soyisimleri[i], afetzede_soyisimleri[i + 1]);
    strcpy(afetzede_telefonlar[i], afetzede_telefonlar[i + 1]);
    strcpy(afetzede_adresleri[i], afetzede_adresleri[i + 1]);
  }
  afetzede_sayisi--;
  printf("Afetzedeki bilgiler ve Yardım talebi silindi.\n");
}

void yardim_talebi_kaydet(int id, char * aciklama) {
  if (id < 0 || id >= afetzede_sayisi) {
    printf("Hata: Geçersiz afetzed ID'si.\n");
    return;
  }
  if (talep_sayisi >= MAX_AFETZEDE_SAYISI) {
    printf("Hata: Maksimum Yardım talebi sayısına ulaşıldı.\n");
    return;
  }
  talep_afetzede_idleri[talep_sayisi] = id;
  strcpy(talep_aciklamalari[talep_sayisi], aciklama);
  talep_sayisi++;
  printf("Yardım talebi kaydedildi.\n");
}

void afetzede_listele() {
  if (afetzede_sayisi == 0) {
    printf("Kayıtlı afetzedeler yok.\n");
    return;
  }
  printf("Afetzedeler:\n");
  printf("ID\tİsim\tSoyisim\tTelefon\tAdres\n");
  int i;
  for (int i = 0; i < afetzede_sayisi; i++) {
    printf("%d\t%s\t%s\t%s\t%s\n", i, afetzede_isimleri[i], afetzede_soyisimleri[i], afetzede_telefonlar[i], afetzede_adresleri[i]);
  }
}

void afetzede_ara(int id) {
  if (id < 0 || id >= afetzede_sayisi) {
    printf("Hata: Geçersiz afetzed ID'si.\n");
    return;
  }
  printf("Afetzedeki bilgiler:\n");
  printf("İsim: %s\n", afetzede_isimleri[id]);
  printf("Soyisim: %s\n", afetzede_soyisimleri[id]);
  printf("Telefon: %s\n", afetzede_telefonlar[id]);
  printf("Adres: %s\n", afetzede_adresleri[id]);
  printf("Yardım talepleri:\n");
  for (int i = 0; i < talep_sayisi; i++) {
    if (talep_afetzede_idleri[i] == id) {
      printf("- %s\n", talep_aciklamalari[i]);
    }
  }
}

void yardim_talepleri_listele() {
  if (talep_sayisi == 0) {
    printf("Kayıtlı yardım talebi yok.\n");
    return;
  }

  printf("Yardım talepleri:\n");
  printf("Afetzed ID\tAçıklama\n");

  int i;
  for (i = 0; i < talep_sayisi; i++) {
    char * isim = afetzede_isimleri[talep_afetzede_idleri[i]];
    char * soyisim = afetzede_soyisimleri[talep_afetzede_idleri[i]];

    if (isim == NULL || soyisim == NULL) {
      printf("%d\tMaalesef Bulunamadı\t%s\n", i, talep_aciklamalari[i]);
    } else {
      printf("%d\t%s %s\t%s\n", i, isim, soyisim, talep_aciklamalari[i]);
    }
  }
}

void menu_goster() {
  printf(".:: Afetzedeler Yardım Sistemi ::.\n");
  printf("1. Afetzedeye ekle\n");
  printf("2. Afetzedeyi güncelle\n");
  printf("3. Afetzedeyi sil\n");
  printf("4. Yardım talebi kaydet\n");
  printf("5. Afetzedeleri listele\n");
  printf("6. Afetzedeyi ara\n");
  printf("7. Yardım taleplerini listele\n");
  printf("8. Menusunu goster\n");
  printf("0. Çıkış");
}

void hata_mesaji() {
  printf("Hata: Geçersiz seçim.\n");
}
