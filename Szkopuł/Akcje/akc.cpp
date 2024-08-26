#include <iostream>
using namespace std;

int nk;
int nz = 1000000000;
int id;
int tym;

int main(){

	cin>>id;

	for(int i =0; i<id; i++){
		cin>>tym;
		if(tym<nz){
			nz = tym;
		}
		else if (tym - nz > nk){
			nk = tym - nz;
		}
	}	

	cout<<nk;
}
	
