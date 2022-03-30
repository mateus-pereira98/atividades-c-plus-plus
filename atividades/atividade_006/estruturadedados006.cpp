#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int elem = 10;
int linha = -1;

struct Clientes {
	string Nome;
	double Salario;
	string Telefone;	
};

struct Clientes cts[elem];

string LerNome() {
	string nome;
	cout << "Digite o seu nome : ";
	cin  >> nome;
	return nome;
}

double LerSalario() {
	double salario;
	cout << "Digite o seu salário : ";
	cin  >> salario;
	return salario;
}

string LerTelefone() {
	string telefone;
	cout << "Digite o seu telefone [(11)1111-1111]: ";
	cin  >> telefone;
	return telefone;
}

void NovoRegistro() {
	linha++;
	cts[linha].Nome = LerNome();
	cts[linha].Salario = LerSalario();
	cts[linha].Telefone = LerTelefone();
}

void Exibir() {
	for(int pos=0; pos < elem; pos++) {
		cout << "Nome...... : " << cts[pos].Nome << " | Salário...... : " << cts[pos].Salario << " | Telefone...... : " << cts[pos].Telefone << endl;
	}
}

void Classificar() {
	string auxN, auxT;
	double auxS;

	for(int l=0; l < elem; l++) {
		for(int c=0; c < elem; c++) {
			if(cts[l].Nome < cts[c].Nome) {
				auxN = cts[l].Nome;
				cts[l].Nome = cts[c].Nome;
				cts[c].Nome = auxN;
				
				auxS = cts[l].Salario;
				cts[l].Salario = cts[c].Salario;
				cts[c].Salario = auxS;
				
				
				auxT = cts[l].Telefone;
				cts[l].Telefone = cts[c].Telefone;
				cts[c].Telefone = auxT;
			}
		}
	}
}

int BuscaSequencial(string nome) {
	for(int pos=0; pos < elem; pos++) {
		if(nome == cts[pos].Nome) {
			return pos;
		}
	}
	return -1;
}

int BuscaBinaria(string nome) {
	int inicio = 0;
	int tam_vetor = elem-1;
	int posicao = 0;
	
	while(inicio <= tam_vetor) {
		posicao = (inicio + tam_vetor)/2;
	
		if(cts[posicao].Nome == nome) {
			return posicao;
		} else {
			inicio = posicao + 1;
		}
	}
	return -1;
}

void Menu() {
	
	int indice, caso;
	string nome;
	
	system("cls");
	
	while(caso != 6) {
		cout << " ================================== MENU PRINCIPAL ================================== " << endl;
		cout << " 1 - LER DADOS " << endl;
		cout << " 2 - LISTAR REGISTROS " << endl;
		cout << " 3 - CLASSIFICAR POR NOME " << endl;
		cout << " 4 - BUSCA SEQUENCIAL " << endl;
		cout << " 5 - BUSCA BINÁRIA " << endl;
		cout << " 6 - SAIR " << endl;
		cin  >> caso;
		
		switch(caso) {
			case 1: 
				system("cls");
				NovoRegistro();
				system("cls");
			break;
		
			case 2: 
				system("cls");
				Exibir();
				system("pause");
				system("cls");
			break;
		
			case 3:
				system("cls");
				Classificar();
				Exibir();
				system("pause");
				system("cls");
			break;
		
			case 4:
				system("cls");
				cout << "Digite um nome para buscar: ";
				cin  >> nome;
				indice = BuscaSequencial(nome);
				if(indice == -1) {
					cout << "Nome não registrado. " << endl;
				} else {
					for(int pos = 0; pos < elem; pos++) {
						if(nome == cts[pos].Nome) {
							cout << "Nome : " << cts[pos].Nome << " | Salário : " << cts[pos].Salario << " | Telefone : " << cts[pos].Telefone << endl;
						}
					}
				}
				system("pause");
				system("cls");
			break;
		
			case 5:
				system("cls");
				cout << "Digite um nome para buscar: ";
				cin  >> nome;
				
				indice = BuscaBinaria(nome);
				if(indice == -1) {
					cout << "Nome não registrado. " << endl;
				} else {
					for(int pos=0; pos < elem; pos++) {
						if(nome == cts[pos].Nome) {
							cout << "Nome : " << cts[pos].Nome << " | Salário : " << cts[pos].Salario << " | Telefone : " << cts[pos].Telefone << endl;	
						}
					}
				}
				system("pause");
				system("cls");
			break;
		
			case 6:
				system("cls");
				cout << "Saindo do programa... " << endl;
				system("pause");
				system("cls");
			break;
			
			default:
				exit(0);
			break;
		}
	}
}


int main() {
	setlocale(LC_ALL, "Portuguese");
	Menu();	
	return 0;
}
