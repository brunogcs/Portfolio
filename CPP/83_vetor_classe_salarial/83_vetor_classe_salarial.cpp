#include<iostream>
using namespace std;
int main(){
	
	int  contwrite=0,contReadFunc=0,contWriteSal=0,contTotClasse=0,contReadClasse=0,contMaxClasse=0
		,total1=0,total2=0,total3=0,total4=0,total5=0,total6=0,total7=0,maiorclasse=0
		,classefunc[4],guardaclasse[4],maior[8]
		,classefixa[8]={0,800,1000,1100,1500,2500,4000,6000};
	
	string nomefunc;
	
	//Digita os dados para gravar nos vetores
	for (contwrite=1;contwrite<=3;contwrite++)
	{
		
		cout << "Digite o nome do funcionario: ";
		cin >> nomefunc[contwrite];
		cout << endl;
		cout << "Entre 1 e 7 digite a classe a qual ele pertence: ";
		cin >> classefunc[contwrite];
		cout << endl;
		//Guarda salario
		for(contWriteSal=1;contWriteSal<=3;contWriteSal++)
		{
			if(classefunc[contwrite]==contWriteSal)
			{
				guardaclasse[contwrite] = classefixa[contWriteSal];	
			}
		}
	//Armazena o total digitado de cada classe
	}
	for (contTotClasse=1;contTotClasse<=3;contTotClasse++)
	{
		if(classefunc[contTotClasse]==1){total1++;} maior[1] = total1;
		if(classefunc[contTotClasse]==2){total2++;} maior[2] = total2;
		if(classefunc[contTotClasse]==3){total3++;} maior[3] = total3;
		if(classefunc[contTotClasse]==4){total4++;} maior[4] = total4;
		if(classefunc[contTotClasse]==5){total5++;} maior[5] = total5;
		if(classefunc[contTotClasse]==6){total6++;} maior[6] = total6;
		if(classefunc[contTotClasse]==7){total7++;} maior[7] = total7;
		//Guarda a classe com maior numero cadastrado
		for(contMaxClasse=1;contMaxClasse<8;contMaxClasse++)
		{
			if(maiorclasse<maior[contMaxClasse])
			{
				maiorclasse = contMaxClasse;
				cout << maiorclasse << " e menor que " << maior[contMaxClasse] << endl;
			}
			else
			{
			cout << maiorclasse << " e maior que " << maior[contMaxClasse] << endl;
			}
		}
	}
	//Printa todos os cadastros	
	cout << "*******************************************************************************************\n\n";
	cout << "Nosso banco de funcionarios: \n\n";
	for (contReadFunc=1;contReadFunc<=3;contReadFunc++)
	{
		cout << "O sujeito de chama " << nomefunc[contReadFunc] << " e recebe como salario R$" << guardaclasse[contReadFunc] << endl;
		cout << endl;	
	}
	//Printa o numero de funcionarios cadastrados em cada parte	
	cout << "*******************************************************************************************\n\n";
	cout << "O total das nossas classes e: \n\n";
	for (contReadClasse=1;contReadClasse<8;contReadClasse++)
	{
		cout << "\nTotal de funcionarios da classe " << contReadClasse << ": " << maior[contReadClasse] << "\n";
	}	
	//Printa qual a classe com maior cadastro e quantas pessoas tem cadastradas nela
	cout << "*******************************************************************************************\n\n";
	cout << "A classe com maior numero de funcionarios e: " << maiorclasse << ". Ela tem " << maior[maiorclasse] << " funcionarios.\n\n";
	
	
system("pause");
return 0;	
}
