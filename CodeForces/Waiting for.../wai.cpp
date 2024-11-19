#include <iostream>
using namespace std;

long long przystanek;
int n;
char wczyt_char;
int wczyt_int;

int main(){
	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> wczyt_char >> wczyt_int;

		if(wczyt_char == 'P'){
			przystanek += wczyt_int;
		}
		
		else{
			if(przystanek - wczyt_int < 0){
				cout << "YES \n";
				przystanek = 0;
			}
			else{
				cout<< "NO \n";
				przystanek -= wczyt_int;
			}
		}

	}

}


		
