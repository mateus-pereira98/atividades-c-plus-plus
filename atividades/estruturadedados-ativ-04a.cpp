/*          												Avaliação/Tarefa
Altere o programa3.cpp, insira o void exibir() para listar os dados do struct na tela e o  void  bolha()  para  classificar  os  nomes  em  ordem  alfabética, 
não  esqueça  que cada nome que mudar de lugar deverá ter a sua chave também alterada de lugar.
*/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
const int n = 5;           
int linha = -1;

struct tabela {    
 int chave; 
 string nome;
 };
 
 struct tabela tb1[n];
 //método para ler a chave, onde ela ñ pode ser igual a uma ja digitada, se for, ficará repetindo o pedido de nova chave, com goto...
 int lerchave() {
 mat:
 int ch; 	
 cout << "\nDigite a chave:";
 cin >> ch;
 for(int pos=0; pos < n; pos++) {
 	if(ch == tb1[pos].chave) {
 		cout << "\nA chave já existe, tente outra. ";
 		system("pause");
 		system("cls");
 		goto mat;
	 }
 }
 return ch;
 }
 
 //método para ler o nome
 string lernome() {
 string x;
 cout << "\nDigite nome:"; 
 cin>> x; 
 
 return x;
 }
 
 //método para realizar um registro no struct
 void novoregistro() {   
 linha ++; 
 tb1[linha].chave = lerchave();
 cin.ignore();
 string nome_= lernome(); 
 tb1[linha].nome = nome_;
}
//método para buscar uma chave.
int buscaseq (int valor){  
	for (int i=0; i <= linha; i++ )  {      
	 if ( valor == tb1[i].chave )  
	 return i; 
	}     
	return -1;  
}

//método para exibir o vetor. |nome e chave|
void exibir() {
	for(int pos=0; pos < n; pos++) {
		cout <<" Nome.....: " << tb1[pos].nome << " - " << " Chave......: " << tb1[pos].chave << endl;	
	}
}

//método para ordernar em ordem alfabetica, e manter as chaves digitadas aos respectivos nomes.
void bolha() {
	string aux;
	int auxC;
	for(int lin=0; lin <= n-2; lin++){
		for(int col=lin; col<=n-1; col++) {
			if(tb1[lin].nome > tb1[col].nome) {
				aux = tb1[lin].nome;
				tb1[lin].nome = tb1[col].nome;
				tb1[col].nome = aux;
				
				auxC = tb1[lin].chave;
				tb1[lin].chave = tb1[col].chave;
				tb1[col].chave = auxC;
			}
		}
	}
}

int main() { 
setlocale(LC_ALL, "Portuguese") ;
int tecla =0, mychave, indice;
	//menu principal
    while (tecla != 5) { 
        system("cls");  
         // FEITO POR: MATEUS DA SILVA PEREIRA | FATEC ZONA SUL |  3º SEMESTRE - ESTRUTURA DE DADOS" 
        cout << "\n 1 - Registrar\n 2 - Buscar\n 3 - Exibir\n 4 - Exibir em Ordem\n 5 - Sair " << endl;  
        cin >> tecla;
		switch(tecla){
			case 1: 
				system("cls");
 				novoregistro();
  			break;
  		
  			case 2: 
  				system("cls");
  				cout << "\nDigite a chave da pessoa:";            
  				cin>> mychave;             
  				indice = buscaseq(mychave);
  		
  				if (indice == -1 ) {
					cout << "\nChave inexistente!\n"; 
					system("pause");
				}else {
					cout << "\nO nome '" <<tb1[indice].nome << "' foi encontrada na posição'"<< indice << "'\n";                
   					system("pause"); 
				}              
  			break;
  		
  			case 3:
  				system("cls");
  				exibir();
  				system("pause");
  			break;
  	
	  		case 4:
	  			system("cls");
  				bolha();
  				exibir();
  				system("pause");
  			break;
		 
			default:
				system("cls");
				cout << "Finalizando o programa..."  << endl;
				return 0;
			break;   
  		} 
	}	  
	system("pause");
 	exit(0);
 }
 
