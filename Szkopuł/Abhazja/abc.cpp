#include <iostream>
#include <vector>

using namespace std;

int im, id;
int odp;
struct G{
	bool odwiedzone;
	vector<int> krawedzie;
};

G graf[2000000];

int a, b;

void DFS(int punkt){
	graf[punkt].odwiedzone = 1;

	for(auto j:graf[punkt].krawedzie){
		if(graf[j].odwiedzone == 0){
			DFS(j);
		}
	}
}

int main(){
	cin>>im>>id;

	for(int i =0; i<id; i++){
		cin>>a>>b;
		graf[a].krawedzie.push_back(b);
		graf[b].krawedzie.push_back(a);
	}

	for(int i =1; i<im+1; i++){
		if(graf[i].odwiedzone == 0){
			DFS(i);
			odp++;
		}
	}

	cout<<odp;



}

