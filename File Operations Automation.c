#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
/*
  EMRE ULUISIK
  18010011013
*/

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

typedef struct YOLCU
{
    char ad[15];
    char soyad[15];
    char kimlikNo[5];
    int yas;
    char uyeAd[15];
    char uyeSoyad[15];
    char uyeKimlikNo[15];
    int uyeYas;
}yolcu;

typedef struct BILET
{
    char ilkSehir[15];
    char sonSehir[15];
    char ay[15];
    int gun;
    int koltukNo;
    int uyeSayisi;
    int gidisUcreti;
    int yolcuSayisi;
    yolcu *y;
    yolcu *uye;
}bilet;

int i;
char Soyad[15];


void UyeliksizYolcuGuncelle(bilet *b, int i, yolcu *y)
{

    char guncelAd[15], guncelSoyad[15], guncelKimlikNo[15], guncelVarisSehri[15], guncelKalkisSehri[15];
    int guncelYas, guncelKoltukNo;


    FILE *uyeliksizAra = fopen("uyeliksiz_yolcu_kayitlari1813.txt","r");
    FILE *uyeliksizGuncelle = fopen("uyeliksiz_yolcu_kayitlari1813.txt","r+");

    printf("Guncellenecek yolcunun soyadini giriniz: ");
    scanf("%s", Soyad);


    printf("Guncel kalkis sehri: ");   scanf("%s", guncelKalkisSehri);
    printf("Guncel varis sehri: ");    scanf("%s", guncelVarisSehri);
    printf("Guncel koltuk no: ");      scanf("%d", &guncelYas);

    printf("Guncel ad: ");             scanf("%s", guncelAd);
    printf("Guncel soyad: ");          scanf("%s", guncelSoyad);
    printf("Guncel numara: ");         scanf("%s", guncelKimlikNo);
    printf("Guncel yas: ");            scanf("%d", &guncelYas);

    fprintf(uyeliksizGuncelle, "\n");

    while(!feof(uyeliksizAra)){

       (b+i)->y = (yolcu *)malloc(sizeof(yolcu));
       fscanf(uyeliksizAra, "%s %s %d %d %s %s %s %d\n", (b+i)->ilkSehir, (b+i)->sonSehir, &(b+i)->koltukNo, &(b+i)->gidisUcreti, ((b+i)->y)->ad, ((b+i)->y)->soyad, ((b+i)->y)->kimlikNo, &((b+i)->y)->yas);

       if(strcmp((((b+i)->y)->soyad) , Soyad)==0){

         strcpy((b+i)->ilkSehir , guncelKalkisSehri);
         strcpy((b+i)->sonSehir , guncelVarisSehri);
         (b+i)->koltukNo = guncelKoltukNo;

         strcpy(((b+i)->y)->ad , guncelAd);
         strcpy(((b+i)->y)->soyad , guncelSoyad);
         strcpy(((b+i)->y)->kimlikNo , guncelKimlikNo);
         ((b+i)->y)->yas = guncelYas;

       }

    fprintf(uyeliksizGuncelle, "%s %s %d %d %s %s %s %d\n", (b+i)->ilkSehir, (b+i)->sonSehir, (b+i)->koltukNo, (b+i)->gidisUcreti, ((b+i)->y)->ad, ((b+i)->y)->soyad, ((b+i)->y)->kimlikNo, ((b+i)->y)->yas);

    }

    fclose(uyeliksizAra);
    fclose(uyeliksizGuncelle);


}


void UyeliksizYolcuSil(bilet *b, int i, yolcu *y)
{

    FILE *uyeliksizAra = fopen("uyeliksiz_yolcu_kayitlari1813.txt","r");
    FILE *uyeliksizSil = fopen("uyeliksiz_yolcu_kayitlari1813.txt","a");

    printf("Silinecek yolcunun soyadini giriniz: ");
    scanf("%s", Soyad);

    fprintf(uyeliksizSil, "\n\n");

    while(!feof(uyeliksizAra)){

       (b+i)->y = (yolcu *)malloc(sizeof(yolcu));
       fscanf(uyeliksizAra, "%s %s %d %d %s %s %s %d", (b+i)->ilkSehir, (b+i)->sonSehir, &(b+i)->koltukNo, &(b+i)->gidisUcreti, ((b+i)->y)->ad, ((b+i)->y)->soyad, ((b+i)->y)->kimlikNo, &((b+i)->y)->yas);

       if(strcmp((((b+i)->y)->soyad) , Soyad)==0){

           continue;
       }

       printf("%s %s %d %d %s %s %s %d\n", (b+i)->ilkSehir, (b+i)->sonSehir, (b+i)->koltukNo, (b+i)->gidisUcreti, ((b+i)->y)->ad, ((b+i)->y)->soyad, ((b+i)->y)->kimlikNo, ((b+i)->y)->yas);
       fprintf(uyeliksizSil, "%s %s %d %d %s %s %s %d\n", (b+i)->ilkSehir, (b+i)->sonSehir, (b+i)->koltukNo, (b+i)->gidisUcreti, ((b+i)->y)->ad, ((b+i)->y)->soyad, ((b+i)->y)->kimlikNo, ((b+i)->y)->yas);

    }

    fclose(uyeliksizAra);
    fclose(uyeliksizSil);

}


void UyeliksizYolcuAra(bilet *b, int i, yolcu *y)
{

    FILE *uyeliksizAra = fopen("uyeliksiz_yolcu_kayitlari1813.txt","r");
    if(uyeliksizAra == NULL){

        printf("Dosya acilamadi..");
        return -1;
    }

    printf("Aranacak uye yolcunun soyadini giriniz: ");
    scanf("%s", Soyad);


    while(!feof(uyeliksizAra)){

       (b+i)->y = (yolcu *)malloc(sizeof(yolcu));
       fscanf(uyeliksizAra, "%s %s %d %d %d %s %s %s %s %d", (b+i)->ilkSehir, (b+i)->sonSehir, &(b+i)->koltukNo, &(b+i)->gidisUcreti, &(b+i)->gun, (b+i)->ay, ((b+i)->y)->ad, ((b+i)->y)->soyad, ((b+i)->y)->kimlikNo, &((b+i)->y)->yas);



    if(strcmp(((b+i)->y)->soyad , Soyad)==0)

        printf("\n%s %s %d %d %d %s %s %s %s %d\n", (b+i)->ilkSehir, (b+i)->sonSehir, (b+i)->koltukNo, (b+i)->gidisUcreti, (b+i)->gun, (b+i)->ay, ((b+i)->y)->ad, ((b+i)->y)->soyad, ((b+i)->y)->kimlikNo, ((b+i)->y)->yas);

    }

    fclose(uyeliksizAra);

}


void UyelikliYolcuGuncelle(bilet *b, int i, yolcu *uye)
{

    char guncelAd[15], guncelSoyad[15], guncelKimlikNo[15], guncelVarisSehri[15], guncelKalkisSehri[15];
    int guncelYas, guncelKoltukNo;


    FILE *uyelikAra = fopen("uyelikli_yolcu_kayitlari1813.txt","r");
    FILE *uyelikGuncelle = fopen("uyelikli_yolcu_kayitlari1813.txt","r+");

    printf("Guncellenecek uye yolcunun soyadini giriniz: ");
    scanf("%s", Soyad);


    printf("Guncel kalkis sehri: ");  scanf("%s", guncelKalkisSehri);
    printf("Guncel varis sehri: ");   scanf("%s", guncelVarisSehri);
    printf("Guncel koltuk no: ");     scanf("%d", &guncelYas);

    printf("Guncel ad: ");            scanf("%s", guncelAd);
    printf("Guncel soyad: ");         scanf("%s", guncelSoyad);
    printf("Guncel numara: ");        scanf("%s", guncelKimlikNo);
    printf("Guncel yas: ");           scanf("%d", &guncelYas);

    fprintf(uyelikGuncelle, "\n");

    while(!feof(uyelikAra)){

       (b+i)->uye = (yolcu *)malloc(sizeof(yolcu));
       fscanf(uyelikAra, "%s %s %d %d %s %s %s %d\n", (b+i)->ilkSehir, (b+i)->sonSehir, &(b+i)->koltukNo, &(b+i)->gidisUcreti, ((b+i)->uye)->uyeAd, ((b+i)->uye)->uyeSoyad, ((b+i)->uye)->uyeKimlikNo, &((b+i)->uye)->uyeYas);

       if(strcmp((((b+i)->uye)->uyeSoyad) , Soyad)==0){

         strcpy((b+i)->ilkSehir , guncelKalkisSehri);
         strcpy((b+i)->sonSehir , guncelVarisSehri);
         (b+i)->koltukNo = guncelKoltukNo;

         strcpy(((b+i)->uye)->uyeAd , guncelAd);
         strcpy(((b+i)->uye)->uyeSoyad , guncelSoyad);
         strcpy(((b+i)->uye)->uyeKimlikNo , guncelKimlikNo);
         ((b+i)->uye)->uyeYas = guncelYas;

       }

    fprintf(uyelikGuncelle, "%s %s %d %d %s %s %s %d\n", (b+i)->ilkSehir, (b+i)->sonSehir, (b+i)->koltukNo, (b+i)->gidisUcreti, ((b+i)->uye)->uyeAd, ((b+i)->uye)->uyeSoyad, ((b+i)->uye)->uyeKimlikNo, ((b+i)->uye)->uyeYas);

    }

    fclose(uyelikAra);
    fclose(uyelikGuncelle);

}


void UyelikliYolcuSil(bilet *b, int i, yolcu *uye)
{

    FILE *uyelikAra = fopen("uyelikli_yolcu_kayitlari1813.txt","r");
    FILE *uyelikSil = fopen("uyelikli_yolcu_kayitlari1813.txt","a");

    printf("Silinecek uye yolcunun soyadini giriniz: ");
    scanf("%s", Soyad);

    fprintf(uyelikSil, "\n\n");

    while(!feof(uyelikAra)){

       (b+i)->uye = (yolcu *)malloc(sizeof(yolcu));
       fscanf(uyelikAra, "%s %s %d %d %s %s %s %d", (b+i)->ilkSehir, (b+i)->sonSehir, &(b+i)->koltukNo, &(b+i)->gidisUcreti, ((b+i)->uye)->uyeAd, ((b+i)->uye)->uyeSoyad, ((b+i)->uye)->uyeKimlikNo, &((b+i)->uye)->uyeYas);

       if(strcmp((((b+i)->uye)->uyeSoyad) , Soyad)==0){

           continue;
       }




       printf("%s %s %d %d %s %s %s %d\n", (b+i)->ilkSehir, (b+i)->sonSehir, (b+i)->koltukNo, (b+i)->gidisUcreti, ((b+i)->uye)->uyeAd, ((b+i)->uye)->uyeSoyad, ((b+i)->uye)->uyeKimlikNo, ((b+i)->uye)->uyeYas);
       fprintf(uyelikSil, "%s %s %d %d %s %s %s %d\n", (b+i)->ilkSehir, (b+i)->sonSehir, (b+i)->koltukNo, (b+i)->gidisUcreti, ((b+i)->uye)->uyeAd, ((b+i)->uye)->uyeSoyad, ((b+i)->uye)->uyeKimlikNo, ((b+i)->uye)->uyeYas);

    }

    fclose(uyelikAra);
    fclose(uyelikSil);

}


void UyelikliYolcuAra(bilet *b, int i, yolcu *uye)
{

    FILE *uyelikAra = fopen("uyelikli_yolcu_kayitlari1813.txt","r");
    if(uyelikAra == NULL){

        printf("Dosya acilamadi..");
        return -1;
    }

    printf("Aranacak uye yolcunun soyadini giriniz: ");
    scanf("%s", Soyad);


    while(!feof(uyelikAra)){

       (b+i)->uye = (yolcu *)malloc(sizeof(yolcu));
       fscanf(uyelikAra, "%s %s %d %d %s %s %s %d", (b+i)->ilkSehir, (b+i)->sonSehir, &(b+i)->koltukNo, &(b+i)->gidisUcreti, ((b+i)->uye)->uyeAd, ((b+i)->uye)->uyeSoyad, ((b+i)->uye)->uyeKimlikNo, &((b+i)->uye)->uyeYas);



    if(strcmp(((b+i)->uye)->uyeSoyad , Soyad)==0)

        printf("\n%s %s %d %d %s %s %s %d\n", (b+i)->ilkSehir, (b+i)->sonSehir, (b+i)->koltukNo, (b+i)->gidisUcreti, ((b+i)->uye)->uyeAd, ((b+i)->uye)->uyeSoyad, ((b+i)->uye)->uyeKimlikNo, ((b+i)->uye)->uyeYas);

    }

    fclose(uyelikAra);

}


void GidisTarihi(bilet *b, int i)
{

    int j, t, a, k=1;
    char Aylar[13][10] = {"","OCAK","SUBAT","MART","NISAN","MAYIS","HAZIRAN","TEMMUZ","AGUSTOS","EYLUL","EKIM","KASIM","ARALIK"};

    printf("\nBilet almak istediginiz ayi takvimdeki sirasina gore tuslayiniz (1 ile 12 arasinda): ");
    scanf("%d", &t);
    if(t<=0 || t>30){

        printf("Yanlis tusladiniz. Lutfen 1 ile 12 arasinda bir sayi tuslayiniz: ");
        scanf("%d", &t);
        if(t<=0 || t>30)
            GidisTarihi(b,i);

    }

    printf("\n\t\t< %s >", Aylar[t]);
    printf("\n\n");


    for(a=1;a<=6;a++){

        for(j=1;j<=5;j++){

           printf("   %d\t", k);
           k++;
        }
    printf("\n\n");
    }


    printf("\n\nBilet almak istediginiz gunu yaziniz: ");
    scanf("%d", &(b+i)->gun);

    if((b+i)->gun<=0 || (b+i)->gun>30){

        printf("Yanlis tusladiniz. Lutfen takvimdeki sayilardan birini tuslayiniz: ");
        scanf("%d", &(b+i)->gun);
        printf("\nGidis Tarihiniz: %d %s 2019", (b+i)->gun, Aylar[t]);
        delay(2800);

        if((b+i)->gun<=0 || (b+i)->gun>30)
            GidisTarihi(b,i);
    }

    printf("\nGidis Tarihiniz -> Gun: %d, Ay: %s, Yil: 2019", (b+i)->gun, Aylar[t]);
    delay(2800);
    printf("\n\n");

    strcpy((b+i)->ay , Aylar[t]);

}


void KoltukSec(bilet *b, int i)
{

    int q, z, x, y=0;
    int Koltuk_Sec[3][6];

    printf("\n~~~~~~~~~~~~ KOLTUK SECIMI ~~~~~~~~~~~~\n\n");

    for(q=0;q<3;q++){

       for(x=0;x<6;x++){

            Koltuk_Sec[q][x] = y+1;
            y++;

       }
    }


    for(q=0;q<3;q++){

      for(x=0;x<6;x++){

        printf("|%d|\t", Koltuk_Sec[q][x]);
        if(Koltuk_Sec[q][x]%9==0)
            printf("\n");

      }
    }

    printf("\n----------------------------- KORIDOR -----------------------------\n\n");


    for(q=0;q<3;q++){

      for(x=0;x<6;x++){

        Koltuk_Sec[q][x] = y+1;
        y++;

      }
    }

    for(q=0;q<3;q++){

      for(x=0;x<6;x++){

         printf("|%d|\t", Koltuk_Sec[q][x]);
         if(Koltuk_Sec[q][x]%27==0)
            printf("\n");

      }
    }

    printf("\n\nOturmak istediginiz koltugun numarasini giriniz: ");
    scanf("%d", &(b+i)->koltukNo);
    delay(1500);


}


void KalkisVarisYerleri(bilet *b, int i)
{

    int a, t;
    char Sehirler[7][10] = {"","ISTANBUL","KONYA","ESKISEHIR","TRABZON","IZMIR","MALATYA"};

    printf("\n* 1-ISTANBUL * \t* 2-KONYA *\t* 3-ESKISEHIR *\t  * 4-TRABZON *\t* 5-IZMIR *\t* 6-MALATYA *");
    printf("\n______________ \t___________\t_______________\t  _____________\t___________\t_____________");

    printf("\n\n%d.yolcunun kalkis yapacagi sehrin onundeki numarayi tuslayiniz: ",  i+1);
    scanf("%d", &a);

    printf("\n\n%d.yolcunun varis yapacagi sehrin onundeki numarayi tuslayiniz: ", i+1);
    scanf("%d", &t);

    if((a == 1 && t == 2) || (t == 1 && a == 2))
        (b+i)->gidisUcreti = 150;
    if((a == 1 && t == 3) || (t == 1 && a == 3))
        (b+i)->gidisUcreti = 110;
    if((a == 1 && t == 4) || (t == 1 && a == 4))
        (b+i)->gidisUcreti = 270;
    if((a == 1 && t == 5) || (t == 1 && a == 5))
        (b+i)->gidisUcreti = 70;
    if((a == 1 && t == 6) || (t == 1 && a == 6))
        (b+i)->gidisUcreti = 380;
    if((a == 2 && t == 3) || (t == 2 && a == 3))
        (b+i)->gidisUcreti = 40;
    if((a == 2 && t == 4) || (t == 2 && a == 4))
        (b+i)->gidisUcreti = 120;
    if((a == 2 && t == 5) || (t == 2 && a == 5))
        (b+i)->gidisUcreti = 80;
    if((a == 2 && t == 6) || (t == 2 && a == 6))
        (b+i)->gidisUcreti = 230;
    if((a == 3 && t == 4) || (t == 3 && a == 4))
        (b+i)->gidisUcreti = 160;
    if((a == 3 && t == 5) || (t == 3 && a == 5))
        (b+i)->gidisUcreti = 40;
    if((a == 3 && t == 6) || (t == 3 && a == 6))
        (b+i)->gidisUcreti = 270;
    if((a == 4 && t == 5) || (t == 4 && a == 5))
        (b+i)->gidisUcreti = 160;
    if((a == 4 && t == 6) || (t == 4 && a == 6))
        (b+i)->gidisUcreti = 110;
    if((a == 5 && t == 6) || (t == 5 && a == 6))
        (b+i)->gidisUcreti = 310;


    if(a == t){

        printf("\nAyni sehri tusladiniz. Lutfen sehirleri farkli seciniz !");
        KalkisVarisYerleri(b,i);
    }

    printf("\n%Kalkis sehri: %s - Varis sehri: %s", Sehirler[a], Sehirler[t]);
    printf("\nOdenecek tutar: %d TL", (b+i)->gidisUcreti);
    delay(3000);


    strcpy((b+i)->ilkSehir , Sehirler[a]);
    strcpy((b+i)->sonSehir , Sehirler[t]);

}


void UyelikliYolcuKaydetme(bilet *b, yolcu *uye, int i)
{

// Gonderilen uyenin kaydi icin kayddetme dosyasi acilir ve dosyaya kaydedilir.
// Bir yolcu sadece bir bilete sahip olabilecegi icin de " biletSayisi=1 " yapilir..

    int j, biletSayisi=1;

    FILE *uyeyiKaydet = fopen("uyelikli_yolcu_kayitlari1813.txt","a");
    if(uyeyiKaydet == NULL){

        printf("Dosya acilamadi..");
        return -1;
    }

    for(j=0; j<biletSayisi ;j++){

        if(biletSayisi == NULL)
            b = (bilet*) malloc(biletSayisi * sizeof(bilet));

        else
            b = (bilet*) realloc(b , sizeof(bilet) * biletSayisi);

system("cls");
        KalkisVarisYerleri(b,i);
system("cls");
        KoltukSec(b,i);
system("cls");
        GidisTarihi(b,i);
        fprintf(uyeyiKaydet, "%s %s %d %d %d %s ", (b+i)->ilkSehir, (b+i)->sonSehir, (b+i)->koltukNo, (b+i)->gidisUcreti, (b+i)->gun, (b+i)->ay);

        fprintf(uyeyiKaydet, "%s %s %s %d\n", ((b+i)->uye)->uyeAd, ((b+i)->uye)->uyeSoyad, ((b+i)->uye)->uyeKimlikNo, ((b+i)->uye)->uyeYas);

    fclose(uyeyiKaydet);

    }

    j--;

}


void UyelikOlusturma(bilet *b, yolcu *uye, int yolcuAdet)
{

// Kodda ilk once uye kaydi yapiliyor ve uyeler dosyasi aciliyor.
// Sonra uye olan kisi icin 'yolcu kaydi listesi'ne eklenip eklenmeyecegi soruluyor.
// Kayit onaylanirsa yolcu yolcu kaydetme fonksiyonuna gönderiliyor.
// Kayit onaylanmazsa  uyelik tamamlaniyor ve islem bitiyor..

    yolcuAdet = 1;
    int i, uyeKayit;

//    printf("\nUye olacak kisi sayisini giriniz: ");
//    scanf("%d", &yolcuAdet);


    for(i=0; i<yolcuAdet ;i++){

        if(yolcuAdet == 1)
            (b+i)->uye = (yolcu*)malloc(sizeof(yolcu) * yolcuAdet);

        else
            (b+i)->uye = (yolcu*)realloc(uye, sizeof(yolcu) * yolcuAdet);


        FILE *uyelik = fopen("uyeler1813.txt","a");
        if(uyelik == NULL){

           printf("Dosya acilamadi..");
           return -1;
        }

        printf("%d.) Adinizi, soyadinizi arasinda bosluk birakarak giriniz: ", i+1);
        scanf("%s %s", ((b+i)->uye)->uyeAd, ((b+i)->uye)->uyeSoyad);
        printf("5 haneli kimlik numaranizi giriniz: ");
        scanf("%s", ((b+i)->uye)->uyeKimlikNo);
        if(strlen(((b+i)->uye)->uyeKimlikNo) != 5)
        {
           printf("Lutfen kimlik numaranizi 5 haneli giriniz: ");
           scanf("%s", ((b+i)->uye)->uyeKimlikNo);
           if(strlen(((b+i)->uye)->uyeKimlikNo) != 5)
           UyelikOlusturma(b,uye,yolcuAdet);
        }
        printf("Yasinizi giriniz: ");
        scanf("%d", &((b+i)->uye)->uyeYas);

        fprintf(uyelik, "%s %s %s %d\n", ((b+i)->uye)->uyeAd, ((b+i)->uye)->uyeSoyad, ((b+i)->uye)->uyeKimlikNo, ((b+i)->uye)->uyeYas);

        printf("Uye olan yolcuyu 'Uyelikli Yolcu Kayitlari Listesi'ne eklemek icin 1'e basiniz: ");
        scanf("%d", &uyeKayit);
        if(uyeKayit == 1)
        {
system("cls");
            UyelikliYolcuKaydetme(b,uye,i);
        }

        else
            printf("\nUyelikler basariyla olusturuldu..\n");


      printf("\nUyelikli yolcu kaydi tamamlandi..\n");
      delay(2500);
      fclose(uyelik);
    }


}


void UyeliksizYolcuKaydetme(bilet *b)
{

// Bir bileti birden fazla yolcu alabilir. Fakat bir yolcu birden fazla bilet alamaz..


    FILE *kayit = fopen("uyeliksiz_yolcu_kayitlari1813.txt","a");
    if(kayit == NULL){

        printf("Dosya acilamadi..");
        return -1;
    }

    int i, j, kayitSayisi, biletSayisi;

    printf("Kac adet bilet almak istediginizi giriniz: ");
    scanf("%d", &biletSayisi);

    for(i=0; i<biletSayisi ;i++){

        if(biletSayisi == NULL)
            b = (bilet*) malloc(biletSayisi * sizeof(bilet));

        else
            b = (bilet*) realloc(b , sizeof(bilet) * biletSayisi);

system("cls");
        KalkisVarisYerleri(b,i);
system("cls");
        KoltukSec(b,i);
system("cls");
        GidisTarihi(b,i);
        fprintf(kayit, "%s %s %d %d %d %s ", (b+i)->ilkSehir, (b+i)->sonSehir, (b+i)->koltukNo, (b+i)->gidisUcreti, (b+i)->gun, (b+i)->ay);


           kayitSayisi = (b+i)->yolcuSayisi;
system("cls");
           printf("Kaydetmek istediginiz yolcu sayisini giriniz: ");
           scanf("%d", &kayitSayisi);

           if(biletSayisi == 1)
             (b+i)->y = (yolcu*) malloc(kayitSayisi * sizeof(yolcu));

           else
             (b+i)->y = (yolcu*) realloc((b+i)->y , kayitSayisi * sizeof(yolcu));

           printf("\n");

           for(j=0; j<kayitSayisi ;j++){

              printf("%d. Biletin %d. Yolcusunun Adi: ", i+1, j+1);               scanf("%s", ((b+i)->y+j)->ad);
              printf("%d. Biletin %d. Yolcusunun Soyadi: ", i+1, j+1);            scanf("%s", ((b+i)->y+j)->soyad);
              printf("%d. Biletin %d. Yolcusunun Kimlik Numarasi: ", i+1, j+1);   scanf("%s", ((b+i)->y+j)->kimlikNo);
              printf("%d. Biletin %d. Yolcusunun Yasi: ", i+1, j+1);              scanf("%d", &((b+i)->y+j)->yas);

              if(j>=2)
              {
                 fprintf(kayit, "%s %s %d %d %d %s ", (b+i)->ilkSehir, (b+i)->sonSehir, (b+i)->koltukNo, (b+i)->gidisUcreti, (b+i)->gun, (b+i)->ay);
              }

              fprintf(kayit, "%s %s %s %d\n", ((b+i)->y+j)->ad, ((b+i)->y+j)->soyad, ((b+i)->y+j)->kimlikNo, ((b+i)->y+j)->yas);

           }

    }

system("cls");
    printf("Islemleriniz tamamlandi..");
    delay(1500);
    fclose(kayit);

}


int main()
{

    int biletAdet, secim, islem;

    bilet *b = (bilet*)malloc(sizeof(bilet)*biletAdet);
    yolcu *uye = (yolcu*)malloc(sizeof(yolcu)*biletAdet);
    yolcu *y = (yolcu*)malloc(sizeof(yolcu)*biletAdet);

    printf("Bilet Alma Islemlerine Hosgeldiniz..\n\n");
    printf("'Uyelikli Yolcu' uzerinden islem yapmak icin 1'e basiniz.\n'Uyeliksiz Yolcu' uzerinden islem yapmak icin herhangi bir tusa basiniz: ");
    scanf("%d", &islem);
    if(islem == 1){

system("cls");

        printf("Islemlerinize uyelikli yolculuk uzerinden devam ediliyor..\n\n");
        delay(1500);
        printf("\n< 1 > Uyelikli Yolcu Kaydet..\n< 2 > Uyelikli Yolcu Sil..\n< 3 > Uyelikli Yolcu Ara..\n< 4 > Uyelikli Yolcu Guncelle..");
        printf("\n\nSeciminiz: ");
        scanf("%d", &secim);

system("cls");

        switch(secim)
        {
            case 1: UyelikOlusturma(b,uye,biletAdet);
                    break;

            case 2: UyelikliYolcuSil(b,i,uye);
                    break;

            case 3: UyelikliYolcuAra(b,i,uye);
                    break;

            case 4: UyelikliYolcuGuncelle(b,i,uye);
                    break;

            default: main();

        }
    }

    else{
system("cls");

        printf("Islemlerinize uyeliksiz yolculuk uzerinden devam ediliyor..\n\n");
        delay(1500);
        printf("\n< 1 > Uyeliksiz Yolcu Kaydet..\n< 2 > Uyeliksiz Yolcu Sil..\n< 3 > Uyeliksiz Yolcu Ara..\n< 4 > Uyeliksiz Yolcu Guncelle..");
        printf("\n\nSeciminiz: ");
        scanf("%d", &secim);

system("cls");

        switch(secim)
        {
            case 1: UyeliksizYolcuKaydetme(b);
                    break;

            case 2: UyeliksizYolcuSil(b,i,y);
                    break;

            case 3: UyeliksizYolcuAra(b,i,y);
                    break;

            case 4: UyeliksizYolcuGuncelle(b,i,y);
                    break;

            default: main();

        }
    }
}
