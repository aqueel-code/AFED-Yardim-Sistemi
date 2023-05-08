#ifndef AFED_YARDIM_SISTEMI
#define AFED_YARDIM_SISTEMI

#define MAX_AFETZEDE_SAYISI 100
#define MAX_ISIM_UZUNLUK 50
#define MAX_TELEFON_UZUNLUK 20
#define MAX_ADRES_UZUNLUK 100
#define MAX_TALEP_UZUNLUK 200
#define MAX_TALEP_SAYISI 1000
#define MAX_LENGTH 1000

char afetzede_isimleri[MAX_AFETZEDE_SAYISI][MAX_ISIM_UZUNLUK];
char afetzede_soyisimleri[MAX_AFETZEDE_SAYISI][MAX_ISIM_UZUNLUK];
char afetzede_telefonlar[MAX_AFETZEDE_SAYISI][MAX_TELEFON_UZUNLUK];
char afetzede_adresleri[MAX_AFETZEDE_SAYISI][MAX_ADRES_UZUNLUK];
int afetzede_sayisi = 0;

char talep_aciklamalari[MAX_TALEP_SAYISI][MAX_TALEP_UZUNLUK];
int talep_afetzede_idleri[MAX_TALEP_SAYISI];
int talep_sayisi = 0;

void BannerGoster();
void hakkinda();

#endif