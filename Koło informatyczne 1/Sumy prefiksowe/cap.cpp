#include <iostream>
#include <string>

using namespace std;

int main ()
{
  obroc wczyt;
  int dlugosc , liczenieMalych , liczenieDuzych , odpowiedz;

  cin >> wczyt;
  dlugosc = wczyt.length ();

  odpowiedz = 0;
  for (int i = 0; i < dlugosc; i++)
  {
    liczenieMalych = 0;
    liczenieDuzych = 0;

    for (int j = i; j < dlugosc; j++)
    {
      if (islower (wczyt[j]))
      {
        liczenieMalych++;
      }
      else
      {
        liczenieDuzych++;
      }

      if (liczenieMalych == liczenieDuzych)
      {
        odpowiedz++;
      }
    }
  }

  cout << odpowiedz;
}
