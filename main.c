#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void studentinfo() {
    printf(" Ad Soyad: Johnny BRAVO\n Ogrenci numarasi: 123456\n Sube: A\n Sinif derecesi: 6\n Bolum: Sayisal\n");
}

void passwordchange(char password[8]) {
    printf("Yeni sifreyi girin: ");
    scanf("%s", password);
    printf("Sifre degistirildi! Yeniden oturum acin!\n\n");
}

int main() {
    char studentnumber[6], password[8];
    int i = 0;
    int righttotry = 5;
    int aytresult[7] = {28, 33, 39, 46, 51};
    int tytresult[7] = {60, 68, 75, 88, 97};
    int chemical[7] = {12, 18, 0, 23, 29};
    int biology[7] = {16, 21, 23, 28, 32};
    int physical[7] = {6, 11, 18, 22, 27};
    int maths[7] = {21, 26, 29, 32, 33};
    int secim;

    printf("Ogrenci numarasi:");
    scanf("%s", &studentnumber);

    while (strcmp(studentnumber, "123456") != 0) {
        printf("Veri girisi yanlis!\n\n");
        printf("Ogrenci numarasi:");
        scanf("%s", &studentnumber);
    }

    if (strcmp(studentnumber, "123456") == 0) {
        while (righttotry > 0) {
            printf("Sifre:");
            scanf("%s", &password);

            if (strcmp(password, "85237412") == 0) {
                printf("Siteye hosgeldiniz.\n\n");
                break;
            } else
                printf("Sifre yanlis! Kalan deneme hakki:%d\n", --righttotry);
        }

        if (righttotry == 0) {
            printf("Hesap bloke!!!\n");
            return 0;
        }
    }

    /* ANA MENÜ */
    while (1) {
        printf("1-DERS DENEME NETLERI\n");
        printf("2-DENEME SONUCLARI\n");
        printf("3-OGRENCI BILGILERI\n");
        printf("4-SIFRE DEGISTIR\n");
        printf("5-OTURUMU SONLANDIR\n\n");
        printf("SECIM YAPIN:\n");
        scanf("%d", &secim);
        printf("\n");

        switch (secim) {
            case 1: /* DERS DENEME NETLERİ ALT MENÜ */
                while (1) {
                    printf("\n1-KIMYA\n");
                    printf("2-BIYOLOJI\n");
                    printf("3-FIZIK\n");
                    printf("4-MATEMATIK\n");
                    printf("5-ANA MENUYE DON\n\n");
                    printf("DERS SECIMI YAPIN:\n");
                    scanf("%d", &secim);

                    if (secim == 5) {
                        printf("\nAna Menu\n");
                        break;
                    }

                    switch (secim) {
                        case 1:
                            for (i = 0; i < 7; i++) {
                                printf("\n%d. kimya ders neti:%d\n", i + 1, chemical[i]);
                            }
                            break;
                        case 2:
                            for (i = 0; i < 7; i++) {
                                printf("\n%d. biyoloji ders neti:%d\n", i + 1, biology[i]);
                            }
                            break;
                        case 3:
                            for (i = 0; i < 7; i++) {
                                printf("\n%d. fizik ders neti:%d\n", i + 1, physical[i]);
                            }
                            break;
                        case 4:
                            for (i = 0; i < 7; i++) {
                                printf("\n%d. matematik ders neti:%d\n", i + 1, maths[i]);
                            }
                            break;
                        case 5:
                            printf("ana menü yükleniyor\n");
                            break;
                        default:
                            printf("Ders seciminiz geçersiz. Gecerli bir secim yapin.\n\n");
                    }
                }
                break;

            case 2: /* DENEME SONUÇLARI ALT MENÜ */
                while (1) {
                    printf("\n1-AYT Deneme sonuclari\n");
                    printf("2-TYT Deneme sonuclari\n");
                    printf("3-ANA MENUYE DON\n");
                    printf("\nSECIM YAPIN:\n\n");
                    scanf("%d", &secim);

                    if (secim == 3) {
                        printf("Ana Menu\n");
                        break;
                    }

                    switch (secim) {
                        case 1:
                            for (i = 0; i < 7; i++) {
                                printf("\n%d. ayt deneme sonucu:%d\n", i + 1, aytresult[i]);
                            }
                            break;
                        case 2:
                            for (i = 0; i < 7; i++) {
                                printf("\n%d. tyt deneme sonucu:%d\n", i + 1, tytresult[i]);
                            }
                            break;
                        case 3:
                            printf("Ana Menu\n");
                            break;
                        default:
                            printf("Seciminiz gecersiz. Gecerli bir secim yapin.\n\n");
                    }
                }
                break;

            case 3: /* ÖĞRENCİ BİLGİLERİ ALT MENÜ */
                studentinfo();
                printf("\n");
                break;

            case 4: /* ŞİFRE DEĞİŞTİRME */
                passwordchange(password);

                while (righttotry > 0) {
                    char enteredPassword[8];

                    printf("Yeni sifrenizi girin: ");
                    scanf("%s", enteredPassword);

                    if (strcmp(enteredPassword, password) == 0) {
                        printf("\nSiteye hosgeldiniz!\n");
                        break;
                    } else {
                        printf("Yanlis sifre! Kalan giris hakki:%d\n", --righttotry);
                    }
                }

                if (righttotry == 0) {
                    printf("Hesap bloke!!!\n");
                    return 0;
                }
                break;

            case 5: /* OTURUMU SONLANDIR */
                printf("Oturum Sonlandirildi.\n");
                return 0;

            default:
                printf("Seciminiz gecersiz. Tekrar secim yapin.\n\n");
        }
    }

    return 0;
}
