

int tab[9][9];
char wczyt;

int sprawdzanie (int x , int y , int a)
{
    for (int i = 0; i < 9; i++)
    {
        if (tab[i][y] == a)
        {
            return 0;
        }

        if (tab[x][i] == a)
        {
            return 0;
        }
    }

    int f = x / 3;
    int g = y / 3;

    for (int i = 3 * f; i < 3 * f + 3; i++)
    {
        for (int j = 3 * g; j < 3 * g + 3; j++)
        {
            if (tab[i][j] == a)
            {
                return 0;
            }
        }
    }

    return 1;
}
void reku (int x , int y)
{
    if (x == 0 && y == 9)
    {
        for (int m = 0; m < 9; m++)
        {
            for (int n = 0; n < 9; n++)
            {
                printf ("%d " , tab[n][m]);
            }
            printf ("\n");
        }
        exit (0);
    }

    if (tab[x][y] == 0)
    {
        for (int h = 1; h < 10; h++)
        {
            if (sprawdzanie (x , y , h))
            {
                tab[x][y] = h;
                reku (x , y);
            }
        }

        tab[x][y] = 0;
    }

    else if (x == 8)
    {
        reku (0 , y + 1);
    }

    else
    {
        reku (x + 1 , y);
    }

    return;

}

int main ()
{


    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf ("%c" , &wczyt);

            if (wczyt != '*')
            {
                tab[j][i] = atoi (&wczyt);
            }
        }
    }

    // reku (0 , 0);
    for (int m = 0; m < 9; m++)
    {
        for (int n = 0; n < 9; n++)
        {
            printf ("%d " , tab[n][m]);
        }
        printf ("\n");
    }




}