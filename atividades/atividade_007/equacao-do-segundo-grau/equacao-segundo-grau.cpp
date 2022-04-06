#include <iostream>
#include <cmath>

using namespace std;
double *pA, *pB, *pC, a, b, c;


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

void Calcular(double a, double b, double c) {
	double x1, x2, delta;
	if(a != 0) {
        delta = (b*b) - (4*a*c);

        if(delta < 0) {
            cout <<"\nNão tem raízes reais! " << endl;
        } else if (delta == 0) {
            x1 = (-b)/(2*a);
            cout << "\nPossui apenas uma raiz real : "<< x1 << endl;
        } else {
            x1 = (-b + sqrt(delta))/(2*a);
            x2 = (-b - sqrt(delta))/(2*a);
            cout << "\nDelta :  " << delta << endl;
            cout << "\nRaiz 1 : " << x1 << endl;
            cout << "\nRaiz 2 : " << x2 << endl;
        }
    } else {
        cout <<"(A = 0) - NÃO É UMA EQUAÇÃO DO SEGUNDO GRAU ! " << endl;;
      }
}

void Menu() {
	int caso;
	while(caso != 4) {
		cout << "\n **************************************************** MENU PRINCIPAL ************************************************** " << endl;
		cout << " 1 - LER DADOS " << endl;
		cout << " 2 - CALCULAR  " << endl;
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
				Calcular(*pA, *pB, *pC);
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
