#include <iostream>
#include <algorithm>
using namespace std;

int tab[10000000];
int ilosc_kandydatow;

bool por(int a, int b){
	return a>b;
}

int main(){
	cin>>ilosc_kandydatow;

	for(int i =0; i<ilosc_kandydatow; i++){
		cin>>tab[i];
	}

	sort(tab, tab+ilosc_kandydatow, por);

	for(int i =0; i<10; i++){
		cout<<tab[i]<<" ";
	}
}
