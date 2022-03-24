/*                                                      Avalia��o / Tarefa 
b) - Fa�a  um  algoritmo  com  struct  e  menu  completo  para  ler  uma  lista  de  NOMES, PESOS, ALTURAS e armazenar o c�lculo do �ndice de massa corp�rea, IMC.
Fa�a um menu com a op��es: 1 Ler, processar, 2 exibir tabela, 3 pesquisar por nome, 4 Classificar  por  nome,  5  sair.
Na  op��o  pesquisar  por  nome,  fa�a  uma  pesquisa sequencial para encontrar e exibir o nome da pessoa, seu peso, sua altura e seu IMC  
assim  como  seu  status  de  classifica��o  de  peso.
Use  as  mensagens  de classifica��o obtidas no site: http://www.calcularpesoideal.com.br/
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
//m�todo para ler o nome
string lerNome() {
	string n;
	cout << "Digite o seu nome : ";
	cin  >> n;
	return n;
}
//m�todo para ler o peso
double lerPeso() {
	double p;
	cout << "Digite o seu peso : ";
	cin  >> p;
	return p;
}
//m�todo para ler a altura
double lerAltura() {
	double a;
	cout << "Digite a sua altura : ";
	cin  >> a;
	return a;
}
//m�todo para calcular o imc
double calcIMC() {
	double res;
	res = tb1[linha].peso/pow(tb1[linha].altura, 2);
	return res;
}
//m�todo da classifica��o do imc
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
		string msg = "Obesidade Grau III OU M�rbida";
		return msg;
	}
}
//m�todo para realizar registros
void novoRegistro() {
	linha++;
	tb1[linha].nome = lerNome();
	tb1[linha].peso = lerPeso();
	tb1[linha].altura = lerAltura();
	tb1[linha].imc = calcIMC();
	tb1[linha].clasimc = clasIMC();
		
}
//m�todo para fazer uma busca no struct pelo nome
int buscaSequencial(string nome) {
	for(int i=0; i <= linha; i++) {
		if(nome == tb1[i].nome){
			return i;
		}
	}
	return -1;
}
//m�todo para exibir as colunas do struct
void exibir() {
	for(int pos=0; pos < tam; pos++) {
		cout << "NOME...:  " << tb1[pos].nome << " | PESO...: " << tb1[pos].peso << " | ALTURA...: " << tb1[pos].altura << " | IMC...: " << setprecision(3) << tb1[pos].imc << endl;
	}
}
//m�todo para ordena��o alfabetica, levando o peso, altura e o imc para a posi��o correspondente ao nome
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
        // FEITO POR: MATEUS DA SILVA PEREIRA | FATEC ZONA SUL |  3� SEMESTRE - ESTRUTURA DE DADOS" 
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
					cout << "\n\n\nO nome '" <<tb1[indice].nome << "' foi encontrada na posi��o'"<< indice << endl;
					cout << "\n\n\nClassifica��o.....................: " << tb1[indice].clasimc << endl;                
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




