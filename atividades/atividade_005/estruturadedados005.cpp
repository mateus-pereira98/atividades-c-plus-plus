#include <iostream>
#include <cmath>
#include <string>
using namespace std;
const int tam = 5;
int linha = -1;

struct tabela{
	int tempoT; // em anos.
	double salario; 
	string prof;
};

struct tabela tbl[tam];
//m�todo para ler o tempo de trabalho.
int LerTempo() {
	int tempo;
	cout << "\nDigite o tempo de trabalho [em anos]:  ";
	cin  >> tempo;
	return tempo;
}
//m�todo para ler o sal�rio.
double LerSalario() {
	double salario;
	cout << "\nDigite o sal�rio : ";
	cin  >> salario;
	return salario;
}
//m�todo para ler o nome da profiss�o.
string LerProfissao() {
	string prof;
	cout << "\nQual a sua profiss�o : ";
	cin  >> prof;
	return prof;
}
//m�todo para adicionar o tempo e o sal�rio nas colunas do struct.
void NovoRegistro() {
	linha++;
	tbl[linha].tempoT = LerTempo();
	tbl[linha].salario = LerSalario();
	tbl[linha].prof = LerProfissao();	
}
//m�todo bolha para classificar em ordem crescente.
void Classificar() {
	int aux;
	double auxS;
	string auxP;
	for(int l=0; l < tam; l++) {
		for(int c=l; c < tam; c++) {
			if(tbl[l].tempoT > tbl[c].tempoT) {
				
				aux = tbl[l].tempoT;
				tbl[l].tempoT = tbl[c].tempoT;
				tbl[c].tempoT = aux;
				
				auxS = tbl[l].salario;
				tbl[l].salario = tbl[c].salario;
				tbl[c].salario = auxS;	
				
				auxP = tbl[l].prof;
				tbl[l].prof = tbl[c].prof;
				tbl[c].prof = auxP;
			}
		}
	}
}
//m�todo de busca bin�ria, para encontrar um tempo de trabalho no vetor.
int BuscaBinaria(int buscar) {
	int inicio = 0;
	int tam_vetor = tam-1;
	int posicao = 0;
	
	while(inicio <= tam_vetor) {
		posicao = (inicio + tam_vetor)/2;
		if(tbl[posicao].tempoT == buscar){
			return posicao;
		}else {
			if(tbl[posicao].tempoT > buscar) {
				tam_vetor = posicao -1;
			}else {
				inicio = posicao +1;
			}
		}
	}
	return -1;
}
//m�todo para exibir o vetor.
void Exibir() {
	for(int pos=0; pos < tam; pos++) {
		cout << "\nTempo de trabalho : " << tbl[pos].tempoT << " ano(s) de trabalho | Sal�rio : " << tbl[pos].salario << " | Profiss�o : " << tbl[pos].prof << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	int menu=0, indice;
	//menu principal
	while(menu != 5) {
		system("cls");
		//FEITO POR: MATEUS DA SILVA PEREIRA | FATEC ZONA SUL | 3� SEMESTRE - ESTRUTURA DE DADOS 
		cout << "\n 1 - Registrar \n 2 - Buscar tempo de trabalho \n 3 - Exibir \n 4 - Classificar por tempo \n 5 - Sair " << endl; 
		cin  >> menu;
		switch(menu){
			case 1:
				system("cls");
				NovoRegistro();
			break;
			
			case 2:
				Classificar();
				system("cls");
				int tempo;
				cout << "\nDigite o tempo de servi�o : ";
				cin  >> tempo;
				system("cls");
				indice = BuscaBinaria(tempo);
				if(indice == -1) {
					cout << "\nTempo de trabalho n�o existente! " << endl;
				}else {
						for(int pos=0; pos < tam; pos++) {
							if(tempo == tbl[pos].tempoT) {
							cout << tempo << " ano(s) de trabalaho | Sal�rio : " << tbl[pos].salario << " | Profiss�o : " << tbl[pos].prof << endl;
							}
						}
					}
				system("pause");
			break;
			
			case 3:
				system("cls");
				Exibir();
				system("pause");
			break;
			
			case 4: 
				system("cls");
				Classificar();
				Exibir();
				system("pause");
			break;
			
			case 5:
				system("cls");
				cout << " Finalizando programa... " << endl;
			break;
			
			default:
				system("cls");
				exit(0);
			break;
		}
	}
	system("pause");
	return 0;
}
