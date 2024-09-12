#include<iostream>
using namespace std;
int main(){
	
	int cont, vet1[100], maior = 0, menor=0, sum=0, media=0;
	
	for (cont=0;cont<=100;cont++){
		
		vet1[cont]= cont;
		sum = sum + vet1[cont];
		if(maior<vet1[cont]){
			maior = vet1[cont];
		}
		else if (menor>vet1[cont]){
			menor = vet1[cont];
		}
	}
	media = sum/(cont-1);
	cout << "Esse e o maior elemento registrado no vetor: " << maior << endl;
	cout << "Esse e o menor elemento registrado no vetor: " << menor << endl;
	cout << "A media do vetor: " << media << endl;
	
	system("pause");
	return 0;
}
