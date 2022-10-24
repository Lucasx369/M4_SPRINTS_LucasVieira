// 4 - Faça uma função que recebe um vetor com 4 posições que contém o valor da distância de um pequeno robô até cada um dos seus 4 lados. A função deve retornar duas informações: A primeira é a direção de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a segunda é esta maior distância.

#include <iostream>
#include <string>
using namespace std;

int maiorDist(int *array){ //Função para descobrir o valor de maior distância 
  int maior = -1; //Vatiável para alocar o maior valor
  for(int i=0; i<4; i++){
    if (array[i] > maior){ //Confere se o valor do vetor é maior do que o maior valor
      maior = array[i]; 
    }
  }
  return maior;
}

char maiorDir(int *array){ //Função para descobrir a direção com maior distância
  const char*  direcao[] = {"Direita", "Esquerda", "Frente", "Tras"}; //Vetor com os tipos de direções
  int maior = -1;
  int dir = -1; //Variável para alocar o index do maior valor
  for(int i=0; i<4; i++){
    if (array[i] > maior){ //Confere se o valor do vetor é maior do que o maior valor
      maior = array[i];
      dir = i;
    }
  }
  return* direcao[dir]; 
}

int main(){
  int vet[4]={8,15,12,4}; //Vetor com 4 posições 
	int maiorDistancia = maiorDist(vet);
  char maiorDirecao = maiorDir(vet);
  cout << "A maior distância é: " << maiorDistancia << endl;
  cout << "A maior direção é: " << maiorDirecao << endl;
  return 0;
}
