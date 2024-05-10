#include <iostream>

using namespace std;

const int righeMax=3;
const int colonneMax=4;

//prototipi
void caricaMatrice(int matrix[righeMax][colonneMax]);
void visualizzaMatrice(int matrix[righeMax][colonneMax]);
void caricaVC(int matrix[righeMax][colonneMax], int vc[colonneMax]);
int Menu();

int main() {

  int scelta;
  int matrix[righeMax][colonneMax];
  int VC[colonneMax];

  do {
    scelta=Menu();
    switch(scelta) {
      case 1:
        caricaMatrice(matrix);
      break;
      case 2:
        visualizzaMatrice(matrix);
      break;
      case 3:
        caricaVC(matrix,VC);
      break;
      case 0:
        cout<<"Esci"<<endl;
      break;
      default:
        cout<<"Attenzione, scelta sbagliata!"<<endl;
      break;
    }
  }while(scelta!=0);

}


int Menu() {
  int scegli;
  cout<<"-----------------MENU-----------------"<<endl;
  cout<<"1-Carica matrice"<<endl;
  cout<<"2-Visualizza matrice"<<endl;
  cout<<"3-Visualizza colonna con somma maggiore"<<endl;
  cout<<"0-Fine"<<endl;
  cout<<"Scegli un operazione: "<<endl;
  cin>>scegli;

  return scegli;
}


void caricaMatrice(int matrix[righeMax][colonneMax]) {

  cout<<endl;

  for(int i=0; i<righeMax; i++) {
    for(int j=0; j<colonneMax; j++) {
      cout<<"Inserisci il valore della cella "<<i+1<<" "<<j+1<<": ";
      cin>>matrix[i][j];
    }
  }


  cout<<endl;

}

void visualizzaMatrice(int matrix[righeMax][colonneMax]) {

  cout<<endl;

  for(int i=0; i<righeMax; i++) {
    for(int j=0; j<colonneMax; j++) {
      cout<<matrix[i][j]<<"\t";
    }
    cout<<endl;
  }

  cout<<endl;

}



void caricaVC(int matrix[righeMax][colonneMax], int vc[colonneMax]) {


  int somma=0;
  int valMax=vc[0];
  int col=0;

  for(int i=0; i<colonneMax; i++) {
    somma=0;
    for(int j=0; j<righeMax; j++) {
      somma=somma+matrix[j][i];
      vc[i]=somma;
    }
  }

  for(int i=0; i<colonneMax; i++) {
    if(vc[i]>valMax) {
      valMax=vc[i];
      col=i;
    }
  }

  cout<<endl;

  cout<<"La colonna "<<col+1<<" ha la somma maggiore che e' : "<<valMax<<endl;

  cout<<endl;
}
