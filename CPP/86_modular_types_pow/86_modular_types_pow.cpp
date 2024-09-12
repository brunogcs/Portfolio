//Fazer um algoritmo para calcular xª (potencia de “x” por “a”), de duas maneiras: 
//uma utilizando uma função pré-definida (nativa do compilador) 
//e outra com seus conhecimentos de algoritmos adquiridos até agora.

#include<iostream>
#include<math.h>
using namespace std;

void powNative(){
	int num,pot; 
	cout << "Digite o numero para saber a potencia: ";
	cin >> num;
	cout << "Digite a potencia: ";
	cin >> pot;
	cout << pow(num,pot)<<endl;
	
}
void powMy(){
	int num,pot,i,result; 
	cout << "Digite o numero para saber a potencia: ";
	cin >> num;
	cout << "Digite a potencia: ";
	cin >> pot;
	for(i=0;i<pot;i++){
		result*=num;
	}
	cout << result << endl;
}

int main(){
	int opcao;
	cout << "Selecione a opcao desejada:"<<endl;
	cout << "1 - Pow nativo" << endl << "2 - Pow Gambiarra"<<endl;
	cin >> opcao;
	switch (opcao){
		case 1:
		powNative();
		break;
		case 2:
		powMy();
		break;
	}
	system("pause");
	return 0;
}

