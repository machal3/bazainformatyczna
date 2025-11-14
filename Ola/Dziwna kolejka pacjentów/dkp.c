#include <stdio.h>
#include <stdlib.h>

#define MAX 10000000

typedef struct
{
    int tab[MAX];
    int rozmiar;
} Kopiec;

void Swap (int* a , int* b)
{
    int tym = *a;
    *a = *b;
    *b = tym;
}

void WGore (Kopiec* kolejka , int i)
{
    if (i && kolejka->tab[(i - 1) / 2] > kolejka->tab[i])
    {
        Swap (&kolejka->tab[(i - 1) / 2] , &kolejka->tab[i]);
        WGore (kolejka , (i - 1) / 2);
    }
}

void push (Kopiec* kolejka , int value)
{
    kolejka->tab[kolejka->rozmiar++] = value;
    WGore (kolejka , kolejka->rozmiar - 1);
}

void WDol (Kopiec* kolejka , int i)
{
    int minim = i;
    int l = 2 * i + 1;
    int p = 2 * i + 2;

    if (l < kolejka->rozmiar
        && kolejka->tab[l] < kolejka->tab[minim])
        minim = l;

    if (p < kolejka->rozmiar
        && kolejka->tab[p] < kolejka->tab[minim])
        minim = p;

    if (minim != i)
    {
        Swap (&kolejka->tab[i] , &kolejka->tab[minim]);
        WDol (kolejka , minim);
    }
}

void pop (Kopiec* kolejka)
{
    int item = kolejka->tab[0];
    kolejka->tab[0] = kolejka->tab[--kolejka->rozmiar];
    WDol (kolejka , 0);
}

int top (Kopiec* kolejka)
{
    return kolejka->tab[0];
}


int n;
int x , y;

int main ()
{
    Kopiec kolejka = { { 0 }, 0 };

    scanf ("%d" , &n);

    while (n--)
    {
        scanf ("%d" , &x);
        if (x == 1)
        {
            scanf ("%d" , &y);

            push (&kolejka , y);
        }
        else
        {
            printf ("%d\n" , top (&kolejka));
            pop (&kolejka);
        }

    }
}

