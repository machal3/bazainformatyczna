#include <iostream>
using namespace std;

long long bierzemy;
long long niebierzemy;
long long starebierzemy;
long long stareniebierzemy;
int wczyt;
int ilosc_marchewek;

long long wieksze(long long a, long long b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}


int main(){
	cin>>ilosc_marchewek;

	for(int i = 1; i<ilosc_marchewek+1; i++){
		cin>>wczyt;
		starebierzemy = bierzemy;
		stareniebierzemy = niebierzemy;
		bierzemy = stareniebierzemy + wczyt;
		niebierzemy = wieksze(stareniebierzemy, starebierzemy); 
	}

	cout<<wieksze(bierzemy, niebierzemy);

}
