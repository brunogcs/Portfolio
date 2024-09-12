//Fazer um algoritmo para converter uma temperatura de ºC (graus Celsius) para ºF (graus Farenheit),
// e em seguida para K (Kelvin). Mostrar os resultados na tela.

#include<iostream>
using namespace std;

void tempConverter(){
	float cel,fah,kel;
	cout << "Digite a temperatura em celsius: ";
	cin >> cel;
	fah = cel*1.8+32;
	kel = cel+ 273.15;
	cout << "Essa e a temperatura em Farenheit: " << fah << endl;
	cout << "Essa e a temperatura em Kelvin: " << kel << endl;
}

int main(){
	tempConverter();
	system("pause");
	return 0;
}

