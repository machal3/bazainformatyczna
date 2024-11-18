#include <iostream>
using namespace std;

bool tab[1000];
string wczyt;
int dlugosc;
int rozne;

int main(){
	cin >> wczyt;	

	dlugosc = wczyt.length();

	for(int i = 0; i < dlugosc; i++){
		if(tab[wczyt[i] - 'a'] == 0){
			tab[wczyt[i] - 'a'] = 1;
			rozne++;
		}
	}

	if(rozne % 2 == 1){
		cout << "IGNORE HIM!";
	}
	else{
		cout << "CHAT WITH HER!";
	}
}


