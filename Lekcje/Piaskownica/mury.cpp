#include <stdio.h>

int muryodgury[2000002];
int muryoddolu[2000002];

int najmniej = 1000000000;
int iloscnajmniej;

int imury , szerokosc , wczyt;

int main () {

    scanf ("%d" , &imury);
    scanf ("%d" , &szerokosc);

    for (int i = 0; i < imury; i++) {
        scanf ("%d" , &wczyt);
        if (i % 2 == 0) {
            muryoddolu[wczyt]++;
        }
        else {
            muryodgury[szerokosc - wczyt + 1]++;
        }
    }

    for (int i = 1; i < szerokosc + 1; i++) {
        muryodgury[i] += muryodgury[i - 1];
        muryoddolu[szerokosc - i + 1] += muryoddolu[szerokosc - i + 2];
    }


    for (int i = 1; i < szerokosc + 1; i++) {
        if ((muryoddolu[i] + muryodgury[i]) < najmniej) {
            najmniej = (muryoddolu[i] + muryodgury[i]);
            iloscnajmniej = 1;
        }

        else if ((muryoddolu[i] + muryodgury[i]) == najmniej) {
            iloscnajmniej++;
        }
    }

    printf ("%d " , najmniej);
    printf ("%d" , iloscnajmniej);



}
