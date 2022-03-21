/*                                                      Avaliação / Tarefa 
b) - Faça  um  algoritmo  com  struct  e  menu  completo  para  ler  uma  lista  de  NOMES, PESOS, ALTURAS e armazenar o cálculo do índice de massa corpórea, IMC.
Faça um menu com a opções: 1 Ler, processar, 2 exibir tabela, 3 pesquisar por nome, 4 Classificar  por  nome,  5  sair.
Na  opção  pesquisar  por  nome,  faça  uma  pesquisa sequencial para encontrar e exibir o nome da pessoa, seu peso, sua altura e seu IMC  
assim  como  seu  status  de  classificação  de  peso.
Use  as  mensagens  de classificação obtidas no site: http://www.calcularpesoideal.com.br/
*/
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
const int tam = 5;
int linha = -1;

struct tabela  {
	string nome;
	double peso;
	double altura;
	double imc;
	string clasimc;
};

struct tabela tb1[tam];
//método para ler o nome
string lerNome() {
	string n;
	cout << "Digite o seu nome : ";
	cin  >> n;
	return n;
}
//método para ler o peso
double lerPeso() {
	double p;
	cout << "Digite o seu peso : ";
	cin  >> p;
	return p;
}
//método para ler a altura
double lerAltura() {
	double a;
	cout << "Digite a sua altura : ";
	cin  >> a;
	return a;
}
//método para calcular o imc
double calcIMC() {
	double res;
	res = tb1[linha].peso/pow(tb1[linha].altura, 2);
	return res;
}
//método da classificação do imc
string clasIMC() {
	if(tb1[linha].imc < 18.5) {
		string msg = "Abaixo do Peso";
		return msg;
	} else if(tb1[linha].imc <= 24.9) {
		string msg = "Peso Normal";
		return msg;
	}else if(tb1[linha].imc <= 29.9) {
		string msg = "Sobrepeso";
		return msg;
	}else if(tb1[linha].imc <= 34.9) {
		string msg = "Obesidade Grau I";
		return msg;
	}else if(tb1[linha].imc <= 39.9) {
		string msg = "Obesidade Grau II";
		return msg;
	}else {
		string msg = "Obesidade Grau III OU Mórbida";
		return msg;
	}
}
//método para realizar registros
void novoRegistro() {
	linha++;
	tb1[linha].nome = lerNome();
	tb1[linha].peso = lerPeso();
	tb1[linha].altura = lerAltura();
	tb1[linha].imc = calcIMC();
	tb1[linha].clasimc = clasIMC();
		
}
//método para fazer uma busca no struct pelo nome
int buscaSequencial(string nome) {
	for(int i=0; i <= linha; i++) {
		if(nome == tb1[i].nome){
			return i;
		}
	}
	return -1;
}
//método para exibir as colunas do struct
void exibir() {
	for(int pos=0; pos < tam; pos++) {
		cout << "NOME...:  " << tb1[pos].nome << " | PESO...: " << tb1[pos].peso << " | ALTURA...: " << tb1[pos].altura << " | IMC...: " << setprecision(3) << tb1[pos].imc << endl;
	}
}
//método para ordenação alfabetica, levando o peso, altura e o imc para a posição correspondente ao nome
void bolha() {
	string aux, auxC;
	double auxP, auxA, auxI;
	for(int i=0; i<tam; i++){
		for(int j=i; j<tam; j++){
			if(tb1[i].nome > tb1[j].nome) {
				aux = tb1[i].nome;
				tb1[i].nome = tb1[j].nome;
				tb1[j].nome = aux;
				
				auxP = tb1[i].peso;
				tb1[i].peso = tb1[j].peso;
				tb1[j].peso = auxP;
				
				auxA = tb1[i].altura;
				tb1[i].altura = tb1[j].altura;
				tb1[j].altura = auxA;
				
				auxI = tb1[i].imc;
				tb1[i].imc = tb1[j].imc;
				tb1[j].imc = auxI;
				
				auxC = tb1[i].clasimc;
				tb1[i].clasimc = tb1[j].clasimc;
				tb1[j].clasimc = auxC;	
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	int tecla=0, indice;
	string nom;
	//menu principal
    while (tecla != 5) { 
        system("cls");  
        // FEITO POR: MATEUS DA SILVA PEREIRA | FATEC ZONA SUL |  3º SEMESTRE - ESTRUTURA DE DADOS" 
        cout << "\n 1 - Registrar\n 2 - Buscar\n 3 - Exibir\n 4 - Exibir em Ordem\n 5 - Sair " << endl;  
        cin >> tecla;
		switch(tecla){
			case 1: 
				system("cls");
 				novoRegistro();
  			break;
  		
  			case 2: 
  				system("cls");
  				cout << "\nDigite o nome da  pessoa:";            
  				cin>> nom;             
  				indice = buscaSequencial(nom);
  				system("cls");
  				if (indice == -1 ) {
					cout << "\n Pessoa inexistente!\n"; 
					system("pause");
				}else {
					cout << "\n\n\nO nome '" <<tb1[indice].nome << "' foi encontrada na posição'"<< indice << endl;
					cout << "\n\n\nClassificação.....................: " << tb1[indice].clasimc << endl;                
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
	return 0;
}




