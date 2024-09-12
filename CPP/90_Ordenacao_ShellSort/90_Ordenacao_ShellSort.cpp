//================================================================
// Implementação do algoritmo de ordenação Shell
//================================================================
 
// Libs
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
 
// Define uma constante para vetor
const int MAX = 8;
 
// Função de ordenação Shell
void shell_sort(int *a, int size)
{
 int i , j , value;
 int h = 1;
 int iaux = 1;
 cout << "Valor que inicializa a varivel H: "<< h <<"\n";
  
 do {
  h = h*3+1;
 } while(h < size);
  
 do {
  h = (h-1)/3;
  cout << "Valor atribuido a H no " << iaux << " loop: " << h <<"\n";
  iaux ++;
  for(i = h; i < size; i++) {
   value = a[i];
   j = i - h;
    
   while (j >= 0 && value < a[j]) {
    a[j + h] = a[j];
    j -= h;
   }
   a[j + h] = value;
  }
 }while(h > 1);
}
 

// Main Function
int main()
{
 int i, vet[MAX];
 
 // Lê MAX
 for(i = 0; i < MAX; i++)
 {
  cout << ("Digite um valor: ");
  cin >> vet[i];
 }
 
 system("cls");
 
 // Ordena os valores utilizando o modulo
 shell_sort(vet, MAX);
 
 // Imprime os valores ordenados
 cout << ("\n\nValores ordenados\n\n");
 for(i = 0; i < MAX; i++)
 {
  cout << vet[i];
  cout << "\n";
 }
 system("pause");
 return 0;
}
