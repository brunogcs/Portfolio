//Criar um programa que ofereça as opções de media, soma, subtração, divisão e multiplicação de números digitados pelo usuário.
//Todas as operações devem ser modularizadas. Os números lidos do teclados também devem ser apresentados.

#include<iostream>
using namespace std;

int soma(int x, int y){
	return x+y;
}
int subtracao(int x, int y){
	return x-y;
}
int multiplicacao(int x, int y){
	return x*y;
}
int divisao(int x, int y){
	return x/y;
}

int main(){
	int x,y,result,opcao;
	cout << "1-Soma"<<endl << "2-Subtracao"<<endl << "3-Multiplicacao"<<endl << "4-Divisao"<<endl;
	cout << "Digite a opcao desejada: ";
	cin >> opcao;
	system("cls");
	switch (opcao){
		case 1:
		cout << "Digite o primeiro valor: ";
		cin >> x;
		cout << "Digite o segundo valor: ";
		cin >> y;
		result = soma(x,y);
		cout << "Soma: " << result << endl;
		break;
		case 2:
		cout << "Digite o primeiro valor: ";
		cin >> x;
		cout << "Digite o segundo valor: ";
		cin >> y;
		result = subtracao(x,y);
		cout << "Subtracao: " << result << endl;
		break;
		case 3:
		cout << "Digite o primeiro valor: ";
		cin >> x;
		cout << "Digite o segundo valor: ";
		cin >> y;
		result = multiplicacao(x,y);
		cout << "Multiplicacao: " << result << endl;
		break;
		case 4:
		cout << "Digite o primeiro valor: ";
		cin >> x;
		cout << "Digite o segundo valor: ";
		cin >> y;
		result = divisao(x,y);
		cout << "Divisao: " << result << endl;
		break;
	}
	system("pause");
	return 0;
}

