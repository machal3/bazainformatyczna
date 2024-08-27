#include <iostream>
#include <vector>
using namespace std;

struct G{
	bool odwiedzone;
	int rodzina;
	vector <int> krawedzie;
};

G graf[100000];
int ilosc_zapytan;
int ilosc_drog;
int ilosc_miast;
int a, b;

void DFS(int punkt, int rodzina){
	graf[punkt].odwiedzone =1;
	graf[punkt].rodzina = rodzina;

	for(auto j : graf[punkt].krawedzie){
		if(graf[j].odwiedzone == 0){
			DFS(j, rodzina);
		}
	}
	return;
}

int main(){
	cin>>ilosc_miast>>ilosc_drog;

	for(int i =0; i<ilosc_drog; i++){
		cin>>a>>b;
		graf[a].krawedzie.push_back(b);
		graf[b].krawedzie.push_back(a);	
	}

	for(int i = 1; i < ilosc_miast + 1; i++){
		if(graf[i].odwiedzone==0){
			DFS(i, i);
		}
	}

	cin>>ilosc_zapytan;

	for(int i =0 ; i<ilosc_zapytan; i++){
		cin>>a>>b;
		if(graf[a].rodzina == graf[b].rodzina){
			cout<<"TAK\n";
		}
		else{
			cout<<"NIE\n";
		}
	}

}
