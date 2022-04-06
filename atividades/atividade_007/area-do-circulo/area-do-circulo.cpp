#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double *pRaio;
const double pi = 3.14;

void AreaCirculo(double raio) {
	double area;
	area = pi * (raio * raio);
	cout << "�rea do c�rculo � de : " << area << endl;	
}

void Menu() {
	int  caso;
	
	system("cls");
	
	while(caso != 3) {
		cout << "\n **************************************************** MENU PRINCIPAL ************************************************** " << endl;
		cout << " 1 - CALCULAR �REA DO C�RCULO " << endl;
		cout << " 2 - SAIR " << endl;
		cout << " ************************************************************************************************************************ " << endl;
		cin  >> caso;
		switch(caso) {
	
			case 1:
				system("cls");
				double raio;
				cout << "Digite o raio : ";
				cin  >> raio;
				pRaio = &raio;
				AreaCirculo(*pRaio);
				system("pause");
				system("cls");
			break;
	
			case 2:
				system("cls");
				cout << "Saindo do programa... " << endl;
				system("cls");
				exit(0);
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
	//FEITO POR: MATEUS DA SILVA PEREIRA | FATEC ZONA SUL | 3� SEMESTRE - ESTRUTURA DE DADOS
	system("pause");
	return 0;
}
