#include<iostream>
using namespace std;
int main(){
	
	int cont, vet1[50], vet2[50], sumv1 = 0, sumv2=0, diff=0;
	
	for (cont=0;cont<50;cont++){
		
		vet1[cont]= 10;
		vet2[cont]= 50;
		sumv1 = sumv1+vet1[cont];
		sumv2 = sumv2+vet2[cont];
	}
	
	diff = sumv1 - sumv2;
	if (diff <0){
		diff = diff * -1;
	}
	
	cout << "Total do primeiro vetor: " << sumv1 << endl;
	cout << "Total do segundo vetor: " << sumv2 << endl;
	cout << "Diferenca geral entre os dois vetores: " << diff << endl;
	
	system("pause");
	return 0;
}
