#include <iostream> 
#include <vector>
using namespace std;

int n, a, odp = 0;

vector <int> T[1000000];
bool tab[30000];

void costam(int zmienna){
    tab[zmienna] = true;

    for (int i = 0; i < T[zmienna].size(); i++) {
        int b = T[zmienna][i];
        if (tab[b]==0) {
            costam(b);
        }
            
    }
}

int main(){
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        T[i].push_back(a);
        T[a].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        if (tab[i]==0) {
            odp++;
            costam(i);
        }
    }

    cout << odp << endl;
}
