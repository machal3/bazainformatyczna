#include <iostream>
#include <algorithm>
using namespace std;
int cho = 0;
long long suma;
long long ilosc_kolek , ilosc_prowadzonych;
long long pro[3000000];
long long kol[3000000];

int main ()
{
    cin >> ilosc_kolek >> ilosc_prowadzonych;
    for (int i = 0; i < ilosc_kolek; i++)
    {
        cin >> kol[i];
    }
    for (int i = 0; i < ilosc_prowadzonych; i++)
    {
        cin >> pro[i];
    }

    sort (pro , pro + ilosc_kolek);
    sort (kol , kol + ilosc_prowadzonych);

    for (int i = 0; i < ilosc_prowadzonych; i++)
    {
        if (pro[i] > kol[cho])
        {
            suma += pro[i] - kol[cho];
            cho++;
        }
        if (cho == ilosc_kolek)
        {
            break;
        }
    }

    if (cho != ilosc_kolek)
    {

        cout << "NIE";
        return 0;
    }

    cout << "TAK\n"
        << suma;
}




