/************************************************\
	Você foi contratado para implementar uma solução para gerenciar e controlar a carga/descarga de caminhões cegonha.
	Ao carregar o caminhão, cada veiculo deve ser cadastrado na ordem de inserção. Os dados a serem armazenados são:
		*MODELO 
		*COR
		*CHASSI
		*ANO DE FABRICAÇÃO
	A fim de otimizar o trabalho, ao carregaro caminhão, as montadoras observam a ordem de descarga uma vez que o primeiro
veiculo a ser carregado será sempre o último a ser descarregado. Isso facilita o trabalho de entrega, pois um mesmo frete,
pode efetuar entregas em varias concessionarias.
	Neste sentido seu sistema deve contar com as seguintess funcionalidades no menu:
		*Inserir carro na cegonha
		*Pesquisar por carro na cegonha
		*Listar carros ainda carregados
		*Descarregar próximo carro
		*Imprimir quantidade de carros na cegonha

 \************************************************/
#include <iostream>
#include <stdlib.h>

using namespace std;
const int MAXTAM=6;
// Classe Fila com vetor
class TipoFila {
private:
	int Item [MAXTAM];
	string MODELO [MAXTAM];
	string COR [MAXTAM];
	string CHASSI [MAXTAM];
	string ANO_FABRICACAO [MAXTAM];
	string NOME [MAXTAM];
	int Frente, Tras, Quantos;
	
public:
	TipoFila (void);
	int Vazia (void);
	int Cheia (void);
	int Tamanho (void);
	void Tamanho_Mostrar (int &Elemento);
	void Enfileirar (int &Elemento, string &Elemento2,string &Elemento3,string &Elemento4,string &Elemento5,string &Elemento6); // no fim
	void Desenfileirar(int &Elemento); // do inicio
}; // fim classe TipoFila

//Setando valores nas variaveis
TipoFila :: TipoFila (void) 
{ Frente = Tras = Quantos = 0; }
//Função para saber se a pilha está vazia
int TipoFila :: Vazia (void){ 
return (Quantos == 0); 
}
//Função para saber se a pilha está cheia
int TipoFila :: Cheia (void){ 
return (Quantos == MAXTAM); 
}
//Função para saber o tamanho da pilha
int TipoFila :: Tamanho(void){ 
return (Quantos); 
}
void TipoFila :: Tamanho_Mostrar(int &Elemento){
cout<< "Quantos: " << Quantos <<"\n\n";
return;	
}

//Procedimento para colocar carro na pilha
void TipoFila :: Enfileirar(int &Elemento, string &Elemento2,string &Elemento3,string &Elemento4,string &Elemento5,string &Elemento6){
	
	cout << "*****Antes*****\n";
	cout<< "Item numero " << Tras << " enfileirando!\n";
	cout << "Valor a ser inserido: " << Elemento<<"\n";
	cout<< "Quantos: " << Quantos <<"\n";
	cout << "Frente: " << Frente <<"\n";
	cout << "Tras: "<< Tras <<"\n\n";
	
	
	if (Cheia ())
		cout << "Fila cheia. \n";
	else {
		Item [Tras] = Elemento;
		NOME [Tras] = Elemento2;
		MODELO [Tras] = Elemento3;
		COR [Tras] = Elemento4;
		CHASSI [Tras] = Elemento5;
		ANO_FABRICACAO [Tras] = Elemento6;	
		
		cout << "Elemento: " <<Item [Tras] 
			 << "\nNome: " << NOME [Tras];
		cout << "\nNa fila!!! \n\n";
		Quantos++;
		Tras = (Tras + 1) % MAXTAM; // avanÃar ou reiniciar
	}
	cout << "*****Depois*****\n";
	cout<< "Quantos: " << Quantos <<"\n";
	cout << "Frente: " << Frente <<"\n";
	cout << "Tras: "<< Tras <<"\n\n";
	return;
}
//Procedimento para retirar carro a pilha
void TipoFila :: Desenfileirar(int &Elemento){
	cout << "*****Antes*****\n";
	cout<< Item [Frente] << " desenfileirando!\n";
	cout<< "Quantos: " << Quantos <<"\n";
	cout << "Frente: " << Frente <<"\n";
	cout << "Tras: "<< Tras <<"\n\n";
	
	
	if (Vazia())
		cout<< "Fila vazia. \n";
	else {
		Elemento = Item [Frente];
		Quantos--;
		Frente = (Frente + 1) % MAXTAM; //avanÃa ou reinicia
	}
	cout << "*****Depois*****\n";
	cout<< Item [Frente] << " Eh o proximo!\n";
	cout<< "Quantos: " << Quantos <<"\n";
	cout << "Frente: " << Frente <<"\n";
	cout << "Tras: "<< Tras <<"\n\n";
}


int main(){
    int n, i, x, op;
    string car,model,color,chassien,year;
    TipoFila s;
    
	do {
		//system("cls");
		cout << "***Fila estatica***"
		<<"\n\nDigite Opcao: "
		<<"\n\n1 - Inserir carro na cegonha"
		<<"\n2 - Pesquisar por carro na cegonha"
		<<"\n3 - Listar carros ainda carregados"
		<<"\n4 - Descarregar proximo carro"
		<<"\n5 - Imprimir quantidade de carros na cegonha"
		<<"\n\nDigite a opcao escolhida: ";
		cin>>op;
		if (op==1) {
			cout << "Digite itema ser inserido na fila: " ;
			cin>>x;
			cout << "Digite o nome do carro: " ;
			cin>>car;
			cout << "Digite o modelo do carro: " ;
			cin>>model;
			cout << "Digite a cor do carro: " ;
			cin>>color;
			cout << "Digite o chassi do carro: " ;
			cin>>chassien;
			cout << "Digite o ano de fabricacao do carro: " ;
			cin>>year;
			cout << "======================" << "\n";
			s.Enfileirar(x,car,model,color,chassien,year);
		}
		if (op==2) {
			s.Desenfileirar(i);
		}
		if (op==3) {
			s.Desenfileirar(i);
		}
		if (op==4) {
			s.Desenfileirar(i);
		}
		if (op==5) {
			s.Tamanho_Mostrar(i);
		}
	} while (op == 1 || op ==2 || op ==3 || op ==4 || op ==5);
	
    system("pause");
    return 0;
}
