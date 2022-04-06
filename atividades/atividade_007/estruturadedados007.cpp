#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int *pA, *pB, *pC;
double *pRaio;
const double pi = 3.14;

void LerDados() {
	int a, b, c;
	
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

void Calcular(int a, int b, int c) {
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
            cout << "\nRaiz 1 : "<< x1 << endl;
            cout << "\nRaiz 2 : "<< x2 << endl;
        }
    } else {
        cout <<"(A = 0) - NÃO É UMA EQUAÇÃO DO SEGUNDO GRAU ! " << endl;;
      }
}

void FormulaHeron(int a, int b, int c) {
	double p = (a + b + c) / 2;
	double area = sqrt(p*(p-a)*(p-b)*(p-c));
	cout << setprecision(4);
	cout << "Área do triangulo : " << area << endl;
}

void AreaCirculo(double raio) {
	double area;
	area = pi * (raio * raio);
	cout << "Área do círculo é de : " << area << endl;	
}

void Menu() {
	int  caso;
	
	system("cls");
	
	while(caso != 6) {
		cout << "\n **************************************************** MENU PRINCIPAL ************************************************** " << endl;
		cout << " 1 - EQUAÇÃO DO SEGUNDO GRAU " << endl;
		cout << " 2 - TRIÂNGULO DE HERON " << endl;
		cout << " 3 - ÁREA DO CÍRCULO  " << endl;
		cout << " 4 - SAIR " << endl;
		cout << " *********************************************************************************************************************** " << endl;
		cin  >> caso;
		switch(caso) {
			case 1: 
				system("cls");
				LerDados();
				Calcular(*pA, *pB, *pC);
				system("pause");
				system("cls");
			break;
		
			case 2: 
				system("cls");
				LerDados();
				FormulaHeron(*pA, *pB, *pC);
				system("pause");
				system("cls");
			break;
			
			case 3:
				system("cls");
				double raio;
				cout << "Digite o raio : ";
				cin  >> raio;
				pRaio = &raio;
				AreaCirculo(*pRaio);
				system("pause");
				system("cls");
			break;
	
			case 4:
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
	system("pause");
	return 0;
}
