#include <iostream>
#include <cmath>
#include <string>
#define tam 3
using namespace std;

struct lifo{
	int idade[tam];
	double salario[tam]; 
	string nome[tam];
	int topo;
};

string LerNome() {
	string nome;
	cout << "\nDIGITE SEU NOME : ";
	cin  >> nome;
	return nome;
}

int LerIdade() {
	int idade;
	cout << "\nQUAL A SUA IDADE :  ";
	cin  >> idade;
	return idade;
}

double LerSalario() {
	double salario;
	cout << "\nQUAL O SEU SALÁRIO : ";
	cin  >> salario;
	return salario;
}

bool pilhaCheia(lifo p) {
	if (p.topo == tam - 1) {
		return true;
	} return false;
}

bool pilhaVazia(lifo p) {
	if (p.topo == -1) {
		return true;
	} return false;
}

lifo push(string nome, int idade, double salario, lifo p) {
	if (pilhaCheia(p) == true) {
		cout << "\nNÃO TEM COMO ADICIONAR - PILHA CHEIA\n";
		system("pause");
		return p;
	}
	
	p.topo++;
	p.nome[p.topo] = nome;
	p.salario[p.topo] = salario;
	p.idade[p.topo] = idade;
	return p;
}

lifo pop (lifo p) {
	if (pilhaVazia(p) == true) {
		cout << "\nNÃO TEM COMO DELETAR - PILHA ESTÁ VAZIA" << endl;
		system("pause");
		return p;
	}

	cout << "\n O VALOR DESEMPILHADO SERÁ - NOME : " << p.nome[p.topo] << endl;
	cout << "\n O VALOR DESEMPILHADO SERÁ - IDADE: " << p.idade[p.topo] << endl;
	cout << "\n O VALOR DESEMPILHADO SERÁ - SALÁRIO: " << p.salario[p.topo] << endl;
	system("pause");
	p.nome[p.topo] = '\0';
	p.salario[p.topo] = '\0';
	p.idade[p.topo] = '\0';
	p.topo--;
	return p;
}

void mostrarPilha(lifo p) {
	if (pilhaVazia(p) == true) {
		cout << "\nNÃO TEM COMO MOSTRAR - A PILHA ESTÁ VAZIA" << endl;
	}
	
	for (int i = p.topo; i >= 0; i--) {
		cout << "\nNOME: " << p.nome[i] << endl;
		cout << "SALÁRIO: " << p.salario[i] << endl;
		cout << "IDADE: " << p.idade[i] << endl;
		cout << endl;
	} 
	system("pause");
}

int tela() {
	int tecla;
	system("cls");
	cout << "      MENU      " << endl;
	cout << "----------------" << endl;
	cout << "\n1 - Push \n2 - Pop \n3 - Mostrar \n4 - Sair";
	cout << "\n----------------";
	cout << "\nItem:";
	cin  >> tecla;
	return tecla;
}

void controlarPilha (lifo p) {
	int tecla, idade;
	double salario;
	string nome;
	
	lifo p1;
	p1.topo = -1;
	
	do {
		tecla = tela();
		
		switch (tecla) {
			case 1: 
				nome = LerNome();
				idade = LerIdade();
				salario = LerSalario();
				p1 = push(nome, idade, salario, p1);
				break;
			case 2: 
				p1 = pop(p1);
				break; 
			case 3: 
				mostrarPilha(p1);
		}
	} while (tecla!= 4);
	cout << "\n Programa Finalizando... \n";
}
int main() {
	setlocale(LC_ALL, "Portuguese");	
		//FEITO POR: MATEUS DA SILVA PEREIRA | FATEC ZONA SUL | 3º SEMESTRE - ESTRUTURA DE DADOS 
	lifo p1;
	controlarPilha(p1);
	return 0;
}
