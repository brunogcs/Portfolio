//Fazer um programa para receber uma lista de números inteiros e retirar todos os números repetidos. 
//Para comprovar o sucesso da operação, seu algoritmo deve mostrar a “lista entrada” e a “lista resultado”.

#include<iostream>
using namespace std;

void fill_list(){
	
	int i,o,ord,dupl=0,vEntrada[5],vSaida[5];
	//Introdução de dados no vetor
	for(i=0;i<5;i++){
		cout << "Digite o " << i+1 << " valor: ";
		cin >> vEntrada[i];
	}
	
	//Ordenando o vetor
	for (i=0; i<5; i++){
        for (int o=0;o<5; o++){
            if (vEntrada[i] < vEntrada[o]){
                ord = vEntrada[i];
                vEntrada[i] = vEntrada[o];
                vEntrada[o] = ord;
            }
        }
    }
    
    //Mostrando lista de entrada
	cout << "Lista de entrada: " << endl;
	for(i=0;i<5;i++){
		cout << vEntrada[i]<<endl;
	}
	
	//Verificando duplicatas no vetor
	for( i=0;i<5;i++){
        for( o=0;o<dupl;o++){
            if( vEntrada[i] == vSaida[o] )
                break;
        }
        if( o == dupl ){
            vSaida[dupl] = vEntrada[i];
            dupl++;
        }
    }
	//Mostrando lista de resultado
	cout << "Lista de saida: " << endl;
	for(i=0;i<o;i++){
		cout << vSaida[i]<<endl;
	}
}

int main(){
	
	fill_list();
	
	system("pause");
	return 0;
}
