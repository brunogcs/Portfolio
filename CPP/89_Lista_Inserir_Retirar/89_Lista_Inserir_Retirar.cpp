/************************************************\
Lista: Inserir e Retirar
\************************************************/
#include <iostream>
#include <stdlib.h>
using namespace std;
const int MAXTAM=10;

class TipoLista // Classe Lista com vetor
{
   private:
      string Item [MAXTAM];
      int Primeiro, Ultimo, Quantos;
      
   public:
      TipoLista (void);
      int Vazia (void);
      int Tamanho (void);
      void Inserir (string Elemento); // no fim
      void Inserir (string Elemento, int Posicao);
      void Retirar (string Elemento); // do inicio
      void Retirar (int Posicao);
      void Listar ();
}; // fim classe TipoLista

TipoLista :: TipoLista(void) //construtorpadr?o
{ Primeiro = Ultimo = Quantos = 0; }
//**********************************************
int TipoLista :: Vazia(void)
{ return(Primeiro == Ultimo); }
//**********************************************
int TipoLista :: Tamanho(void)
{ return(Quantos); }
//**********************************************
void TipoLista :: Listar()
{
	for(int i=0;i<MAXTAM;i++){
		cout << "Posicao: "<< i <<": "<<Item[i] << "\n";
      	Quantos++;
	}
}
//**********************************************
void TipoLista :: Inserir(string Elemento)
{
   if (Ultimo >= MAXTAM)
      cout << "Lista cheia. \n";
   else {
      Item[Ultimo++] = Elemento;
      Quantos++;
   }
   return;
}
//**********************************************
void TipoLista :: Inserir (string Elemento, int Posicao)
{
   if (Ultimo >= MAXTAM)
      cout << "Lista cheia. \n";
   else {
      //A partir da posi??o informanda, jogo todos os elementos um posi??o para
      //tr?s e depois coloco o elemento informado na posi??o solicitada.
      for(int i = Ultimo; i >= Posicao; i--){
          Item[i+1] = Item[i];
      }
   }        
   Item[Posicao] = Elemento;
   Ultimo++;
   Quantos++;
   return;
}
//***********************************************
void TipoLista :: Retirar(string Elemento)
{
   if (Vazia( ))
      cout << "Lista vazia. \n";
   else {
      Elemento = Item[Primeiro];
      Ultimo--;
      Quantos--;
      for (int i = Primeiro; i < Ultimo; i++)
           Item[i] = Item[i+1];
   }
}
//**********************************************
void TipoLista :: Retirar (int Posicao)
{
   //A partir da posi??o informanda, jogo todos os elementos um posi??o para
   //frente.    
   

   	if(Item[Posicao]==""){
   		cout << "Nao foi possivel remover. Esta posicao esta vazia\n\n";
    }
    else {
      Ultimo--;
      Quantos--;
      for (int i = Posicao; i < Ultimo; i++){
           Item[i] = Item[i+1];
      }
   }
}

int main(){
    int n, i, caso=0, limpar=0, rposicao=0, iposicao=0;
    string nome,nomeretirar,nomeindice;
    TipoLista lista;
    
    do{
                   cout << "***Sistema de Gerenciamento de Clientes***\n\n";
                   cout << "1 - Inserir Cliente\n";
                   cout << "2 - Remover Cliente\n";
                   cout << "3 - Inserir Cliente na posicao indicada\n";
                   cout << "4 - Remover Cliente na posicao indicada\n";
                   cout << "5 - Listar Clientes\n";
                   cout << "0 - Para sair\n\n";
    
                   cout << "Digite a opcao desejada: ";
                   cin >> caso;
                   cout << "\n\n";
    
                   if (caso==1){
                   cout << "Digite o nome que deseja inserir: ";
                   cin >> nome;
                   lista.Inserir(nome);
                   cout << "O cliente foi inserido com sucesso\n\n";
                   if (lista.Vazia()){
                                       cout<< "Lista: Vazia\n" << endl;
                                       }
                                       else{
                                       cout<< "Lista: Tem elementos\n" << endl;
                                       }            
                   }
                   if (caso==2){
                   lista.Retirar(nomeretirar);
                   cout << "O cliente " << nomeretirar << " foi removido com sucesso\n\n";
                                       if (lista.Vazia()){
                                       cout<< "Lista: Vazia\n" << endl;
                                       }
                                       else{
                                       cout<< "Lista: Tem elementos\n" << endl;
                                       }      
                   }
                   if (caso==3){
                   cout << "Digite o nome que deseja inserir: "; 
                   cin >> nomeindice;
                   cout << "Digite o indice onde deseja inserir: ";
                   cin >> iposicao;
                   lista.Inserir(nomeindice,iposicao);
                   cout << "O cliente " << nomeretirar << " foi inserido com sucesso\n\n";
                                       if (lista.Vazia()){
                                       cout<< "Lista: Vazia\n" << endl;
                                       }
                                       else{
                                       cout<< "Lista: Tem elementos\n" << endl;
                                       }
                   }
                   if (caso==4){
                   cout << "Digite o numero correspondente ao indice: "; 
                   cin>>rposicao;
                   lista.Retirar(rposicao);
                                       if (lista.Vazia()){
                                       cout<< "Lista: Vazia" << endl;
                                       }
                                       else{
                                       cout<< "Lista: Tem elementos" << endl;
                                       }     
                   }
                   if (caso==5){
                	lista.Listar(); 
                   }
                   if (caso==0){
                   cout << "Saindo...\n\n";  
                   break;    
                   }
                   cout << "Deseja limpar a tela? 1-SIM 2-NAO: ";
                   cin  >> limpar; 
                   if(limpar==1){
                             system("cls");
                   }
    }while(caso!=0);
        
    system("pause");
    return 0;
}

