#include<iostream>
using namespace std;
int main(){
	
	int  cont;
	string data[5],dia[5],mes[5],ano[5];
	
	for (cont=0;cont<=1;cont++){
		
		cout << "Digite a primeira data: EXEMPLO: 01-01-01: ";
		cin >> data[cont];
		dia[cont] = data[cont].substr(0,2);
		mes[cont] = data[cont].substr(3,2);
		ano[cont] = data[cont].substr(6,2);
		
		if (mes[cont]=="01"){
			mes[cont] = "Janeiro";
		}
		if (mes[cont]=="02"){
			mes[cont] = "Fevereiro";
		}
		if (mes[cont]=="03"){
			mes[cont] = "Marco";
		}
		if (mes[cont]=="04"){
			mes[cont] = "Abril";
		}
		if (mes[cont]=="05"){
			mes[cont] = "Maio";
		}
		if (mes[cont]=="06"){
			mes[cont] = "Junho";
		}
		if (mes[cont]=="07"){
			mes[cont] = "Julho";
		}
		if (mes[cont]=="08"){
			mes[cont] = "Agosto";
		}
		if (mes[cont]=="09"){
			mes[cont] = "Setembro";
		}
		if (mes[cont]=="10"){
			mes[cont] = "Outubro";
		}
		if (mes[cont]=="11"){
			mes[cont] = "Novembro";
		}
		if (mes[cont]=="12"){
			mes[cont] = "Dezembro";
		}
		
	}
	for (cont=0;cont<=1;cont++){
		
	 	cout << dia[cont] << " de " << mes[cont] << " de 20" << ano[cont] << endl;
	 	
	}

	system("pause");
	return 0;
}
