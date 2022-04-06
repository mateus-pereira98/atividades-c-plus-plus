#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int *pA, *pB, *pC, a, b, c;

void LerDados() {	
	cout << "Digite o valor de A: ";
	cin  >> a;
	cout << "Digite o valor de B: ";
	cin  >> b;
	cout << "Digite o valor de C: ";
	cin  >> c;
	
	pA = &a;
	pB = &b;
	pC = &c;
}

void FormulaHeron(int a, int b, int c) {
	double p = (a + b + c) / 2;
	double area = sqrt(p*(p-a)*(p-b)*(p-c));
	cout << setprecision(4);
	cout << "\nValor de P : " << p << endl;
	cout << "\nÁrea do triangulo : " << area << endl;
}

void Menu() {
	int caso;
	while(caso != 4) {
		cout << "\n **************************************************** MENU PRINCIPAL ************************************************** " << endl;
		cout << " 1 - LER DADOS " << endl;
		cout << " 2 - TRIÂNGULO DE HERON " << endl;
		cout << " 3 - SAIR " << endl;
		cout << " *********************************************************************************************************************** " << endl;
		cin  >> caso;
		switch(caso) {
			case 1: 
				system("cls");
				LerDados();
				system("cls");
			break;
			
			case 2:
				system("cls");
				FormulaHeron(*pA, *pB, *pC);
				system("pause");
				system("cls");
			break;
	
			case 3:
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
	//FEITO POR: MATEUS DA SILVA PEREIRA | FATEC ZONA SUL | 3º SEMESTRE - ESTRUTURA DE DADOS
	return 0;
}
