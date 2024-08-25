#include <iostream>
using namespace std;

#include <stack>

int smiec;
int tab[250000];
int m;
int w;

stack <int> stos;

int main(){
    ios_base::sync_with_stdio(0);
cin.tie(0);

    cin>>m;

    stos.push(0);

    for(int i=0; i<m; i++){
        cin>>smiec>>tab[i];
    }

    for(int i=0; i<m; i++){

        while(true){
            if(tab[i]<stos.top()){
            stos.pop();
            }

            else{
                break;
            }
        }


        if(tab[i]>stos.top()){
            stos.push(tab[i]);
            w++;
        }

    }


    cout<<w;
}
